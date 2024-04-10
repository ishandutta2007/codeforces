#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, m, k, inc = 1, ans = 1, l, r;

int main() {
    scanf("%lld %lld %lld", &n, &m, &k);
    l = r = k;

    m -= n;
    while(m >= inc) {
        m -= inc;
        ans++;
        if(l > 1) l--;
        if(r < n) r++;
        if(inc == (r - l + 1)) {
            ans += (m / inc);
            break;
        }
        inc = (r - l + 1);
    }

    printf("%lld\n", ans);
    return 0;
}