#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    ans = 0;
    for(ll a = 3;; a += 2) {
        ll b = a * a / 2, c = b + 1;
        if(c > n) break;
        ans++;
        assert(a*a + b*b == c*c);
        assert(a*a == b + c);
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}