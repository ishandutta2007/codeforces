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

const int N = 3e5 + 5, M = N * 5;

int n;
int a[N], b[N];

int mxid;
int leaf[N]; int isleaf[M];
vpii adj[M];
int dist[M], par[M];
deque <pii> dq;

void build(int id, int l, int r){
    mxid = max(mxid, id);
    if (l == r){
        leaf[l] = id;
        isleaf[id] = l;
        return;
    }
    adj[id].emplace_back(id * 2, 0);
    adj[id].emplace_back(id * 2 + 1, 0);
    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
}

void adda(int id, int l, int r, int u, int v, int x){
    if (v < l or r < u){
        return;
    }
    if (u <= l and r <= v){
        adj[x].emplace_back(id, 1);
        return;
    }
    int mid = (l + r) >> 1;
    adda(id * 2, l, mid, u, v, x);
    adda(id * 2 + 1, mid + 1, r, u, v, x);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    ForE(i, 1, n){
        cin >> b[i];
    }
    build(1, 1, n);
    ForE(i, 1, n){
        if (a[i] == i){
            adj[mxid + i].emplace_back(0, 1);
            a[i]--;
        }
        adda(1, 1, n, i - a[i], i, mxid + i);
        adj[leaf[i]].emplace_back(mxid + i + b[i], 0);
    }
    memset(dist, 0x3f, sizeof(dist));
    dist[mxid + n] = 0; par[mxid + n] = -1;
    dq.emplace_back(mxid + n, 0);
    while (!dq.empty()){
        int u, d; tie(u, d) = dq.front(); dq.pop_front();
        if (d != dist[u]){
            continue;
        }
        if (u == 0){
            vi vtrace = {u};
            while (u != mxid + n){
                if (isleaf[u]){
                    vtrace.emplace_back(isleaf[u]);
                }
                u = par[u];
            }
            reverse(bend(vtrace));
            cout << isz(vtrace) << endl;
            Fora(v, vtrace){
                cout << v << ' ';
            } cout << endl;
            return 0;
        }
        Fora(&edge, adj[u]){
            int v, w; tie(v, w) = edge;
            if (dist[v] > d + w){
                dist[v] = d + w; par[v] = u;
                if (w){
                    dq.emplace_back(v, d + w);
                }
                else{
                    dq.emplace_front(v, d);
                }
            }
        }
    }
    cout << -1 << endl;
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