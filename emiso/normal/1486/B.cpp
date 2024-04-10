#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, x[MN], y[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld %lld", &x[i], &y[i]);
    }
    sort(x, x + n);
    sort(y, y + n);

    if(n % 2) puts("1");
    else printf("%lld\n", (x[n/2] - x[n/2-1] + 1) * (y[n/2] - y[n/2-1] + 1));
    if(--t) goto st;
    return 0;
}