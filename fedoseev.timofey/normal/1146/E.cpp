#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int Inf = 1e9;
 
struct SegmentTree {
    int n;
    vector <int> t;
 
    void build(const vector <int> &a) {
        for (int i = 0; i < n; ++i) {
            t[n + i] = a[i];
        }
        for (int i = n - 1; i > 0; --i) {
            t[i] = max(t[i << 1], t[i << 1 | 1]);
        }
    }
 
    void modify(int x, int val) {
        for (t[x += n] = val; x > 1; x >>= 1) {
            t[x >> 1] = max(t[x], t[x ^ 1]);
        }
    }
 
    int get(int l, int r) {
        ++r;
        int res = -Inf;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, t[l++]);
            if (r & 1) res = max(res, t[--r]);
        }
        return res;
    }
 
    SegmentTree(const vector <int> &a) {
        n = a.size();
        t.resize(2 * n, -Inf);
        build(a);
    }
};

struct fenwick {
    vector <int> f;
    int n;
    fenwick(int nn) {
        n = nn;
        f.resize(n);
    }
    void modify(int i, int val) {
        for (; i < n; i |= i + 1) f[i] += val;
    }
    int get(int i) {
        int res = 0;
        for (; i >= 0; i &= i + 1, --i) res += f[i];
        return res;
    }
    int sum(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
    void clear() {
        for (int i = 0; i < n; ++i) f[i] = 0;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <char> s(q);
    vector <int> x(q);
    for (int i = 0; i < q; ++i) {
        cin >> s[i] >> x[i];
    }  
    vector <int> id(q);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&] (int i, int j) {
        return x[i] < x[j];
    });

    vector <int> idl = id;
    vector <int> idg = id;
    for (int i = 0; i < q; ++i) {
        if (s[id[i]] == '>') idl[i] = -Inf;
        else idg[i] = -Inf;
    }

    SegmentTree stl(idl), stg(idg);

    vector <int> y = x;
    sort(y.begin(), y.end());
    vector <int> wh(n);
    vector <int> b = a;
    for (int i = 0; i < n; ++i) {
        int l = min(-a[i], a[i]);
        int r = max(-a[i], a[i]);
        int l1 = upper_bound(y.begin(), y.end(), l) - y.begin();
        int r1 = upper_bound(y.begin(), y.end(), r) - y.begin() - 1;
        int l2 = lower_bound(y.begin(), y.end(), l) - y.begin();
        int r2 = lower_bound(y.begin(), y.end(), r) - y.begin() - 1;
        int v1 = -Inf;
        int v2 = -Inf;
        if (r1 >= l1 && l1 != n - 1) v1 = stl.get(l1, r1);
        if (r2 >= l2 && l2 != n - 1) v2 = stg.get(l2, r2);
        if (v1 == -Inf && v2 == -Inf) wh[i] = -1;
        else {
            if (v1 > v2) {
                b[i] = abs(a[i]);
                wh[i] = v1;
            }
            else {
                b[i] = -abs(a[i]);
                wh[i] = v2;
            }
        }
    }
    for (int i = 0; i < n; ++i) a[i] = abs(a[i]);
    fenwick f(q);
    vector <int> kek_id(n);
    iota(kek_id.begin(), kek_id.end(), 0);
    sort(kek_id.begin(), kek_id.end(), [&] (int i, int j) {
        return a[i] < a[j];
    });
    int uk = 0;
    for (int i : kek_id) {
        while (uk < id.size() && x[id[uk]] < -a[i]) {
            if (s[id[uk]] == '>') {
                f.modify(id[uk], 1);
            }
            ++uk;
        }
        if (f.sum(wh[i] + 1, q - 1) % 2 == 1) {
            b[i] *= -1;
        }
    }
    reverse(kek_id.begin(), kek_id.end());
    uk = q - 1;
    f.clear();
    for (int i : kek_id) {
        while (uk >= 0 && x[id[uk]] > a[i]) {
            if (s[id[uk]] == '<') {
                f.modify(id[uk], 1);
            }
            --uk;
        }
        if (f.sum(wh[i] + 1, q - 1) % 2 == 1) {
            b[i] *= -1;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << b[i] << ' ';
    }
}