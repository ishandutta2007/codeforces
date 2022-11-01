#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, m, ans, a[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld", &n, &m);

    if(n < m) swap(n, m);
    ans = n + m;
    ans += max(n - m - 1, 0LL);

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}