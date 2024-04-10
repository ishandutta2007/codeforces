#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 3e5+5;
int n, m, k;
vector<int> adj[N], b[N];
vector<vector<int>> ans;
int v[N], d[N], deg[N], p[N];

void dfs(int i, int r) {
    v[i] = 1;
    d[i] = d[r]+1;
    p[i] = i == r ? -1 : r;
    deg[r]++;

    if (d[i]*k >= n) {
        cout << "PATH\n" << d[i] << "\n";
        for (; i != -1; i = p[i])
            cout << i+1 << " \n"[p[i] == -1];
        exit(0);
    }

    for (int j : adj[i]) {
        if (j == r) continue;
        if (v[j]) b[i].pb(j);
        else dfs(j, i);
    }

    if (deg[i] == 0) {
        int x = b[i][0], y = b[i][1];
        if (d[x] < d[y]) swap(x, y);
        vector<int> path;
        if ((d[i]-d[x])%3 != 2) {
            for (; i != x; i = p[i])
                path.pb(i);
            path.pb(x);
        } else if ((d[i]-d[y])%3 != 2) {
            for (; i != y; i = p[i])
                path.pb(i);
            path.pb(y);
        } else {
            path.pb(i);
            for (i = x; i != y; i = p[i])
                path.pb(i);
            path.pb(y);
        }
        ans.pb(path);
    }

    if (ans.size() == k) {
        cout << "CYCLES\n";
        for (auto& path : ans) {
            cout << path.size() << "\n";
            for (int j = 0; j < path.size(); j++)
                cout << path[j]+1 << " \n"[j+1 == path.size()];
        }
        exit(0);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    while (m--) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), adj[y].pb(x);
    }
    dfs(0, 0);
    cout << "-1\n";
}