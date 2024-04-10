#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;

    scanf("%lld", &n);

    ll maxi = 0;
    bool even = false;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (i > 0 && i + 1 < n) {
            even |= (a[i] % 2 == 0);
            ans += (a[i] + 1) / 2;
            maxi = max(maxi, a[i]);
        }
    }

    if (even || (maxi > 1 && n > 3)) printf("%lld\n", ans);
    else puts("-1");
    if(--t) goto st;
    return 0;
}