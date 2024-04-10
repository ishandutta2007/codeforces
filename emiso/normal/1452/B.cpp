#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    ll sc = 0, maxi = 0;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sc += a[i];
        maxi = max(maxi, a[i]);
    }

    ll v = max(maxi, (sc+n-2)/(n-1));
    ans = v * (n-1) - sc;

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}