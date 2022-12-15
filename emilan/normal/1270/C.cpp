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

const ll kBig = 1LL << 50;

vector<ll> solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    ll sum = accumulate(ALL(a), 0LL);
    if (sum == 0) return {};
    a.push_back(kBig - sum);

    ll xum = accumulate(ALL(a), 0LL, bit_xor());
    a.push_back((2 * xum ^ kBig) / 2);
    a.push_back((2 * xum ^ kBig) / 2);

    return {a[n], a[n + 1], a[n + 2]};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        auto ans = solve();
        cout << SZ(ans) << '\n';
        for (auto x : ans) cout << x << ' ';
        cout << '\n';
    }
}