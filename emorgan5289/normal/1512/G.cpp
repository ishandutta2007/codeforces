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
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

const ll N = 1e7+5;
ll c[N], s[N], d[N], p[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fill(c, c+N, -1);
    d[1] = c[1] = 1;
    for (ll i = 2; i < N; i++) {
        if (!d[i]) {
            for (ll x = i; x < N; x *= i)
                for (ll j = x; j < N; j += x)
                    d[j] = x, p[j] = i;
        }
        if (d[i] == i)
            s[i] = (d[i]*p[i]-1)/(p[i]-1);
        else
            min(N, s[i] = s[i/d[i]]*s[d[i]]);
        if (s[i] < N && c[s[i]] == -1) c[s[i]] = i;
    }
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        cout << c[n] << "\n";
    }
}