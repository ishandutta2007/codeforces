#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll C(int n) { return n * ll(n + 1) / 2; }

struct SegTree {
    struct Seg {
        bool one;
        ll sum;
        int l_cnt, r_cnt;
        int l_val, r_val;
    };

    int n;
    vector<Seg> a;

    SegTree(vector<int> &b) : n(b.size()), a(2 * n) {
        for (int i = 0; i < n; i++) {
            a[i + n] = {true, 0, 1, 1, b[i], b[i]};
        }

        for (int i = n - 1; i > 0; i--) {
            a[i] = combine(a[lc(i)], a[rc(i)]);
        }
    }

    inline int lc(int i) { return 2 * i; }
    inline int rc(int i) { return 2 * i + 1; }

    Seg combine(Seg u, Seg v) {
        if (u.l_val == 0) return v;
        if (v.l_val == 0) return u;

        Seg r{};
        r.sum = u.sum + v.sum;
        r.l_val = u.l_val;
        r.r_val = v.r_val;

        if (u.r_val > v.l_val) {
            r.one = false;
            r.l_cnt = u.l_cnt;
            r.r_cnt = v.r_cnt;

            if (!u.one) r.sum += C(u.r_cnt);
            if (!v.one) r.sum += C(v.l_cnt);
        } else { 
            r.one = u.one && v.one;

            if (u.one && v.one) {
                r.l_cnt = u.l_cnt + v.r_cnt;
                r.r_cnt = u.l_cnt + v.r_cnt;
            } else if (u.one && !v.one) {
                r.l_cnt = u.l_cnt + v.l_cnt;
                r.r_cnt = v.r_cnt;
            } else if (!u.one && v.one) {
                r.l_cnt = u.l_cnt;
                r.r_cnt = u.r_cnt + v.r_cnt;
            } else {
                r.sum += C(u.r_cnt + v.l_cnt);
                r.l_cnt = u.l_cnt;
                r.r_cnt = v.r_cnt;
            }
        }

        return r;
    }

    ll query(int l, int r) {
        Seg seg_l{}, seg_r{};

        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) seg_l = combine(seg_l, a[l++]);
            if (r & 1) seg_r = combine(a[--r], seg_r);
        }

        Seg seg = combine(seg_l, seg_r);
        if (seg.one) return C(seg.l_cnt);
        else return seg.sum + C(seg.l_cnt) + C(seg.r_cnt);
    }

    void update(int i, int u) {
        for (a[i += n] = {true, 0, 1, 1, u, u}; i /= 2;) {
            a[i] = combine(a[lc(i)], a[rc(i)]);
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    SegTree sgt(a);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, u;
            cin >> i >> u;
            sgt.update(--i, u);
        } else {
            int l, r;
            cin >> l >> r;
            cout << sgt.query(--l, r) << "\n";
        }
    }
}