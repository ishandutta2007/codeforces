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
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

int dp1, dp2;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    int n;

    cin >> n;

    int prev_x = -INF, prev_h = 0;

    for (int i = 0; i < n; i++) {
        int x, h;
        scanf("%d%d", &x, &h);
        int ndp1 = dp1, ndp2 = dp1 + 1;
        if (prev_x + prev_h < x) {
            ndp1 = dp2, ndp2 = dp2 + 1;
        }

        if (prev_x < x - h) {
            ndp1 = max(ndp1, dp1 + 1);
        }
        if (prev_x + prev_h < x - h) {
            ndp1 = max(ndp1, dp2 + 1);
        }

        dp1 = ndp1;
        dp2 = ndp2;

        prev_x = x;
        prev_h = h;
    }

    cout << dp2 << endl;
    return 0;
}