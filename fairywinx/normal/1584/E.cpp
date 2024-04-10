#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

const long long inf = 1e18 + 288;

struct sparse {
    vector<long long> t;
    int n;

    void build(int v, int l, int r, vector<long long> &a) {
        if (r - l == 1) {
            t[v] = a[l];
            return;
        }

        int m = (l + r) / 2;
        build(v * 2 + 1, l, m, a);
        build(v * 2, m, r, a);
        t[v] = min(t[v * 2 + 1], t[v * 2]);
    }

    int first(int v, int l, int r, int L, int R, long long val) {
        if (R <= l || r <= L)
            return n;
        if (L <= l && r <= R && t[v] >= val)
            return n;
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = first(v * 2 + 1, l, m, L, R, val);
        if (res == n) {
            return first(v * 2, m, r, L, R, val);
        } else {
            return res;
        }
    }

    long long get(int l, int r, long long val) {
        return first(1, 0, n, l, r, val);
    }

    sparse(vector<long long> a) {
        n = a.size();
        int sz = 1;
        while (sz < 2 * n)
            sz *= 2;
        t.resize(sz);
        build(1, 0, n, a);
    }
};

struct SegTree {
    vector<vector<long long>> t;
    int n;

    void build(int v, int l, int r, vector<long long> &a) {
        t[v].clear();
        if (r - l == 1) {
            t[v] = {a[l]};
            return;
        }

        int m = (l + r) / 2;
        build(v * 2 + 1, l, m, a);
        build(v * 2, m, r, a);
        merge(all(t[v * 2 + 1]), all(t[v * 2]), back_inserter(t[v]));
    }

    int get(int v, int l, int r, int L, int R, long long val) {
        if (r <= L || R <= l)
            return 0;
        if (L <= l && r <= R) {
            return upper_bound(all(t[v]), val) - lower_bound(all(t[v]), val);
        }
        int m = (l + r) / 2;
        return get(v * 2 + 1, l, m, L, R, val) + get(v * 2, m, r, L, R, val);
    }

    SegTree(int _n, vector<long long> a) {
        n = _n;
        int sz = 1;
        while (sz < 2 * n)
            sz *= 2;
        t.resize(sz);
        build(1, 0, n, a);
    }

    int get(int l, int r, long long val) {
        return get(1, 0, n, l, r, val);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<long long> p(n + 1), p1(n, inf), p2(n, inf);
    for (int i = 0; i < n; ++i) {
        p[i + 1] = a[i] - p[i];
    }
    for (int i = 1; i <= n; ++i) {
        if ((i - 1) % 2 == 0)
            p1[i - 1] = p[i];
        else
            p2[i - 1] = p[i];
    }

    // for (auto i : p1)
    //     cout << i << ' ';
    // cout << '\n';
    // for (auto i : p2)
    //     cout << i << ' ';
    // cout << '\n';

    array<sparse, 2> sp = {sparse(p1), sparse(p2)};
    array<SegTree, 2> t = {SegTree(n, p1), SegTree(n, p2)};
    long long ans = 0;
    long long val = 0;
    const int type = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 1) {
            int l = min(sp[type].get(i, n, val), sp[type ^ 1].get(i, n, -val));
            ans += t[type].get(i, l, val) + t[type ^ 1].get(i, l, -val);
            val = a[i] - val;
        } else {
            int l = min(sp[type ^ 1].get(i, n, val), sp[type].get(i, n, -val));
            // cout << val << '\n';
            // cout << i << ':' << l << ' ' << t[type].get(i, l, val) << ' ' << t[type ^ 1].get(i, l, -val)<< '\n';
            ans += t[type ^ 1].get(i, l, val) + t[type].get(i, l, -val);
            val = a[i] - val;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    SOLVE;
}