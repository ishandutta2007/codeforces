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

const ll kMod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<ll> pow2(n + 1, 1);
    REP(i, n) pow2[i + 1] = pow2[i] * 2 % kMod;

    array<int, 30> freq = {};
    for (int x : a) freq[__builtin_ctz(x)]++;

    int suf = accumulate(begin(freq) + 1, end(freq), 0);
    ll ans = (pow2[freq[0]] - 1) * pow2[suf] % kMod;
    REP1(i, 29) {
        suf -= freq[i];
        if (freq[i] >= 2) {
            ans = (ans + (pow2[freq[i] - 1] - 1) * pow2[suf]) % kMod;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}