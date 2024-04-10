#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, m, ans, a[MN], b[MN], x, maxi[4000200];

int main() {
    scanf("%lld %lld", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for(int i = 0; i < m; i++) {
        scanf("%lld", &b[i]);
    }
    scanf("%lld", &x);

    for(ll l = 0; l < m; l++) {
        ll sum = 0;
        for(ll r = l; r < m; r++) {
            sum += b[r];
            maxi[sum] = max(maxi[sum], (r - l + 1));
        }
    }
    for(int i = 1; i < 4000200; i++)
        maxi[i] = max(maxi[i], maxi[i-1]);

    for(ll l = 0; l < n; l++) {
        ll sum = 0;
        for(ll r = l; r < n; r++) {
            sum += a[r];
            ll other = x / sum;
            ans = max(ans, (r - l + 1) * maxi[min(other, 4000000LL)]);
        }
    }

    printf("%lld\n", ans);
    return 0;
}