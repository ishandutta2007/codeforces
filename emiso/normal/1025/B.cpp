#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN], b[MN], c[MN];

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld %lld", &a[i], &b[i]);
        c[i] = a[i] / __gcd(a[i], b[i]) * b[i];

        if(i) ans = __gcd(ans, c[i]);
        else ans = c[i];
    }

    if(ans == 1) {
        printf("-1\n");
        return 0;
    }

    for(int i = 0; i < n; i++) {
        int g = __gcd(a[i], ans);
        if(g > 1) {
            ans = g;
        } else {
            ans = __gcd(b[i], ans);
        }
    }

    assert(ans > 1);
    printf("%lld\n", ans);
    return 0;
}