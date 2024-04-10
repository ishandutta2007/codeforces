#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;

int n, have;
int a[MAXN];

void read() {
    cin >> n >> have;
    for (int i = 0; i < n; ++i) cin >> a[i];
}

bool ch[MAXN * 4];

void chbuild(int v, int tl, int tr) {
    if (tl == tr) {
        ch[v] = 1;
        return;
    }   
    int tm = (tl + tr) / 2;
    chbuild(v * 2 + 1, tl, tm); chbuild(v * 2 + 2, tm + 1, tr);
    ch[v] = ch[v * 2 + 1] + ch[v * 2 + 2];
}   

void chupd(int v, int tl, int tr, int p) {
    if (tl == tr) {
        ch[v] = 0;
        return;
    }
    int tm = (tl + tr) / 2;
    if (p <= tm) chupd(v * 2 + 1, tl, tm, p);
    else chupd(v * 2 + 2, tm + 1, tr, p);
    ch[v] = ch[v * 2 + 1] + ch[v * 2 + 2];
}

int chget(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return 0;
    if (l <= tl && tr <= r) return ch[v];
    int tm = (tl + tr) / 2;
    return chget(v * 2 + 1, tl, tm, l, r) + chget(v * 2 + 2, tm + 1, tr, l, r);
}

int tree[MAXN * 4];
void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = a[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2 + 1, tl, tm);
    build(v * 2 + 2, tm + 1, tr);
    tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
}

void upd(int v, int tl, int tr, int p) {
    if (tl == tr) {
        tree[v] = 0;
        return;
    }   
    int tm = (tl + tr) / 2;
    if (p <= tm) upd(v * 2 + 1, tl, tm, p);
    else upd(v * 2 + 2, tm + 1, tr, p);
    tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
}

int get(int v, int tl, int tr, int x) {
    if (tl == tr) return tl;
    int tm = (tl + tr) / 2;
    if (x < tree[v * 2 + 1]) return get(v * 2 + 1, tl, tm, x);
    else return get(v * 2 + 2, tm + 1, tr, x - tree[v * 2 + 1]);
}

int getsum(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return 0;
    if (l <= tl && tr <= r) return tree[v];
    int tm = (tl + tr) / 2;
    return getsum(v * 2 + 1, tl, tm, l, r) + getsum(v * 2 + 2, tm + 1, tr, l, r);
}   

int ans = 0;
void solve() {
    chbuild(0, 0, n - 1);
    build(0, 0, n - 1);
    int u = 0;
    int sum = tree[0];
    int cnt = n;
    while (cnt) {
        ans += cnt * (have / sum);
        have %= sum;
        int tmp = getsum(0, 0, n - 1, u, n - 1);
        if (tmp <= have) {
            ans += chget(0, 0, n - 1, u, n - 1);
            have -= tmp;
            u = 0;   
        }
        int pref = getsum(0, 0, n - 1, 0, u - 1);
        int p = get(0, 0, n - 1, have + pref);
        upd(0, 0, n - 1, p);
        chupd(0, 0, n - 1, p);
        sum -= a[p];
        --cnt;
    }
}

void print() {
    cout << ans << '\n';
}   

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}