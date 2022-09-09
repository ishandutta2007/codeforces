#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int off = 1;
struct BIT{
    int m;
    vector<LL> d;
    vector<int> s;
    LL *dd;
    int *ss;
    void add(LL y, int z) {
        if (off) d.push_back(y);
        else {
            int i = lower_bound(dd, dd + m, y) - dd;
            for (i += 1; i <= m; i += i & -i)
                ss[i - 1] = max(ss[i - 1], z);
        }
    }
    int query(LL p) {
        if (off) return 0;
        int res = -2E5;
        int i = upper_bound(dd, dd + m, p) - dd;
        if (i == 0) return res;
        for (; i; i -= i & -i)
            res = max(res, ss[i - 1]);
        return res;
    }
    void init() {
        sort(d.begin(), d.end());
        d.erase(unique(d.begin(), d.end()), d.end());
        dd = d.data();
        s.resize(m = d.size(), -2E5);
        ss = s.data();
    }
};
struct Tree{
    int n;
    vector<BIT> bit;
    Tree(int n) : n(n), bit(n + 1) {}
    void init() {
        for (auto& b : bit) b.init();
    }
    void add(int x, LL y, int z) {
        for (x += 1; x <= n; x += x & -x)
            bit[x - 1].add(y, z);
    }
    int query(int x, LL p) {
        int res = -2E5;
        for (x += 1; x; x -= x & -x)
            res = max(res, bit[x - 1].query(p));
        return res;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL n, v;
    cin >> n >> v;
    vector<int> a(n + 1), t(n + 1);
    for (int i = 1; i <= n; i += 1) cin >> t[i];
    for (int i = 1; i <= n; i += 1) cin >> a[i];
    if (n == 0) {
        int m = 200000;
        n = v = m;
        a.resize(n + 1);
        t.resize(n + 1);
        for (int i = 1; i <= n; i += 1) {
            t[i] = t[i - 1] + rand() % m;
            a[i] = rand();
        }
    }
    vector<pair<int, int>> vp;
    for (int i = 0; i <= n; i += 1) vp.emplace_back(a[i], t[i]);
    sort(vp.begin(), vp.end());
    Tree A(n), B(n);
    for (int i = 0; i <= n; i += 1) {
        A.add(i, vp[i].second * v - vp[i].first, 0);
        B.add(n - i, vp[i].second * v + vp[i].first, 0);
    }
    off = 0;
    int ans = 0;
    A.init();
    B.init();
    off = 0;
    for (int j = 0; j <= n; j += 1) {
        int i = lower_bound(vp.begin(), vp.end(), make_pair(a[j], t[j])) - vp.begin();
        int f = A.query(i - 1, vp[i].second * v - vp[i].first);
        int g = B.query(n - i - 1, vp[i].second * v + vp[i].first);
        int dp = j ? max(f, g) + 1 : 0;
        ans = max(ans, dp);
        A.add(i, vp[i].second * v - vp[i].first, dp);
        B.add(n - i, vp[i].second * v + vp[i].first, dp);
    }
    cout << ans;
}