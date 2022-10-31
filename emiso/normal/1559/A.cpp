#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
		ans = (i == 0) ? a[0] : (ans & a[i]);
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}