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

int n, m, mx;
int a[111111];

bool check(ll val) {
    if (val == 4) {
//        cout << "fgergfwe";
    }
    ll r = 0;
    ll mm = m;
    if (mx >= val) {
        return false;
    }
    for (ll i = n; i >= 1; i--) if (a[i] != 0) {
        ll b = a[i];
        ll c = min(b, r);
        b -= c;
        r -= c;
        ll q = (b + val - i - 1) / (val - i);
        if (q > mm) {
            return false;
        }
        mm -= q;
        r += q * (val - i) - b;
    }
    return true;
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", a + i + 1);
        if (a[i + 1] != 0) {
            mx = i + 1;
        }
    }

    ll L = -1, R = 1e18 + 1e8;

    while (R - L > 1) {
        ll mid = (L + R) / 2;
        if (check(mid) == true) {
            R = mid;
        } else {
            L = mid;
        }
    }

    cout << L + 1 << endl;

    return 0;
}