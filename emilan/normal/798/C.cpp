#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for (int i = 0; (i) < n; (i)++)
#define SZ(a)       int(size(a))
#define ALL(a)      begin(a), end(a)
#define RALL(a)     rbegin(a), rend(a)

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using ld = long double;
using pii = pair<int, int>;

int solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int g_ = accumulate(ALL(a), 0, gcd<int, int>);
    if (g_ > 1) return 0;

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        while (a[i] & 1) {
            tie(a[i], a[i + 1]) =
                pair{a[i] - a[i + 1], a[i] + a[i + 1]};
            ans++;
        }
    }
    if (a[n - 1] & 1) ans += 2;
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "YES\n";
    cout << solve() << '\n';
}