#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 2e5 + 5;

int n;
vi adj1[N];

vi adj[N];
int par[N];
int sz[N], cntleaf[N];

void dfs1(int u, int p){
    par[u] = p;
    Fora(v, adj1[u]){
        if (v == p){
            continue;
        }
        dfs1(v, u);
    }
}

void dfs2(int u){
    sz[u] = isz(adj[u]);
    Fora(&v, adj[u]){
        dfs2(v);
        cntleaf[u] += (!sz[v] ? 1 : 0);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n;
    ForE(u, 1, n){
        adj1[u].clear();
        adj[u].clear();
        par[u] = 0;
        cntleaf[u] = 0;
    }
    For(i, 1, n){
        int u, v; cin >> u >> v;
        adj1[u].emplace_back(v);
        adj1[v].emplace_back(u);
    }
    dfs1(1, 0);
    ForE(u, 1, n){
        Fora(v, adj1[u]){
            if (u == par[v]){
                adj[u].emplace_back(v);
            }
        }
    }
    dfs2(1);
    int ans = 0;
    queue <int> qu;
    ForE(u, 2, n){
        if (sz[u] and cntleaf[u] == sz[u]){
            qu.push(u);
            ans += cntleaf[u] - 1;
        }
    }
    while (!qu.empty()){
        int u = qu.front(); qu.pop();
        int p = par[u];
        sz[p]--;
        if (p != 1 and sz[p] and cntleaf[p] == sz[p]){
            qu.push(p);
            ans += cntleaf[p] - 1;
        }
        if (par[p]){
            cntleaf[par[p]] += (!sz[p] ? 1 : 0);
            if (par[p] != 1 and sz[par[p]] and cntleaf[par[p]] == sz[par[p]]){
                qu.push(par[p]);
                ans += cntleaf[par[p]] - 1;
            }
        }
    }
    ans += max(cntleaf[1], 1);
    cout << ans << endl;
}
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/