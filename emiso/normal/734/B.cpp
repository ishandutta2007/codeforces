#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a, b, c, d, ans = 0;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

    long long a256 = min(a, min(c,d));

    a -= a256;
    c -= a256;
    d -= a256;
    ans += a256 * 256;

    ans += min(a, b)* 32;

    printf("%lld\n", ans);

    return 0;
}