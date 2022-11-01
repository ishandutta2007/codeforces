#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, m, ans, lit, maxi = 0;
vector<ll> a;

int main() {
    scanf("%lld %lld", &n, &m);
    a.resize(n + 3);

    a[0] = 0; a[n+1] = m;
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    for(int i = n + 1; i >= 0; i--) {
        if(i <= n) {
            if(i % 2 == 0) lit += (a[i+1] - a[i]);
        }

        if(i % 2 == 0) continue;

        if(i <= n && a[i]+1 != a[i+1]) {
            ll unlit = (m - a[i] - 1) - lit;
            maxi = max(maxi, unlit - lit);
        }
        if(a[i]-1 != a[i-1]) {
            ll unlit = (m - a[i]) - lit;
            maxi = max(maxi, unlit - lit - 1);
        }
    }
    ans = max(lit, lit + maxi);

    printf("%lld\n", ans);
    return 0;
}