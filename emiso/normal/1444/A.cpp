#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, p, q;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld", &p, &q);

    if(p % q) {
        printf("%lld\n", p);
    } else {
        vector<pair<ll, ll>> v;
        ll tmp = q;
        for(ll i = 2; i * i <= tmp; i++) {
            if(tmp % i == 0) {
                int cnt = 0;
                ll pot = 1;
                while(tmp % i == 0) {
                    tmp /= i;
                    cnt++;
                    pot *= i;
                }
                v.emplace_back(i, pot / i);
            }
        }
        if(tmp > 1) v.emplace_back(tmp, 1);

        ll ans = 0;
        for(auto tt : v) {
            tmp = p;
            while(tmp % tt.first == 0) tmp /= tt.first;
            tmp *= tt.second;
            ans = max(ans, tmp);
        }
        printf("%lld\n", ans);
    }

    if(--t) goto st;
    return 0;
}