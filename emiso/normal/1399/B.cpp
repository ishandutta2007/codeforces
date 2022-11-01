#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN], b[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    ll ma = INT_MAX, mb = INT_MAX;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        ma = min(ma, a[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        mb = min(mb, b[i]);
    }

    ans = 0;
    for(int i = 0; i < n; i++) {
        int qa = a[i] - ma, qb = b[i] - mb;
        ans += max(qa, qb);
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}