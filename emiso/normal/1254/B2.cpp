#include <bits/stdc++.h>

#define MN 2011000

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

vector<bool> isp(MN, 1);
vector<int> primos, fact;

void crivo() {
    for(int i = 2; i < MN; i++) {
        if(isp[i]) {
            primos.push_back(i);
            for(int j = 2 * i; j < MN; j += i)
                isp[j] = 0;
        }
    }
}

int main() {
    crivo();
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }

    ll x = sum;
    for(int i = 0; 1LL * primos[i] * primos[i] <= x; i++) {
        if(x % primos[i] == 0) {
            ans = min(ans, can(primos[i]));
            while(x % primos[i] == 0) x /= primos[i];
        }
    }
    ans = min(ans, can(x));

    if(ans == LLONG_MAX) puts("-1");
    else printf("%lld\n", ans);
    return 0;
}