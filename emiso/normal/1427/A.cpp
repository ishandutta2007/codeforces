#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    int pos = 0, neg = 0;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if(a[i] >  0) pos += a[i];
        else neg += a[i];
    }
    if(pos > abs(neg)) sort(a, a + n, greater<ll>());
    else sort(a, a + n);

    if(pos + neg == 0) puts("NO");
    else {
        puts("YES");
        for(int i = 0; i < n; i++) printf("%lld ", a[i]);
        puts("");
    }
    if(--t) goto st;
    return 0;
}