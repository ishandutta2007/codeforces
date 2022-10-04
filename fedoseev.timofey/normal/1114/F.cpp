#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int md = 1e9 + 7;

void add(int &a, int b) {
    a += b;
    if (a >= md) a -= md;
}

int mul(int a, int b) {
    return ((ll)a * b) % md;
}

int power(int a, ll b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int a) {
    return power(a, md - 2);
}

const int M = 301;

ull who[M];
bool pr[M];
int invr[M];

vector <int> prms;

void prec() {
    for (int i = 2; i < M; ++i) pr[i] = 1;
    for (int i = 2; i < M; ++i) {
        if (pr[i]) {
            int nm = prms.size();
            prms.push_back(i);
            who[i] |= (1ull << nm);
            for (int j = 2 * i; j < M; j += i) {
                pr[j] = 0;
                who[j] |= (1ull << nm);
            }
        }
    }
    for (int i = 1; i < M; ++i) invr[i] = inv(i);
}   

const int N = 4e5 + 7;

ull mask[4 * N];
ull modm[4 * N];
int t[4 * N];
int modt[4 * N];

void build(int l, int r, int v, vector <int> &a) {
    modt[v] = 1;
    if (l == r) {
        mask[v] = who[a[l]];
        t[v] = a[l];
    }
    else {
        int m = (l + r) >> 1;
        build(l, m, 2 * v + 1, a);
        build(m + 1, r, 2 * v + 2, a);
        t[v] = mul(t[2 * v + 1], t[2 * v + 2]);
        mask[v] = mask[2 * v + 1] | mask[2 * v + 2];
    }
}

void update(int v, ull ms, int pr, int l, int r) {
    mask[v] |= ms;
    modm[v] |= ms;
    t[v] = mul(t[v], power(pr, r - l + 1));
    modt[v] = mul(modt[v], pr);
}

void push(int v, int l, int r) {
    //if (modm[v] == 0 && modt[v] == 1) return;
    int m = (l + r) >> 1;
    update(2 * v + 1, modm[v], modt[v], l, m);
    update(2 * v + 2, modm[v], modt[v], m + 1, r);
    modm[v] = 0;
    modt[v] = 1;
}

void modify(int ql, int qr, int val, int l, int r, int v) {
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) {
        update(v, who[val], val, l, r);
    }
    else {
        push(v, l, r);
        int m = (l + r) >> 1;
        modify(ql, qr, val, l, m, 2 * v + 1);
        modify(ql, qr, val, m + 1, r, 2 * v + 2);
        t[v] = mul(t[2 * v + 1], t[2 * v + 2]);
        mask[v] = mask[2 * v + 1] | mask[2 * v + 2];
    }
}

int getpr(int ql, int qr, int l, int r, int v) {
    if (qr < l || r < ql) return 1;
    if (ql <= l && r <= qr) return t[v];
    push(v, l, r);
    int m = (l + r) >> 1;
    return mul(getpr(ql, qr, l, m, 2 * v + 1), getpr(ql, qr, m + 1, r, 2 * v + 2));
}

ull getm(int ql, int qr, int l, int r, int v) {
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return mask[v];
    int m = (l + r) >> 1;
    return getm(ql, qr, l, m, 2 * v + 1) | getm(ql, qr, m + 1, r, 2 * v + 2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    prec();
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    build(0, n - 1, 0, a);
    while (q--) {
        string s;
        cin >> s;
        if (s[0] == 'M') {
            int l, r, x;
            cin >> l >> r >> x;
            --l, --r;
            modify(l, r, x, 0, n - 1, 0);
        }
        else {
            int l, r;
            cin >> l >> r;
            --l, --r;
            int pr = getpr(l, r, 0, n - 1, 0);
            ull ms = getm(l, r, 0, n - 1, 0);
            for (int i = 0; i < (int)prms.size(); ++i) {
                if (ms & (1ull << i)) {
                    pr = mul(pr, mul(prms[i] - 1, invr[prms[i]]));
                }
            }
            cout << pr << '\n';
        }
    }
}