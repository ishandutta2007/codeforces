#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN], h1;
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:

    ans = 0;
    h1 = 0;
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        ans += a[i];
        h1 |= (a[i] == 1);
    }

    if(ans % 2 == 1) puts("NO");
    else  {
        if(ans % 4 == 0) puts("YES");
        else if(h1) puts("YES");
        else puts("NO");
    }
    if(--t) goto st;
    return 0;
}