#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll k, d, s, ans;

int main() {
    scanf("%lld %lld %lld", &k, &d, &s);
    s <<= 1;
    ll t = (k / d + (k % d ? 1 : 0)) * d;
    ll tx = k * 2 + t - k;
    ans += s / tx * t;
    s %= tx;
    if (s <= k * 2) {
        if (s & 1) printf("%lld.5\n", ans + (s >> 1));
        else printf("%lld.0\n", ans + (s >> 1));
    } else {
        s -= k * 2;
        printf("%lld.0", ans + k + s);
    }
    return 0;
}