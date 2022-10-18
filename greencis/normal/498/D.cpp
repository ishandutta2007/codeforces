//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXN = 1 << 17;
constexpr int LCM = 60;

int t[2 * MAXN][LCM];
int a[MAXN];
int md[2 * MAXN + 5];

inline void create(int* res, int x) {
    for (int i = 0; i < LCM; ++i) {
        res[i] = (i % x == 0 ? 2 : 1);
    }
}

inline void combine(int* res, const int* lhs, const int* rhs) {
    for (int i = 0; i < LCM; ++i)
        res[i] = lhs[i] + rhs[md[i + lhs[i]]];
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        for (int i = 0; i < LCM; ++i)
            create(t[v], a[tl]);
    } else {
        int tm = (tl + tr) >> 1;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        combine(t[v], t[2 * v], t[2 * v + 1]);
    }
}

void update(int v, int tl, int tr, int idx, int val) {
    if (tl == tr)
        create(t[v], val);
    else {
        int tm = (tl + tr) >> 1;
        if (idx <= tm)
            update(2 * v, tl, tm, idx, val);
        else
            update(2 * v + 1, tm + 1, tr, idx, val);
        combine(t[v], t[2 * v], t[2 * v + 1]);
    }
}

int get(int v, int tl, int tr, int l, int r, int off = 0) {
    if (tl == l && tr == r)
        return t[v][off];
    int tm = (tl + tr) >> 1;
    int ans = 0;
    if (l <= tm)
        ans += get(2 * v, tl, tm, l, min(r, tm), off);
    if (r > tm)
        ans += get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, md[off + ans]);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i = 0; i < 2 * MAXN + 5; ++i) md[i] = i % LCM;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    build(1, 0, n - 1);

    int q;
    cin >> q;
    while (q--) {
        char tp[2];
        int x, y;
        cin >> tp >> x >> y;
        if (*tp == 'C') {
            update(1, 0, n - 1, x - 1, y);
        } else {
            cout << get(1, 0, n - 1, x - 1, y - 2) << '\n';
        }
    }
}