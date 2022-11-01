#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, ans, a[MN];
char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %s", &n, s); str = s;

    ll c0 = -1;
    for(int i = 0; i < n; i++) {
        if(str[i] == '0') c0 = i;
    }

    if(c0 == -1) {
        printf("%lld %lld %lld %lld\n", 2LL, n, 1LL, n - 1LL);
    } else if(c0 < n / 2) {
        printf("%lld %lld %lld %lld\n", c0 + 1, n, c0 + 2, n);
    } else {
        printf("%lld %lld %lld %lld\n", 1LL, c0 + 1, 1LL, c0);
    }
    if(--t) goto st;
    return 0;
}