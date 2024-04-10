#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

using namespace std;
typedef long long ll;

ll n, p, q, b;

int main() {
    scanf("%lld", &n);

    while(n--) {
        scanf("%lld %lld %lld", &p, &q, &b);

        ll g = __gcd(p, q);
        p = p / g;
        q = q / g;

        g = __gcd(q, b);
        while(g != 1) {
            while(q % g == 0) q /= g;
            g = __gcd(q, b);
        }

        printf("%s\n", (q > 1) ? "Infinite" : "Finite");
    }

    return 0;
}