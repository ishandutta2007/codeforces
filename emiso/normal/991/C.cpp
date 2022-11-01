#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, ans;

bool ok(ll n, ll k) {
    ll quant = 0, N = n;
    while(n) {
        if(n <= k) {
            quant += n;
            n = 0;
            break;
        }

        quant += k;
        n -= k;
        n -= n / 10;
    }

    return 2 * quant >= N;
}

int main() {
    scanf("%lld", &n);

    ll l = 1, r = n, m;
    while(l < r) {
        m = (l + r) / 2;
        if(ok(n, m)) r = m;
        else l = m + 1;
    }

    printf("%lld\n", l);
    return 0;
}