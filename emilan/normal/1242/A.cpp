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

ll solve() {
    ll n;
    cin >> n;

    vector<ll> f;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            f.push_back(i);
            n /= i;
            for (; n % i == 0; n /= i);
        }
    }
    if (n != 1) f.push_back(n);

    if (f.size() != 1) return 1;
    else return f[0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << solve() << '\n';
}