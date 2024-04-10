#include <bits/stdc++.h>

#define MN 401000

using namespace std;
typedef long long ll;

ll n, ans, a[MN];
int acum[30000100], f[30000100];

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        f[a[i]]++;
    }

    for(int b = 0; b < 25; b++) {
        memset(acum, 0, sizeof acum);
        for(int i = 0; i < n; i++) {
            acum[a[i] % (1 << (b+1))]++;
        }
        for(int i = 1; i < 30000100; i++) {
            acum[i] += acum[i-1];
        }

        ll tot = 0, m = (1 << (b + 1)) - 1;
        for(int i = 1; i < 10000100; i++) {
            if(!f[i]) continue;
            int rem = i % (1 << (b + 1));

            int r = min(m - rem, 30000000LL);
            int l = 0;
            if(rem < (1 << b)) l = (1 << b) - rem;
            l = min(l, r);

            tot += 1LL * f[i] * (acum[r] - (l ? acum[l-1] : 0));
            if(l <= rem && rem <= r) tot -= 1LL * f[i];

            r = min((1 << (b+1)) + m - rem, 30000000LL);
            l = min((1 << (b+1)) + (1 << b) - rem, r);

            tot += 1LL * f[i] * (acum[r] - (l ? acum[l-1] : 0));
            if(l <= rem && rem <= r) tot -= 1LL * f[i];
        }

        assert(tot % 2 == 0);
        if((tot / 2) % 2) ans += (1LL << b);
    }

    printf("%lld\n", ans);
    return 0;
}