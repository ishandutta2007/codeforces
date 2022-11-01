#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n;

ll qr(int pos) {
    if(pos <= 0 || pos > n) return 123456789LL;
    printf("? %lld\n", pos); fflush(stdout);
    ll ret;
    scanf("%lld", &ret);
    return ret;
}

int main() {
    scanf("%lld", &n);

    ll l = 1, r = n, m;
    while(l < r) {
        m = (l + r) / 2;
        if(qr(m) < qr(m + 1)) r = m;
        else l = m + 1;
    }

    printf("! %lld\n", l); fflush(stdout);
    return 0;
}