#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 200001;
const int K = 5;
const int INF = 1e16 + 7;
   
int n, k, q;
int a[MAXN][K];
int tree[MAXN << 2][1 << K];

void upd(int v, int tl, int tr, int p) {
    if (tl == tr) {
        for (int i = 0; i < k; ++i) {
            cin >> a[tl][i];
        }   
        for (int mask = 0; mask < (1 << k); ++mask) {
            int cost = 0;
            for (int i = 0; i < k; ++i) {
                if ((mask >> i) & 1) {
                    cost += a[tl][i];
                }
                else {
                    cost -= a[tl][i];
                }   
            }   
            tree[v][mask] = cost;
        }   
        return;
    }   
    int tm = (tl + tr) >> 1;
    if (p <= tm) {
        upd(v * 2 + 1, tl, tm, p);
    }
    else {
        upd(v * 2 + 2, tm + 1, tr, p);
    }   
    for (int mask = 0; mask < (1 << k); ++mask) {
        tree[v][mask] = max(tree[v * 2 + 1][mask], tree[v * 2 + 2][mask]);
    }
}

int getmax(int v, int tl, int tr, int l, int r, int mask) {
    if (tr < l || r < tl) {
        return -INF;
    }   
    if (l <= tl && tr <= r) {
        return tree[v][mask];
    }   
    int tm = (tl + tr) >> 1;
    return max(getmax(v * 2 + 1, tl, tm, l, r, mask), getmax(v * 2 + 2, tm + 1, tr, l, r, mask));
}   

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 0; i < (MAXN << 2); ++i) {
        for (int mask = 0; mask < (1 << K); ++mask) {
            tree[i][mask] = -INF;
        }
    }   

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        upd(0, 0, n - 1, i);
    }   
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int p;
            cin >> p; --p;
            upd(0, 0, n - 1, p);
        }   
        else {
            int l, r;
            cin >> l >> r;
            --l; --r;
            int ans = -INF;
            for (int mask = 0; mask < (1 << (k - 1)); ++mask) {
                ans = max(ans, getmax(0, 0, n - 1, l, r, mask) + getmax(0, 0, n - 1, l, r, mask ^ ((1 << k) - 1)));
            }   
            cout << ans << '\n';
        }   
    }   

    return 0;
}