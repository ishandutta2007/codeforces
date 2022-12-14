#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for (int i = 0; (i) < n; (i)++)
#define SZ(a)       int(size(a))
#define ALL(a)      (a).begin(), (a).end()
#define RALL(a)     (a).rbegin(), (a).rend()

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using ld = long double;
using pii = pair<int, int>;

const int kA = 1e5 + 1;
vector<int> pr;
int pr_least[kA];

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    ll ans = 0;
    map<vector<pii>, int> m;
    for (int x : a) {
        vector<pii> fac0;
        for (; x > 1; x /= pr_least[x]) {
            if (fac0.empty() || get<0>(fac0.back()) != pr_least[x]) {
                fac0.emplace_back(pr_least[x], 1);
            } else {
                get<1>(fac0.back())++;
            }
        }

        vector<pii> fac;
        for (auto [p, e] : fac0) if (e % k != 0) {
            fac.emplace_back(p, e % k);
        }

        vector<pii> inv;
        for (auto [p, e] : fac) {
            inv.emplace_back(p, k - e);
        }

        ans += m[inv];
        m[fac]++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; i < kA; i++) {
        if (pr_least[i] == 0) {
            pr_least[i] = i;
            pr.push_back(i);
        }
        for (int p : pr) {
            if (p > pr_least[i] || p * i >= kA) break;
            pr_least[p * i] = p;
        }
    }

    solve();
}