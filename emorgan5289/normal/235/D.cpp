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
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

using ld = long double;

const int N = 3005;
vector<int> adj[N], cyc, grp[N];
int vis[N], oncyc[N];
int root[N], rootdist[N];

ld ans = 0;

bool findcyc(int i, int j) {
    vis[i] = 1;
    for (int k : adj[i]) {
        if (k == j) continue;
        if (vis[k] || findcyc(k, i)) {
            cyc.pb(k), oncyc[k] = 1;
            return cyc[0] != i;
        }
    }
    return 0;
}

void dfs1(int i, int j) {
    root[i] = root[j];
    rootdist[i] = rootdist[j]+1;
    for (int k : adj[i])
        if (k != j)
            dfs1(k, i);
}

void dfs2(int i, int j, int x) {
    debug(i, x);
    ans += ld(1)/x;
    for (int k : adj[i])
        if (k != j && root[k] == root[i])
            dfs2(k, i, x+1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        adj[x].pb(y), adj[y].pb(x);
    }
    findcyc(0, 0);
    debug(cyc);

    for (int i : cyc) {
        root[i] = i;
        for (int j : adj[i])
            if (!oncyc[j])
                dfs1(j, i);
    }
    for (int i = 0; i < n; i++)
        grp[root[i]].pb(i);

    debug(vector(root, root+n));
    debug(vector(rootdist, rootdist+n));

    // contribution of stuff in separate trees to the answer
    for (int i = 0; i < n; i++)
        dfs2(i, i, 1);

    for (int i = 0; i < cyc.size(); i++)
        for (int j = i+1; j < cyc.size(); j++) {
            int x = cyc[i], y = cyc[j];
            int d1 = j-i-1, d2 = cyc.size()-2-d1;
            for (int p : grp[x])
                for (int q : grp[y]) {
                    int r = rootdist[q]+rootdist[p]+2;
                    debug(p, q, d1, d2, r);
                    ans += 2 * (ld(1)/(r+d1) + ld(1)/(r+d2) - ld(1)/(r+d1+d2));
                    debug(p, q, ld(1)/(r+d1) + ld(1)/(r+d2) - ld(1)/(r+d1+d2));
                }
        }

    cout << setprecision(16) << fixed << ans << "\n";
}