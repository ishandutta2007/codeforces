#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, k, a, b, l[4], mi, ma;

int main() {
    scanf("%lld %lld %lld %lld", &n, &k, &a, &b);
    mi = n*k;
    ma = 1;

    l[0] = a + b;
    l[1] = 2*k - a - b;
    l[2] = k - a + b;
    l[3] = a + k - b;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 4; j++) {
            ll x = n*k / __gcd(n*k, i*k + l[j]);
            mi = min(mi, x);
            ma = max(ma, x);
        }
    }

    printf("%lld %lld\n", mi, ma);
    return 0;
}