#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>

using namespace std;

const int MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;i++)
#define rep2(i, m, n) for(int i=m;i<n;i++)
#define rrep(i, n, m) for(int i=n;i>=m;i--)
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

vector<int> ans;

void dfs(const vector<vector<pair<ll, ll>>> &g, int start, int color) {
    ans[start] = color;
    for (auto e : g[start]) {
        if (ans[e.first] == -1) {
            if (e.second % 2 == 0) {
                dfs(g, e.first, color);
            } else {
                dfs(g, e.first, 1 - color);
            }
        }
    }
}


int main() {
    int N;
    cin >> N;
    vector<vector<pair<ll, ll>>> graph(N);
    rep(i, N - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u - 1].push_back({v - 1, w});
        graph[v - 1].push_back({u - 1, w});
    }

    ans.assign(N, -1);
    dfs(graph, 0, 1);

    rep(i, N){
        cout << ans[i] << endl;
    }

}
