#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

inline ll binpow(ll x, int deg) {
    ll ans = 1;
    while (deg > 0) {
        if (deg & 1)
            ans *= x;
        deg >>= 1;
        x *= x;
    }
    return ans;
}

inline ll root(ll x, int deg) {
    ll ans = (ll)pow((ld)x, ld(1) / deg);
    while (binpow(ans, deg) < x) ++ans;
    while (binpow(ans, deg) > x) --ans;
    return ans;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

map<ll, int> mp;
const ll mod = 998244353;
vector<ll> special, new_special;
ll ans = 1;

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    while (n--) {
        ll x;
        cin >> x;
        ll cur = root(x, 4);
        if (binpow(cur, 4) == x) { mp[cur] += 4; continue; }
        cur = root(x, 3);
        if (binpow(cur, 3) == x) { mp[cur] += 3; continue; }
        cur = root(x, 2);
        if (binpow(cur, 2) == x) { mp[cur] += 2; continue; }
        special.push_back(x);
    }

    int good = 1;
    while (good) {
        good = 0;
        new_special.clear();
        for (ll x : special) {
            int ok = 0;
            for (auto& p : mp) {
                ll y = p.first;
                if (x % y == 0) {
                    ++mp[y];
                    ++mp[x / y];
                    ok = 1;
                    break;
                }
            }
            if (ok)
                good = 1;
            else
                new_special.push_back(x);
        }
        special = new_special;
        for (int i = 0; !good && i < (int)special.size(); ++i) {
            for (int j = i + 1; !good && j < (int)special.size(); ++j) {
                if (special[i] == special[j])
                    continue;
                ll x = gcd(special[i], special[j]);
                if (x > 1) {
                    mp[x] += 2;
                    ++mp[special[j] / x];
                    ++mp[special[i] / x];
                    special.erase(special.begin() + j);
                    special.erase(special.begin() + i);
                    good = 1;
                    break;
                }
            }
        }
    }

    for (auto& p : mp)
        ans = ans * (p.second + 1) % mod;
    sort(all(special));
    for (int i = 0; i < (int)special.size(); ) {
        int j = i;
        while (j < (int)special.size() && special[i] == special[j])
            ++j;
        ans = ans * (j - i + 1) % mod;
        ans = ans * (j - i + 1) % mod;
        i = j;
    }

    cout << ans << endl;
}