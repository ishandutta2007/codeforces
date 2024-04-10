#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, K;

int main() {
    scanf("%lld %lld", &n, &K);
    auto phi = [&](ll n) {
        ll x = n, v = n;
        for (ll i = 2; i * i <= x; i++) if (!(x % i)) {
            v = v / i * (i - 1);
            while (!(x % i)) x /= i;
        }
        if (x > 1) v = v / x * (x - 1);
        return v;
    };
    ll ans = phi(n);
    for (ll k = 2; k <= K; k++) {
        if (!(k % 2)) continue;
        ans = phi(ans);
        if (ans == 1) break;
    }
    printf("%lld\n", ans % 1000000007);
    return 0;
}