#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 239;

int t[4 * N];
int mod[4 * N];

void update(int v, int x) {
    t[v] += x;
    mod[v] += x;
}

void push(int v) {
    if (mod[v] != 0) {
        update(2 * v + 1, mod[v]);
        update(2 * v + 2, mod[v]);
        mod[v] = 0;
    }
}

void modify(int ql, int qr, int x, int l = 0, int r = N - 1, int v = 0) {
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) {
        update(v, x);
    }
    else {
        push(v);
        int m = (l + r) >> 1;
        modify(ql, qr, x, l, m, 2 * v + 1);
        modify(ql, qr, x, m + 1, r, 2 * v + 2);
        t[v] = min(t[2 * v + 1], t[2 * v + 2]);
    }
}

void _set(int x, int val, int l = 0, int r = N - 1, int v = 0) {
    if (x < l || r < x) return;
    if (l == r) {
        t[v] = val;
    }
    else {
        push(v);
        int m = (l + r) >> 1;
        _set(x, val, l, m, 2 * v + 1);
        _set(x, val, m + 1, r, 2 * v + 2);
        t[v] = min(t[2 * v + 1], t[2 * v + 2]);
    }
}

int get_last(int l = 0, int r = N - 1, int v = 0) {
    if (t[v] >= 0) return -1;
    if (l == r) return l;
    push(v);
    int m = (l + r) >> 1;
    int x = get_last(m + 1, r, 2 * v + 2);
    if (x != -1) return x;
    return get_last(l, m, 2 * v + 1);
}

const int Inf = 1e9 + 7;

struct fenwick {
    vector <int> f;
    int n;
    void modify(int i, int val) {
        i = n - i - 1;
        for (; i < n; i |= i + 1) f[i] += val;
    }
    int get(int r) {
        r = n - r - 1;
        int res = 0;
        for (; r >= 0; r &= r + 1, --r) res += f[r];
        return res;
    }
    void init(int _n) {
        n = _n;
        f.resize(n);
    }
    fenwick(int _n) {
        init(_n);
    }
};

int ca[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    fill(t, t + 4 * N, Inf);
    vector <int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++ca[a[i]];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    fenwick fb(N);
    for (int i = 0; i < m; ++i) {
        fb.modify(b[i], 1);
    }
    fenwick fa(N);
    for (int i = 0; i < n; ++i) {
        fa.modify(a[i], 1);
    }
    for (int i = 0; i < n; ++i) {
        int cnt = fb.get(a[i]);
        int pos = fa.get(a[i]);
        _set(a[i], cnt - pos);
    }
    int q;
    cin >> q;
    while (q--) {
        int t, i, x;
        cin >> t >> i >> x;
        --i;
        if (t == 1) {
            modify(0, a[i], 1);
            modify(0, x, -1);
            --ca[a[i]];
            ++ca[x];
            if (ca[a[i]] == 0) _set(a[i], Inf);
            fa.modify(a[i], -1);
            fa.modify(x, 1);
            a[i] = x;
            int cnt = fb.get(a[i]);
            int pos = fa.get(a[i]);
            _set(a[i], cnt - pos);
        }   
        else {
            modify(0, b[i], -1);
            modify(0, x, 1);
            fb.modify(b[i], -1);
            fb.modify(x, 1);
            b[i] = x;
        }
        cout << get_last() << '\n';
    }
}