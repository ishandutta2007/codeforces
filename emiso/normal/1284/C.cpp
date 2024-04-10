#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, m, ans, f[MN];

int main() {
    scanf("%lld %lld", &n, &m);

    f[0] = 1;
    for(ll i = 1; i <= n; i++)
        f[i] = f[i-1] * i % m;

    for(ll len = 1; len <= n; len++) {
        ans += (n - len + 1) * (n - len + 1) % m * f[n-len] % m * f[len] % m;
        if(ans >= m) ans -= m;
    }

    printf("%lld\n", ans % m);
    return 0;
}