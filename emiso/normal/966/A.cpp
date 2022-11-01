#include <bits/stdc++.h>

#define MN 1001000
#define debug(args...) for(auto x : {args}) cerr << x << " "; cerr << endl;
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

ll n, m, cl, ce, v, x, x1_, y1_, x2_, y2_, q;
vector<int> stairs, elevs;

int main() {
    scanf("%lld %lld %lld %lld %lld", &n, &m, &cl, &ce, &v);

    for(int i = 0; i < cl; i++) {
        scanf("%lld", &x);
        stairs.push_back(x);
    }

    for(int i = 0; i < ce; i++) {
        scanf("%lld", &x);
        elevs.push_back(x);
    }

    scanf("%lld", &q);
    while(q--) {
        scanf("%lld %lld %lld %lld", &y1_, &x1_, &y2_, &x2_);
        ll ans = 99999999999999LL;

        if(y1_ == y2_) ans = abs(x1_ - x2_);
        else {
            ll l = lower_bound(stairs.begin(), stairs.end(), x1_) - stairs.begin();

            if(l < stairs.size()) {
                ans = min(ans, abs(x1_ - stairs[l]) + abs(x2_ - stairs[l]) + abs(y1_ - y2_));
            }
            if(l > 0) {
                ans = min(ans, abs(x1_ - stairs[l-1]) + abs(x2_ - stairs[l-1]) + abs(y1_ - y2_));
            }

            l = lower_bound(elevs.begin(), elevs.end(), x1_) - elevs.begin();
            if(l < elevs.size()) {
                ans = min(ans, abs(x1_ - elevs[l]) + abs(x2_ - elevs[l]) + abs(y1_ - y2_) / v + (abs(y1_ - y2_) % v != 0));
            }
            if(l > 0) {
                ans = min(ans, abs(x1_ - elevs[l-1]) + abs(x2_ - elevs[l-1]) + abs(y1_ - y2_) / v + (abs(y1_ - y2_) % v != 0));
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}