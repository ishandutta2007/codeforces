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

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a, a + n);

    for(int i = 1; i + 1 < n; i++) {
        ans = max(ans, a[i] - a[i-1] + a[n-1] - a[i-1]);
        ans = max(ans, a[i+1] - a[i] + a[i+1] - a[0]);
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}