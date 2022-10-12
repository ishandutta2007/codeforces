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

ll f[1000];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, t; cin >> n >> t;
    string s; cin >> s;
    t -= 1ll<<(s.back()-'a'); s.pop_back();
    t += 1ll<<(s.back()-'a'); s.pop_back();
    debug(vector(f, f+26), t);
    for (auto& x : s) {
        f[x-'a']++;
        t += 1ll<<(x-'a');
    }
    debug(vector(f, f+26), t);
    if (t&1 > 0 || t < 0) cout << "No\n", exit(0);
    t /= 2;
    ll l = t, r = t;
    ll j = 0;
    for (ll i = 0; i < 60; i++) {
        debug(i, f[i], t);
        if (t&1) f[i]--, t--;
        if (f[i] < 0) cout << "No\n", exit(0);
        if (t == 0) cout << "Yes\n", exit(0);
        f[i+1] += f[i]/2;
        t /= 2;
    }
    while (1) {}
}