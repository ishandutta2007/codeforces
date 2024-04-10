#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN];

int main() {
    scanf("%lld", &t);
    st:

    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) printf("%lld ", abs(a[i]));
        else printf("%lld ", -abs(a[i]));
    } puts("");

    if(--t) goto st;
    return 0;
}