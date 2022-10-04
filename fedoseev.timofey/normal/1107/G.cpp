#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll Inf = 2e18;

struct SegmentTree {
    int n;
    vector <ll> t;
 
    void build(const vector <ll> &a) {
        for (int i = 0; i < n; ++i) {
            t[n + i] = a[i];
        }
        for (int i = n - 1; i > 0; --i) {
            t[i] = max(t[i << 1], t[i << 1 | 1]);
        }
    }
 
    void modify(int x, ll val) {
        for (t[x += n] = val; x > 1; x >>= 1) {
            t[x >> 1] = max(t[x], t[x ^ 1]);
        }
    }
 
    ll get(int l, int r) {
        ++r;
        ll res = -Inf;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, t[l++]);
            if (r & 1) res = max(res, t[--r]);
        }
        return res;
    }
 
    SegmentTree(const vector <ll> &a) {
        n = a.size();
        t.resize(2 * n, -Inf);
        build(a);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, a;
    cin >> n >> a;
    vector <int> c(n);
    vector <int> d(n);
    for (int i = 0; i < n; ++i) cin >> d[i] >> c[i];
    ll ans = 0;
    for (int i = 0; i < n; ++i) ans = max(ans, (ll)a - c[i]);
    vector <ll> fir(n);
    for (int i = 1; i < n; ++i) {
        fir[i] = (ll)(d[i] - d[i - 1]) * (d[i] - d[i - 1]);
    }
    SegmentTree kek(fir);
    vector <ll> pref(n + 1);
    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + c[i];
    vector <ll> sec(n + 1);
    for (int i = 0; i <= n; ++i) {
        sec[i] = -pref[i] + (ll)i * a;
    }
    vector <ll> thr(n + 1);
    for (int i = 0; i <= n; ++i) {
        thr[i] = -sec[i];
    }
    SegmentTree mem(sec);
    SegmentTree flex(thr);
    for (int i = 1; i < n; ++i) {
        int l = i, r = n;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (kek.get(i, m) == fir[i]) l = m;
            else r = m;
        }
        int cr = r;
        l = 0, r = i;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (kek.get(m, i) == fir[i]) r = m;
            else l = m;
        }
        int cl = l;
        ans = max(ans, mem.get(i + 1, cr) + flex.get(cl, i) - fir[i]);
    }
    cout << ans << '\n';
}