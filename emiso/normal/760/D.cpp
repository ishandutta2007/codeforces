#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, a[MN], ans[MN], i;

ll search(ll tm) {
    if(tm < 0) return 0;
    ll l = 0, r = i - 1, m;
    while(l < r) {
        m = (l + r + 1) / 2;
        if(a[m] <= tm) l = m;
        else r = m - 1;
    }
    return ans[l];
}

int main() {
    scanf("%lld", &n);

    for(i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);

        ans[i] = search(a[i] - 1) + 20;
        ans[i] = min(ans[i], search(a[i] - 90) + 50);
        ans[i] = min(ans[i], search(a[i] - 1440) + 120);

        printf("%lld\n", ans[i] - ans[i-1]);
    }

    return 0;
}