#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans = LLONG_MAX, a[MN], sum;

ll can(ll k) {
    if(k == 1) return LLONG_MAX;
    ll carry = 0, ret = 0;
    for(int i = 0; i < n; i++) {
        ll x = a[i] + carry;
        if(x > k) x %= k;

        carry = 0;
        if(x < 0) carry = x;
        else if(x <= k / 2) carry += x;
        else carry -= (k - x);

        ret += abs(carry);
        if(ret > ans) break;
    }
    return ret;
}

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }

    for(ll i = 1; i * i <= sum; i++) {
        if(sum % i == 0) {
            ans = min(ans, can(sum / i));
            if(i * i < sum) ans = min(ans, can(i));
        }
    }

    if(ans == LLONG_MAX) puts("-1");
    else printf("%lld\n", ans);
    return 0;
}