#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a, b, t;

bool is_prime(ll x) {
    for(ll i = 2; i * i <= x; i++)
        if(x % i == 0)
            return false;
    return true;
}

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld %lld", &a, &b);
        if(b + 1 == a && is_prime(a+b)) puts("YES");
        else puts("NO");
    }
    return 0;
}