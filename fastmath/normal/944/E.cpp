#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

int l[MAXN], r[MAXN];
int add[MAXN];
int a[MAXN];
int dp1[MAXN], dp2[MAXN];

int tree[MAXN << 2];

void build(int v, int tl, int tr) {
    tree[v] = 0;
    if (tl == tr) return;
    int tm = (tl + tr) >> 1;
    build(v * 2 + 1, tl, tm); build(v * 2 + 2, tm + 1, tr);    
}

int get(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return 0;
    if (l <= tl && tr <= r) return tree[v];
    int tm = (tl + tr) >> 1;
    return max(get(v * 2 + 1, tl, tm, l, r), get(v * 2 + 2, tm + 1, tr, l, r));
}

void upd(int v, int tl, int tr, int p, int x) {
    if (tl == tr) {
        tree[v] = x;
        return;
    }
    int tm = (tl + tr) >> 1;
    if (p <= tm) upd(v * 2 + 1, tl, tm, p, x);
    else upd(v * 2 + 2, tm + 1, tr, p, x);
    tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);
}

signed main() { 
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];

    for (int i = 0; i < n; ++i) {
        ++add[l[i]]; --add[r[i] + 1];
    }

    int curr = 0;
    for (int i = 1; i <= m; ++i) {
        curr += add[i];
        a[i] = curr;
    }   
    
    build(0, 0, MAXN);
    for (int i = 1; i <= m; ++i) {
        dp1[i] = get(0, 0, MAXN, 0, a[i]) + 1;
        upd(0, 0, MAXN, a[i], dp1[i]);
    }

    build(0, 0, MAXN);
    for (int i = m; i >= 1; --i) {
        dp2[i] = get(0, 0, MAXN, 0, a[i]) + 1;
        upd(0, 0, MAXN, a[i], dp2[i]);
    }   
    
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }
    cout << ans << '\n';

    return 0;
}