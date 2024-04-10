#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, k, ans, a[MN];
//char s[MN]; string str;

int ok(ll m) {
    ll sum = a[0] + m;
    for(int i = 1; i < n; i++) {
        if(a[i] * 100LL > k * sum) return false;
        sum += a[i];
    }
    return true;
}

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld", &n, &k);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    ll l = 0, r = 1234567890123456LL, m;
    while(l < r) {
        m = (l + r) / 2;
        if(ok(m)) r = m;
        else l = m + 1;
    }

    printf("%lld\n", l);
    if(--t) goto st;
    return 0;
}