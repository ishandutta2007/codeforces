#include <bits/stdc++.h>

// Contest: Educational Codeforces Round 75 (Rated for Div. 2) (https://codeforces.com/contest/1251)
// Problem: D: Salary Changing (https://codeforces.com/contest/1251/problem/D)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; ll s; cin >> n >> s;
        vector<pair<int,int>> e(n);
        for (auto& [li, ri] : e) cin >> li >> ri;
        sort(begin(e), end(e));

        ll l = e[n / 2].first, r = s + 1;
        while (r - l > 1) {
            ll m = (l + r) / 2;
            ll cost = 0;
            int high = 0;
            for (int i = n - 1; i >= 0; --i) {
                auto [li, ri] = e[i];
                if (li >= m)
                    cost += li, high++;
                else if (li < m && m <= ri) {
                    if (high <= n / 2)
                        cost += m, high++;
                    else
                        cost += li;
                } else
                    cost += li;
            }

            if (cost <= s && high > n / 2)
                l = m;
            else
                r = m;
        }

        cout << l << '\n';
    }

    return 0;
}