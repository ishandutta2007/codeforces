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

#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-10;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ll a, b, c, l;
    cin >> a >> b >> c >> l;
    ll ans = 0;
    for (int i = 0; i <= l; i++) {
        ll x = (b + c - a + i + 1) / 2;
        ll y = (a + c - b + i + 1) / 2;
        ll z = (a + b - c + i + 1) / 2;
        if (x <= 0 || y <= 0 || z <= 0) {
            continue;
        }
        ans += (i + 2) * 1ll * (i + 1) / 2;
        if (x <= i) {
            ans -= (i - x + 2) * 1ll * (i - x + 1) / 2;
        }
        if (y <= i) {
            ans -= (i - y + 2) * 1ll * (i - y + 1) / 2;
        }
        if (z <= i) {
            ans -= (i - z + 2) * 1ll * (i - z + 1) / 2;
        }
    }
    cout << ans << endl;
    return 0;
}