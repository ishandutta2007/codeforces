#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ll MOD = 1000000007LL;
map<int,int> mp;
pii a[200005];
int ai;

ll binpow(ll x, ll deg) {
    ll ans = 1;
    while (deg) {
        if (deg & 1LL) (ans *= x) %= MOD;
        (x *= x) %= MOD;
        deg >>= 1LL;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int m, x;
    cin >> m;
    while (m--) {
        cin >> x;
        ++mp[x];
    }
    for (map<int,int>::iterator it = mp.begin(); it != mp.end(); ++it)
        a[++ai] = *it;

    ll ans = 1;
    ll d = 1;
    ll cur;
    for (int i = 1; i <= ai; ++i) {
        cur = binpow(a[i].first, a[i].second * (a[i].second + 1LL) / 2LL);
        ans = (binpow(ans, a[i].second + 1) * binpow(cur, d)) % MOD;
        d = (d * (a[i].second + 1)) % (MOD - 1);
    }
    cout << ans;

    return 0;
}