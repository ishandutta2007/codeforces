#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;

int n, k, a, b, q;

int arr[MAXN];

void read() {
    cin >> n >> k >> a >> b >> q;
}

int acnt[MAXN << 2], asum[MAXN << 2], bcnt[MAXN << 2], bsum[MAXN << 2];

int getacnt(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return 0;
    if (l <= tl && tr <= r) return acnt[v];
    int tm = (tl + tr) >> 1;
    return getacnt(v * 2 + 1, tl, tm, l, r) + getacnt(v * 2 + 2, tm + 1, tr, l, r);
}

int getbcnt(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return 0;
    if (l <= tl && tr <= r) return bcnt[v];
    int tm = (tl + tr) >> 1;
    return getbcnt(v * 2 + 1, tl, tm, l, r) + getbcnt(v * 2 + 2, tm + 1, tr, l, r);
}

int getasum(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return 0;
    if (l <= tl && tr <= r) return asum[v];
    int tm = (tl + tr) >> 1;
    return getasum(v * 2 + 1, tl, tm, l, r) + getasum(v * 2 + 2, tm + 1, tr, l, r);
}

int getbsum(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return 0;
    if (l <= tl && tr <= r) return bsum[v];
    int tm = (tl + tr) >> 1;
    return getbsum(v * 2 + 1, tl, tm, l, r) + getbsum(v * 2 + 2, tm + 1, tr, l, r);
}

void updacnt(int v, int tl, int tr, int p, int x) {
    if (tl == tr) {
        acnt[v] = (arr[p] + x >= a);
        return;
    }   
    int tm = (tl + tr) >> 1;
    if (p <= tm) updacnt(v * 2 + 1, tl, tm, p, x);
    else updacnt(v * 2 + 2, tm + 1, tr, p, x);
    acnt[v] = acnt[v * 2 + 1] + acnt[v * 2 + 2];
}   

void updbcnt(int v, int tl, int tr, int p, int x) {
    if (tl == tr) {
        bcnt[v] = (arr[p] + x >= b);
        return;
    }   
    int tm = (tl + tr) >> 1;
    if (p <= tm) updbcnt(v * 2 + 1, tl, tm, p, x);
    else updbcnt(v * 2 + 2, tm + 1, tr, p, x);
    bcnt[v] = bcnt[v * 2 + 1] + bcnt[v * 2 + 2];
}

void updasum(int v, int tl, int tr, int p, int x) {
    if (tl == tr) {
        asum[v] = (arr[p] + x) * (arr[p] + x < a);
        return;
    }   
    int tm = (tl + tr) >> 1;
    if (p <= tm) updasum(v * 2 + 1, tl, tm, p, x);
    else updasum(v * 2 + 2, tm + 1, tr, p, x);
    asum[v] = asum[v * 2 + 1] + asum[v * 2 + 2];
}

void updbsum(int v, int tl, int tr, int p, int x) {
    if (tl == tr) {
        bsum[v] = (arr[p] + x) * (arr[p] + x < b);
        return;
    }   
    int tm = (tl + tr) >> 1;
    if (p <= tm) updbsum(v * 2 + 1, tl, tm, p, x);
    else updbsum(v * 2 + 2, tm + 1, tr, p, x);
    bsum[v] = bsum[v * 2 + 1] + bsum[v * 2 + 2];
}

void print() {
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int p, x;
            cin >> p >> x;
            --p;
            updacnt(0, 0, MAXN, p, x);
            updbcnt(0, 0, MAXN, p, x);
            updasum(0, 0, MAXN, p, x);
            updbsum(0, 0, MAXN, p, x);
            arr[p] += x;
        }   
        else {
            int p;
            cin >> p;
            --p;
            int sum1 = getbcnt(0, 0, MAXN, 0, p - 1) * b + getbsum(0, 0, MAXN, 0, p - 1);
            int sum2 = getacnt(0, 0, MAXN, p + k, MAXN) * a + getasum(0, 0, MAXN, p + k, MAXN);
            cout << sum1 + sum2 << '\n';
        }
    }   
}   

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    print();

    return 0;
}