#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = 1e9+10;
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

template<typename it1, typename it2>
void fixedrangermq(it1 first, it1 last, it2 result, int width) {
    int n = distance(first, last);
    vector p(first, last), s(first, last);
    for (int i = n-1; i >= 0; i--)
        if (i%width != width-1 && i != n-1) s[i] = min(s[i], s[i+1]);
    for (int i = 0; i < n; i++)
        if (i%width) p[i] = min(p[i], p[i-1]);
    for (int i = 0; i <= n-width; i++, result++)
        *result = min(s[i], p[i+width-1]);
}

const ll N = 1e5+5;
ll a[N], dp[N], r[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, c; cin >> n >> c;
    ll ans = 0;
    for (ll i = 0; i < n; i++)
        cin >> a[i], ans += a[i];
    if (c > n) cout << ans << "\n", exit(0);
    fixedrangermq(a+0, a+n, r, c);
    for (ll i = c; i <= n; i++)
        dp[i] = max(dp[i-1], dp[i-c]+r[i-c]);
    cout << ans-dp[n] << "\n";
}