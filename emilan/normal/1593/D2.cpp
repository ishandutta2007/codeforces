#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for (int i = 0; (i) < (n); (i)++)
#define REP1(i, n)  for (int i = 1; (i) <= (n); (i)++)
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

const int kA = 1e6;

int solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x, x += kA;

    sort(ALL(a));
    if (count(ALL(a), a[0]) >= n / 2) return -1;
    if (count(ALL(a), a[n / 2]) >= n / 2) return -1;

    int ans = 1;
    for (int s : a) for (int t : a) {
        int x = abs(t - s);
        auto f = [&](int d) {
            auto pred = [&](int z) { return z % d == s % d; };
            if (count_if(ALL(a), pred) >= n / 2) ans = max(ans, d);
        };
        for (int d = 1; d * d <= x; d++) if (x % d == 0) {
            f(d);
            f(x / d);
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        cout << solve() << '\n';
    }
}