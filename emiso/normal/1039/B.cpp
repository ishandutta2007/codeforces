#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, k;

bool ok(ll l, ll r) {
    printf("%lld %lld\n", l, r);
    fflush(stdout);

    char ret[10];
    scanf("%s", ret);

    if(ret[0] == 'Y' && l == r) exit(0);
    return ret[0] == 'Y';
}

int main() {
    srand(time(NULL));
    scanf("%lld %lld", &n, &k);

    ll l = 1, r = n;
    while(1) {
        ll sz = r - l + 1;
        if(sz <= 50) {
            ll rnd = 1LL * rand() * rand() % sz;
            ok(l + rnd, l + rnd);
            l = max(1LL, l - k);
            r = min(n, r + k);
        } else {
            ll m = (l + r) / 2;
            if(ok(l, m)) {
                l = max(1LL, l - k);
                r = min(n, m + k);
            } else {
                l = max(1LL, m + 1 - k);
                r = min(n, r + k);
            }
        }
    }

    return 0;
}