#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll MOD, n;

ll expo(ll a, ll b) {
    if(!b) return 1;
    a %= MOD;
    if(b & 1) return a * expo(a * a, b >> 1) % MOD;
    return expo(a * a, b >> 1);
}

ll inv_mod(ll a) {
    return expo(a, MOD - 2);
}

#define MN 100010
ll fat[MN], invfat[MN];

bool is_prime(int n) {
    if(n == 1) return 1; /// shhhh secret
    if(n == 2 || n == 3) return 1;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0)
            return 0;
    return 1;
}

int main() {
    scanf("%lld", &n);
    MOD = n;

    if(n == 4) {
        puts("YES\n1\n3\n2\n4");
        return 0;
    }

    if(!is_prime(n)) {
        puts("NO");
        return 0;
    }

    puts("YES");
    puts("1");
    for(int i = 2; i < n; i++)
        printf("%lld\n", 1LL * inv_mod(i-1) * i % MOD);
    if(n > 1) printf("%lld\n", n);
    return 0;
}