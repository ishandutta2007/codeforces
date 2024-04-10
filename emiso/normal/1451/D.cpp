#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, k, d, ans, a[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld", &d, &k);

    ll l = 1, r = 2 * (d + k - 1) / k, m;
    while(l < r) {
        m = (l + r + 1) / 2;
        if((m/2) * k * (m/2) * k + ((m+1)/2)*k*((m+1)/2)*k <= d * d) l = m;
        else r = m - 1;
    }

    if(l % 2 == 0) puts("Utkarsh");
    else puts("Ashish");

    if(--t) goto st;
    return 0;
}