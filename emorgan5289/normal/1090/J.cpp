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

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string a, b; cin >> a >> b;
    ll n = a.size(), m = b.size();
    auto z = z_function(b+"$"+a);

    // x[i] = number of times prefix of b of length i appears in a[1..]
    vector<ll> x(m+1);
    for (ll i = 1; i < n; i++)
        x[z[m+i+1]]++;
    for (ll i = m-1; i >= 0; i--)
        x[i] += x[i+1];

    // y[i] = largest j such that there exists a k <= j such that y[k..j] == y[0..j-k] or something
    vector<ll> y(m+1);
    for (ll i = 1; i < m; i++)
        y[i] = max(y[i-1], i+z[i]);

    ll ans = n*m;
    for (ll i = 1; i <= m; i++)
        ans -= x[i] * min((ll)z[i], max(0ll, i+z[i]-y[i-1]));
    cout << ans << "\n";
}