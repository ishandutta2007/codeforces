#include <iostream>

using namespace std;

using ll = long long;
const __int128 MOD = 1e9 + 7;

__int128 sum(__int128 l) {
    l %= MOD;
    return l * (l + 1) / 2;
}

__int128 seg_sum(__int128 l, __int128 r) {
    if (l > r) {
        return 0;
    }
    return ((sum(r) - sum(l - 1)) % MOD + MOD) % MOD;
}

int main() {
    __int128 n, m;
    ll x, y;
    cin >> x >> y;
    n = x;
    m = y;
    // a % b = a - (a / b) * b;
    __int128 sum1 = n % MOD * m % MOD;
    __int128 sum2 = 0;
    for (__int128 frac = 1; frac * frac <= n; ++frac) {
        __int128 l = n / (frac + 1) + 1;
        __int128 r = n / frac;
        r = min(r, m);
        sum2 += seg_sum(l, r) * frac;
        sum2 %= MOD;
    }
    for (__int128 b = 1; b * b < n && b <= m; ++b) {
        __int128 val = n / b;
        if (val * __int128(1) * val >= n) {
            sum2 += n / b % MOD * b % MOD;
            sum2 %= MOD;
        }
    }
    cout << ll(((sum1 - sum2) % MOD + MOD) % MOD);
    return 0;
}