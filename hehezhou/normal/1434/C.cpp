#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if (1ll * b * c < a) {
            puts("-1");
            continue;
        }
        ll r = 1ll * b * d;
        ll rr = r + 2 * a;
        ll a1 = rr / r / 2, a2 = a1 + 1;
        a1 = a1 * a1 * r - a1 * rr, a2 = a2 * a2 * r - a2 * rr;
        printf("%lld\n", -min(a1, a2) / 2);
    }
}