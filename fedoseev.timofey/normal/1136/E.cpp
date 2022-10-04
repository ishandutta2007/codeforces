#include <bits/stdc++.h>

#define int long long

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 7;

int t[4 * N];
int mod[4 * N];

void update(int v, int l, int r, int x) {
    t[v] += (r - l + 1) * x;
    mod[v] += x;
}

void push(int v, int l, int r) {
    if (mod[v]) {
        int m = (l + r) >> 1;
        update(2 * v + 1, l, m, mod[v]);
        update(2 * v + 2, m + 1, r, mod[v]);
        mod[v] = 0;
    }
}

void modify(int ql, int qr, int x, int l = 0, int r = N, int v = 0) {
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) {
        update(v, l, r, x);
    }
    else {
        push(v, l, r);
        int m = (l + r) >> 1;
        modify(ql, qr, x, l, m, 2 * v + 1);
        modify(ql, qr, x, m + 1, r, 2 * v + 2);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
}

int get(int ql, int qr, int l = 0, int r = N, int v = 0) {
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return t[v];
    push(v, l, r);
    int m = (l + r) >> 1;
    return get(ql, qr, l, m, 2 * v + 1) + get(ql, qr, m + 1, r, 2 * v + 2);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <int> k(n - 1);
    for (int i = 0; i + 1 < n; ++i) cin >> k[i];
    set <int> idx;
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i + 1] != a[i] + k[i]) {
            idx.insert(i + 1);
        }
    }
    idx.insert(n);
    for (int i = 0; i < n; ++i) modify(i, i, a[i]);

    int q;
    cin >> q;
    while (q--) {
        char c;
        cin >> c;
        if (c == '+') {
            int id, val;
            cin >> id >> val;
            --id;
            modify(id, id, val);
            if (id && get(id, id) > get(id - 1, id - 1) + k[id - 1]) idx.insert(id);
            int a, b;
            while (id + 1 < n && (a = get(id, id)) + k[id] > (b = get(id + 1, id + 1))) {
                int r = *idx.upper_bound(id);
                int d = a + k[id] - b;
                modify(id + 1, r - 1, d);
                idx.erase(id + 1);
                id = r - 1;
            }
        }
        else {
            int l, r;
            cin >> l >> r;
            --l, --r;
            cout << get(l, r) << '\n';
        }
    }
}