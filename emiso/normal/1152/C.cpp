#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll a, b, dif, ansk, anslcm = LLONG_MAX;
vector<ll> dv;

int main() {
    scanf("%lld %lld", &a, &b);
    if(a > b) swap(a, b);

    dif = b - a;
    for(ll i = 1; i * i <= dif; i++) {
        if(dif % i == 0) {
            dv.push_back(i);
            if(i * i < dif) dv.push_back(dif / i);
        }
    }

    for(ll d : dv) {
        ll k = (a + d - 1) / d * d - a, lcm;
        lcm = (a + k) / __gcd(a + k, b + k) * (b + k);
        if(lcm < anslcm || (lcm == anslcm && k < ansk)) {
            ansk = k;
            anslcm = lcm;
        }
    }

    printf("%lld\n", ansk);
    return 0;
}