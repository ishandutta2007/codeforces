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
vi a[N];

vi adj[N];

bool vis[N];
vi vtopo;
int postopo[N];

void dfs_topo(int u){
    vis[u] = 1;
    Fora(v, adj[u]){
        if (!vis[v]){
            dfs_topo(v);
        }
    }
    vtopo.emplace_back(u);
}

void find_topo(){
    ForE(u, 1, n){
        vis[u] = 0;
    }
    vtopo.clear();
    ForE(i, 1, n){
        if (!vis[i]){
            dfs_topo(i);
        }
    }
    reverse(bend(vtopo));
    For(i, 0, n){
        postopo[vtopo[i]] = i;
    }
}

int cnt[N], dp[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n;
    ForE(i, 1, n){
        a[i].clear();
        adj[i].clear();
        cnt[i] = 0;
        dp[i] = 1;
    }
    ForE(i, 1, n){
        int k; cin >> k;
        ForE(j, 1, k){
            int x; cin >> x; a[i].emplace_back(x);
            adj[x].emplace_back(i);
        }
    }
    find_topo();
    bool ck = 1;
    ForE(u, 1, n){
        Fora(v, adj[u]){
            if (postopo[v] < postopo[u]){
                ck = 0;
            }
        }
    }
    if (!ck){
        cout << -1 << endl;
        continue;
    }
    queue <int> qu;
    ForE(u, 1, n){
        if (isz(a[u]) == cnt[u]){
            qu.emplace(u);
        }
    }
    while (!qu.empty()){
        int u = qu.front(); qu.pop();
        Fora(v, adj[u]){
            if (v > u){
                dp[v] = max(dp[v], dp[u]);
            }
            else{
                dp[v] = max(dp[v], dp[u] + 1);
            }
            cnt[v]++;
            if (isz(a[v]) == cnt[v]){
                qu.emplace(v);
            }
        }
    }
    int ans = 0;
    ForE(u, 1, n){
        ans = max(ans, dp[u]);
    }
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