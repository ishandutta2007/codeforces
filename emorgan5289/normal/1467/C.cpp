#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

ll n[3], s[3], m[3];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n[0] >> n[1] >> n[2];
    m[0] = m[1] = m[2] = inf_ll;
    for (int i = 0; i < 3; i++)
        while (n[i]--) {
            ll x; cin >> x;
            s[i] += x, cmin(m[i], x);
        }
    vector<ll> opt = {m[0]+m[2], m[1]+m[2], m[0]+m[1], s[0], s[1], s[2]};
    cout << s[0]+s[1]+s[2]-2**min_element(all(opt)) << "\n";
}