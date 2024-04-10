#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, x, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &n, &x);

    ll l = INT_MAX, r = INT_MIN;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        l = min(l, a[i]);
        r = max(r, a[i]);
        if (l + x + x < r) {
            ans++;
            l = r = a[i];
        }
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}