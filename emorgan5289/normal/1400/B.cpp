#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        ll p, f; cin >> p >> f;
        ll cs, cw; cin >> cs >> cw;
        ll s, w; cin >> s >> w;
        ll ans = 0;
        if (s > w) swap(s, w), swap(cs, cw);
        for (ll i = 0; i <= cs; i++) {
            ll ps = min(i, p/s), fs = min(cs-i, f/s);
            ll pw = (p-ps*s)/w, fw = (f-fs*s)/w;
            ans = max(ans, ps+fs+min(cw, pw+fw));
        }
        cout << ans << "\n";
    }
}