#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ll m, b, ans = 0; scanf("%lld%lld", &m, &b);
    for (ll x = 0; b >= 0; x += m, b--)
        ans = max(ans, (x + 1) * (b + 1) * (x + b) / 2);
    printf("%lld", ans);
    return 0;
}