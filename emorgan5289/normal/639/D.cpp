#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const ll N = 2e5+5;
multiset<ll> t;
vector<ll> a[5];
ll l[5], r[5];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, k, b, c; cin >> n >> k >> b >> c;
    b = min(b, 5*c);
    for (ll i = 0; i < n; i++) {
        ll x; cin >> x; t.insert(x);
    }
    for (auto& x : t) a[(x%5+5)%5].pb(x);
    ll ans = inf_ll;
    for (ll w = 0; w < 5; w++) {
        ll s = 0, cnt = 0, px = -inf_ll;
        for (ll i = 0; i < 5; i++)
            l[i] = 0, r[i] = 0;
        for (auto x : t) {
            while ((x%5+5)%5 != w) x++;
            s += (x-px)/5*cnt*b;
            px = x;
            for (ll i = 0; i < 5; i++)
                while (r[i] < a[i].size() && a[i][r[i]] <= x) {
                    s += (x-a[i][r[i]])/5*b + (x-a[i][r[i]])%5*c;
                    r[i]++, cnt++;
                }
            while (cnt > k) {
                pair<ll, ll> z = {-inf_ll, -1};
                for (ll i = 0; i < 5; i++)
                    if (l[i] < r[i])
                        z = max(z, {(x-a[i][l[i]])/5*b + (x-a[i][l[i]])%5*c, i});
                s -= z.first, l[z.second]++;
                cnt--;
            }
            if (cnt == k) ans = min(ans, s);
        }
    }
    cout << ans << "\n";
}