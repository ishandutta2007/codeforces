#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const int INF = 1e9 + 7;
int pos[N];
int p[N], a[N];
int r[N];
int tree[N << 2];
void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = r[tl];
        return;
    }   
    int tm = (tl + tr) >> 1;
    build(v * 2 + 1, tl, tm); build(v * 2 + 2, tm + 1, tr);
    tree[v] = min(tree[v * 2 + 1] , tree[v * 2 + 2]);
}   
int get(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return INF;
    if (l <= tl && tr <= r) return tree[v];
    int tm = (tl + tr) >> 1;
    return min(get(v * 2 + 1, tl, tm, l, r), get(v * 2 + 2, tm + 1, tr, l, r));
}   
int n, m, q;
const int LG = 20;
int last[N];
int go[N][LG];
int flex(int u, int w) {
    for (int i = LG - 1; i >= 0; --i) {
        if ((w >> i) & 1) {
            if (go[u][i] == INF) return INF;
            else u = go[u][i];
        }   
    }   
    return u;
}   
void solve() {
    /*
    for (int i = 0; i < m; ++i) {
        cout << a[i] << ' ';
    }   
    cout << '\n';
    */
    for (int i = 0; i < N; ++i) {
        last[i] = -1;
    }   
    for (int i = m - 1; i >= 0; --i) {
        last[a[i]] = i;
        int w = (a[i] + 1) % n;
        if (last[w] != -1) {
            go[i][0] = last[w];
            for (int j = 1; j < LG; ++j) {
                go[i][j] = go[go[i][j - 1]][j - 1];
                if (go[i][j] == INF) {
                    for (int k = j + 1; k < LG; ++k) {
                        go[i][k] = INF;
                    }   
                    break;
                }   
            }   
        }   
        else {
            for (int j = 0; j < LG; ++j) {
                go[i][j] = INF;
            }   
        }   
        r[i] = flex(i, n - 1);
    }   
    /*
    for (int i = 0; i < m; ++i) {
        cout << r[i] << ' ';
    }   
    cout << '\n';
    */
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        pos[p[i]] = i;
    }   
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        a[i] = pos[a[i]];
    }   
    solve();
    build(0, 0, m - 1);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        if (get(0, 0, m - 1, l, r) <= r) {
            cout << '1';
        }   
        else {
            cout << '0';
        }   
    }   
    cout << '\n';
}