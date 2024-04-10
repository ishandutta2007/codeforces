#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

using namespace std;

ll n, k, l, m;

ll power(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1ll) {
            ans = (ans * a) % m;
        }
        b /= 2;
        a = (a * a) % m;
    }
    return ans;
}

ll get_fib(ll i) {
    ll a = 1, b = 1, c = 1, d = 0;
    ll aa = 1, bb = 0, cc = 0, dd = 1;
    while (i) {
        if (i & 1) {
            ll na = aa * a + bb * c;
            ll nb = aa * b + bb * d;
            ll nc = cc * a + dd * c;
            ll nd = cc * b + dd * d;
            aa = na % m;
            bb = nb % m;
            cc = nc % m;
            dd = nd % m;
        }
        i >>= 1;
        {
            ll na = a * a + b * c;
            ll nb = a * b + b * d;
            ll nc = c * a + d * c;
            ll nd = c * b + d * d;
            a = na % m;
            b = nb % m;
            c = nc % m;
            d = nd % m;
        }
    }
    return cc;
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    cin >> n >> k >> l >> m;

    ll ans = 1 % m;

    for (int i = 0; i < l; i++) {
        bool flag = false;
        if (i < 62 && (k & (1ll << i))) {
            flag = true;
        }
        if (!flag) {
            ans = ans * (get_fib(n + 2)) % m;
        } else {
            ans = ans * (power(2, n) - get_fib(n + 2)) % m;
            ans += m;
            ans %= m;
        }
    }

    for (int i = l; i < 62; i++) {
        if (k & (1ll << i)) {
            ans = 0;
        }
    }

    cout << ans << endl;

    return 0;
}