#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN], res;

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if(i) {
            ll x = min(res, a[i] / 2);
            ans += x;
            a[i] -= 2 * x;
            res -= x;
        }
        ans += (a[i] / 3);
        res += (a[i] % 3);
    }

    printf("%lld\n", ans);
    return 0;
}