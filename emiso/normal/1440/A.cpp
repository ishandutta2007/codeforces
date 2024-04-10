#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, c0, c1, h, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld %lld %lld", &n, &c0, &c1, &h);

    ans = 0;
    for(int i = 0; i < n; i++) {
        scanf("%1lld", &a[i]);
        if(a[i] == 0) {
            if(h < c0 - c1) a[i] = 1, ans += h;
        }
        else if(a[i] == 1) {
            if(h < c1 - c0) a[i] = 0, ans += h;
        }
        ans += (a[i] == 0) * c0 + (a[i] == 1) * c1;
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}