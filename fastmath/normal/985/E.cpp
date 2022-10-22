#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 7;
const int INF = 1e9 + 7;

int mn[MAXN * 4];
int mx[MAXN * 4];

int a[MAXN];
bool dp[MAXN];
bool tree[MAXN * 4];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        mn[v] = a[tl];
        mx[v] = a[tl];
        return;
    }

    int tm = (tl + tr) / 2;
    build(v * 2 + 1, tl, tm);
    build(v * 2 + 2, tm + 1, tr);
    mn[v] = min(mn[v * 2 + 1], mn[v * 2 + 2]);
    mx[v] = max(mx[v * 2 + 1], mx[v * 2 + 2]);
}

int getmin(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return INF;
    if (l <= tl && tr <= r) return mn[v];
    int tm = (tl + tr) / 2;
    return min(getmin(v * 2 + 1, tl, tm, l, r), getmin(v * 2 + 2, tm + 1, tr, l, r));
}

int getmax(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return -INF;
    if (l <= tl && tr <= r) return mx[v];
    int tm = (tl + tr) / 2;
    return max(getmax(v * 2 + 1, tl, tm, l, r), getmax(v * 2 + 2, tm + 1, tr, l, r));
}

bool get(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return false;
    if (l <= tl && tr <= r) return tree[v];
    int tm = (tl + tr) / 2;
    return get(v * 2 + 1, tl, tm, l, r) || get(v * 2 + 2, tm + 1, tr, l, r);
}

void upd(int v, int tl, int tr, int p, bool val) {
    if (tl == tr) {
        tree[v] = val;
        return;
    }

    int tm = (tl + tr) / 2;
    if (p <= tm) upd(v * 2 + 1, tl, tm, p, val);
    else upd(v * 2 + 2, tm + 1, tr, p, val);
    tree[v] = tree[v * 2 + 1] || tree[v * 2 + 2];
}

int l[MAXN];

bool check(int l, int r, int d, int n) {
    return getmax(0, 0, n - 1, l, r) - getmin(0, 0, n - 1, l, r) <= d;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k, d;
    cin >> n >> k >> d;
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a, a + n);

    build(0, 0, n - 1);
    
    int u = n - 1;
    for (int i = n - 1; i >= 0; --i) {
        u = min(u, i);
        while (u && check(u - 1, i, d, n)) --u;
        l[i] = u;
    }

    dp[0] = true;
    upd(0, 0, n, 0, true);

    for (int i = 0; i < n; ++i) {
        dp[i + 1] = get(0, 0, n, l[i], i + 1 - k);
        upd(0, 0, n, i + 1, dp[i + 1]);
    }

    if (dp[n]) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}