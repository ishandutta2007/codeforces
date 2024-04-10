#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 1e5 + 5;

int n;
int a[N], b[N];

vi adj[N];
bool vis[N];

void dfs(int u, int &cnt){
    cnt++;
    vis[u] = 1;
    Fora(v, adj[u]){
        if (!vis[v]){
            dfs(v, cnt);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    ForE(i, 1, n){
        cin >> b[i];
    }

    ForE(i, 1, n){
        adj[i].clear();
        vis[i] = 0;
    }
    ForE(i, 1, n){
        adj[a[i]].emplace_back(b[i]);
        adj[b[i]].emplace_back(a[i]);
    }

    int cntodd = 0;
    ForE(i, 1, n){
        if (!vis[i]){
            int cnt = 0;
            dfs(i, cnt);
            if (cnt & 1){
                cntodd++;
            }
        }
    }
    int len = (n - cntodd) / 2;
    ll ans = 0;
    ForE(i, 1, n){
        if (i <= len){
            ans -= 2 * i;
        }
        else if (i >= n - len + 1){
            ans += 2 * i;
        }
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