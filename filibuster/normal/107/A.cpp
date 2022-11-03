#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

pii g[N];
pii r[N];

pii dfs(int v) {
    pii res = {v, INF};
    if(g[v].f != -1) {
        pii r = dfs(g[v].f);
        res.s = min(g[v].s, r.s);
        res.f = r.f;
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        g[i] = {-1, -1};
        r[i] = {-1, -1};
    }

    for(int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;

        v--;
        u--;

        g[v] = {u, w};
        r[u] = {v, w};
    }

    vector<vector<int>> ans;
    for(int i = 0; i < n; i++) {
        if(g[i].f != -1 && r[i].f == -1) {
            pii res = dfs(i);
            ans.push_back(vector<int>{i, res.f, res.s});
        }
    }

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i][0] + 1 << ' ' << ans[i][1]  + 1 << ' ' << ans[i][2] << endl;
    }
}