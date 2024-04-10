#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const ll N = 3e5+5, B = 62;
ll a[N], m[N];

#define pc __builtin_popcountll
mt19937 randint(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    ll s = 0, k = 0, r = (1ll<<B)-1;
    for (ll i = 0; i < n; i++)
        cin >> a[i] >> m[i], s += a[i];
    s /= abs(s);
    bool f = 0;
    for (ll i = 0; i < B; i++) {
        ll x = 0; r ^= 1ll<<i;
        for (ll j = 0; j < n; j++)
            if ((r&m[j]) == 0)
                x += a[j]*(pc(k&m[j])&1 ? -1 : 1);
        if (x != 0) f = 1;
        if (x*s > 0 || x == 0 && f) k ^= 1ll<<i;
    }
    cout << k << "\n";
}