#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int main() {
    ll t, a, m;
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld %lld", &a, &m);
        ll g = __gcd(a, m);
        a /= g; m /= g;
        printf("%lld\n", phi(m));
    }
}