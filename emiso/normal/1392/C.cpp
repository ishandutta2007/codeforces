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

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    ans = 0;
    for(int i = n-1; i >= 0; i--) {
        if(a[i] < a[i-1]) {
            ans += (a[i-1] - a[i]);
        }
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}