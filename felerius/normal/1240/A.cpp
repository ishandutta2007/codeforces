#include <bits/stdc++.h>

// Contest: Codeforces Round #591 (Div. 1, based on Technocup 2020 Elimination Round 1) (https://codeforces.com/contest/1240)
// Problem: A: Save the Nature (https://codeforces.com/contest/1240/problem/A)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        vector<ll> p(n);
        for (auto& pi : p) cin >> pi, pi /= 100;
        ll x, a, y, b, k; cin >> x >> a >> y >> b >> k;

        sort(begin(p), end(p), greater<>{});
        vector<ll> s(n);
        s[0] = p[0];
        for (int i = 1; i < n; ++i)
            s[i] = s[i - 1] + p[i];

        if (x < y)
            swap(x, y), swap(a, b);

        auto get_sum = [&](int l, int r) {
            return r == 0 ? 0 : s[r - 1] - (l == 0 ? 0 : s[l - 1]);
        };

        auto l = lcm(a, b);
        ll res = -1;
        for (int i = 1; i <= n; ++i) {
            auto c = i / l;
            auto d = i / a - c;
            auto e = i / b - c;
            auto sum = get_sum(0, c) * (x + y);
            sum += get_sum(c, c + d) * x;
            sum += get_sum(c + d, c + d + e) * y;
            if (sum >= k) {
                res = i;
                break;
            }
        }

        cout << res << '\n';
    }

    return 0;
}