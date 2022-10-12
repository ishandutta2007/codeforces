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
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

#define pc __builtin_popcount

unordered_map<ll, ll> m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll k; cin >> k;
    vector<vector<ll>> a(k);
    vector<ll> n(k), s(k), ss(1<<k);
    ll sum = 0;
    for (ll i = 0; i < k; i++) {
        cin >> n[i];
        a[i].resize(n[i]);
        for (ll j = 0; j < n[i]; j++) {
            cin >> a[i][j];
            s[i] += a[i][j];
            m[a[i][j]] = i;
        }
        sum += s[i];
    }
    if (sum%k != 0)
        cout << "No\n", exit(0);
    for (ll i = 0; i < k; i++) {
        s[i] -= sum/k;
        ss[1<<i] = s[i];
    }
    for (ll i = 0; i < 1<<k; i++)
        if (pc(i) > 1) ss[i] = ss[i&-i]+ss[i-(i&-i)];
    vector<vector<ll>> ch(1<<k);
    for (auto& [x, i] : m) {
        ll y = 1<<i;
        bool ok = 1;
        vector<ll> v = {x};
        for (ll z = x-s[i]; z != x; z = z-s[m[z]]) {
            v.pb(z);
            if (!m.count(z) || y&(1<<m[z])) {
                ok = 0; break;
            }
            y |= 1<<m[z];
        }
        if (ok) ch[y] = v;
    }
    vector<ll> dp(1<<k);
    for (ll i = 0; i < 1<<k; i++) {
        if (ss[i] == 0 && ch[i].size() == pc(i))
            dp[i] = 1;
        for (ll j = i; j > 0; j = (j-1)&i)
            dp[i] = dp[i] || (dp[j] && dp[i^j]);
    }
    if (!dp[(1<<k)-1])
        cout << "No\n", exit(0);
    cout << "Yes\n";
    ll x = (1<<k)-1;
    vector<array<ll, 2>> ans(k);
    while (x > 0) {
        for (ll y = x; y > 0; y = (y-1)&x)
            if (ss[y] == 0 && ch[y].size() == pc(y) && dp[x^y]) {
                x = x^y;
                for (ll i = 0; i < ch[y].size(); i++) {
                    ll j = (i+1)%ch[y].size();
                    ans[m[ch[y][j]]] = {ch[y][j], m[ch[y][i]]+1};
                }
            }
    }
    for (ll i = 0; i < k; i++)
        cout << ans[i][0] << " " << ans[i][1] << "\n";
}