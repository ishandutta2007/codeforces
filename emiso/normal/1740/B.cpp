#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, ans, a[MN], b[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld", &n);

    ll maxh = 0;
    for(int i = 0; i < n; i++) {
        scanf("%lld %lld", &a[i], &b[i]);
        if (a[i] > b[i]) swap(a[i], b[i]);
        ans += 2 * a[i];
        maxh = max(maxh, b[i]);
    }

    printf("%lld\n", ans + 2*maxh);
    if(--t) goto st;
    return 0;
}