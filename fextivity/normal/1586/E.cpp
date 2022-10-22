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

const int N = 3e5 + 5;

int n, m, q;
pii aquery[N];

vi adj2[N];
bool vis[N];

vi adj[N];
int par[N], h[N], sz[N];
int ctrtour, tour[N], tin[N], tout[N], nxt[N];

void dfs(int u){
    vis[u] = 1;
    Fora(v, adj2[u]){
        if (!vis[v]){
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
            dfs(v);
        }
    }
}

void dfs_par(int u){
    Fora(v, adj[u]){
        if (v == par[u]){
            continue;
        }
        par[v] = u;
        h[v] = h[u] + 1;
        dfs_par(v);
    }
    For(i, 0, isz(adj[u])){
        if (adj[u][i] == par[u]){
            adj[u].erase(adj[u].begin() + i);
            break;
        }
    }
}

void dfs_sz(int u){
    sz[u] = 1;
    Fora(&v, adj[u]){
        if (v == par[u]){
            continue;
        }
        dfs_sz(v);
        sz[u] += sz[v];
        if (sz[v] > sz[adj[u][0]]){
            swap(v, adj[u][0]);
        }
    }
}

void dfs_tour(int u){
    tour[++ctrtour] = u;
    tin[u] = ctrtour;
    Fora(v, adj[u]){
        if (v == par[u]){
            continue;
        }
        nxt[v] = (v == adj[u][0] ? nxt[u] : v);
        dfs_tour(v);
    }
    tout[u] = ctrtour;
}

int cnt[N], deg[N];

int lca[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    ForE(i, 1, m){
        int u, v; cin >> u >> v;
        adj2[u].emplace_back(v);
        adj2[v].emplace_back(u);
    }
    dfs(1);
    dfs_par(1);
    dfs_sz(1);
    nxt[1] = 1;
    dfs_tour(1);
    cin >> q;
    ForE(i, 1, q){
        cin >> aquery[i].fi >> aquery[i].se;
        int u = aquery[i].fi, v = aquery[i].se;
        while (nxt[u] != nxt[v]){
            if (h[nxt[u]] < h[nxt[v]]){
                swap(u, v);
            }
            cnt[tin[nxt[u]]]++; cnt[tin[u] + 1]--;
            u = par[nxt[u]];
        }
        if (h[u] > h[v]){
            swap(u, v);
        }
        cnt[tin[u] + 1]++; cnt[tin[v] + 1]--;
        lca[i] = u;
    }
    bool hasodd = 0;
    ForE(i, 1, n){
        cnt[i] += cnt[i - 1];
        if (cnt[i] % 2){
            hasodd = 1;
        }
    }
    if (!hasodd){
        cout << "YES" << endl;
        ForE(i, 1, q){
            vi vans1, vans2;
            int u = aquery[i].fi, v = aquery[i].se;
            while (u != lca[i]){
                vans1.emplace_back(u);
                u = par[u];
            }
            vans1.emplace_back(u);
            while (v != lca[i]){
                vans2.emplace_back(v);
                v = par[v];
            }
            reverse(bend(vans2));
            cout << isz(vans1) + isz(vans2) << endl;
            Fora(elem, vans1){
                cout << elem << ' ';
            }
            Fora(elem, vans2){
                cout << elem << ' ';
            } cout << endl;
        }
        return 0;
    }
    cout << "NO" << endl;
    ForE(i, 1, n){
        if (cnt[i] % 2){
            deg[par[tour[i]]]++; deg[tour[i]]++;
        }
    }
    int ans = 0;
    ForE(i, 1, n){
        ans += deg[i] % 2;
    }
    ans /= 2;
    cout << ans << endl;
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