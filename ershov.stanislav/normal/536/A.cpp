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

ll a, b;
int n;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    cin >> a >> b >> n;
    for (int i = 0; i < n; i++) {
        ll l, t, m;
        scanf(LLD" "LLD" "LLD, &l, &t, &m);
        ll l1 = l;
        ll r = 1700000;
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            if (max(a + b * (mid - 1),
                    ((a + b * (l1 - 1) + a + b * (mid - 1)) * (mid - l1 + 1) / 2 + m - 1) / m)
                        <= t) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (max(a + b * (l - 1),
                    ((a + b * (l1 - 1) + a + b * (l - 1)) * (l - l1 + 1) / 2 + m - 1) / m)
                        <= t) {
            printf(LLD"\n", l);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}