#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, a, b, x, ans;

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld %lld %lld", &a, &b, &x);

        ans = INT_MAX;

        ans = min(ans, (1 + x - a + b - 1) / b);
        ans = min(ans, (1 + x - b + a - 1) / a);

        ll tmp = 0, t = 0, ta = a, tb = b;
        while(ta <= x && tb <= x) {
            if(t == 0) {
                ta += tb;
            } else {
                tb += ta;
            }
            tmp++;
            t = 1 - t;
        }
        ans = min(ans, tmp);

        tmp = 0, t = 1, ta = a, tb = b;
        while(ta <= x && tb <= x) {
            if(t == 0) {
                ta += tb;
            } else {
                tb += ta;
            }
            tmp++;
            t = 1 - t;
        }

        ans = min(ans, tmp);
        printf("%lld\n", ans);
    }

    return 0;
}