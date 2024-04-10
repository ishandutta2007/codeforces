#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, p, k, x, y, ans, a[MN], quant[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld %lld", &n, &p, &k);

    for(int i = 1; i <= n; i++) {
        scanf("%1lld", &a[i]);
    }
    scanf("%lld %lld", &x, &y);

    ans = INT_MAX;
    for(int i = n; i >= p; i--) {
        quant[i] = (a[i] == 0) * x + quant[i + k];
        ans = min(ans, quant[i] + (i - p) * y);
    }

    printf("%lld\n", ans);
    for(int i = 0; i <= n; i++) {
        quant[i] = 0;
    }
    if(--t) goto st;
    return 0;
}