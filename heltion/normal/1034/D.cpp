#include <bits/stdc++.h>
using namespace std;
using LL = long long;
struct Seg{
    int L, R, id;
    bool operator < (const Seg& s) const {
        if (L == s.L) return R < s.R;
        return L < s.L;
    }
};
struct BIT{
    int n;
    vector<LL> v;
    BIT(int n) : n(n), v(n + 1) {}
    void add(int x, LL y) {
        for (; x <= n; x += x & -x) v[x] += y;
    }
    LL sum(int x) {
        LL res = 0;
        for (; x; x -= x & -x) res += v[x];
        return res;
    }
};
struct BIT_Range{
    BIT t1, t2;
    BIT_Range(int n) : t1(n), t2(n) {
    }
    void add(int L, int R, LL d) {
        t1.add(L, d);
        t1.add(R + 1, -d);
        t2.add(L, L * d);
        t2.add(R + 1, (R + 1) * -d);
    }
    LL sum(int x) {
        return t1.sum(x) * (x + 1) - t2.sum(x);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    set<Seg> ss;
    vector<vector<pair<int, int>>> vp(n + 1);
    auto split = [&](int x) {
        auto it = ss.lower_bound({x, 0, 0});
        if (it != ss.begin()) {
            it = prev(it);
            auto [L, R, id] = *it;
            if (L < x and R > x) {
                ss.erase(it);
                ss.insert({L, x, id});
                ss.insert({x, R, id});
            }
        }
    };
    for (int i = 1; i <= n; i += 1) {
        int a, b;
        cin >> a >> b;
        split(a);
        split(b);
        for (auto it = ss.upper_bound({a, 0}); it != ss.end(); it = ss.erase(it)) {
            if (it->L >= b) break;
            vp[i].emplace_back(it->id, -(it->R - it->L));
        }
        ss.insert({a, b, i});
        vp[i].emplace_back(i, b - a);
        //for (auto [a, b, i] : ss) cout << "(" << a << "," << b << "," << i << ")"; cout << "\n";
    }
    auto f = [&](int u) {
        LL c = 0;
        vector<LL> g(n + 2);
        LL sj = 0;
        for (int i = 1, j = 1; i <= n; i += 1) {
            for (auto [x, y] : vp[i]) {
                if (j <= x) {
                    sj += y;
                    g[x + 1] -= y;
                }
            }
            while (j <= n and sj >= u) {
                j += 1;
                sj += g[j];
            }
            c += j - 1;
        }
        return c;
    };
    int L = 1, R = 1E9;
    while (L < R) {
        int M = (L + R + 1) >> 1;
        if (f(M) < k) R = M - 1;
        else L = M;
    }
    LL ans = 0;
    BIT bit(n);
    BIT_Range bit_range(n);
    for (int i = 1, j = 1; i <= n; i += 1) {
        for (auto [x, y] : vp[i]) {
            bit.add(1, y);
            bit.add(x + 1, -y);
            bit_range.add(1, x, y);
        }
        while (j <= n and bit.sum(j) >= L) j += 1;
        ans += bit_range.sum(j - 1);
    }
    cout << ans - (f(L) - k) * L << "\n";
    //cout << L << "\n";
}