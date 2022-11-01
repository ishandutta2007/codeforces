#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a, b, n, s, a1, b1;
// 1000000000 77400 77400

int main() {
    scanf("%lld %lld %lld", &n, &a, &b);

    if(a*b >= 6LL*n) {s = a*b, a1 = a, b1 = b;}
    else for(s = 6LL*n; ; s++) {
        for(ll d = min(a, b); d * d <= s; d++) {
            if(s % d == 0) {
                if(d >= a && (s / d) >= b) {
                    printf("%lld\n%lld %lld\n", s, d, s/d);
                    return 0;
                }
                if((s / d) >= a && d >= b) {
                    printf("%lld\n%lld %lld\n", s, s/d, d);
                    return 0;
                }
            }
        }
    }

    printf("%lld\n%lld %lld\n", s, a1, b1);
    return 0;
}