#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, m, r, c, ans, a[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld %lld %lld", &n, &m, &r, &c);

    ans = 0;
    for(ll x : vector<ll>{1, n})
        for(ll y : vector<ll>{1, m})
            ans = max(ans, abs(r - x) + abs(c - y));

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}