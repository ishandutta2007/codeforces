#include<bits/stdc++.h>

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
#define rank _rank

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

const int N = 1e5 + 100;

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    int x, y;
    cin >> x >> y;
    if (y > x) {
        cout << -1 << endl;
    } else {
        double ans = 2e9 + 100;
        ans = min(ans, ((double) x + y) / 2.0 / (double) ((x + y) / 2 / y));
        if (x > y) {
            ans = min(ans, ((double) x - y) / 2.0 / (double) ((x - y) / 2 / y));
        }
        if (ans > 2e9 + 50) {
            cout << -1 << endl;
        } else {
            printf("%.18lf", ans);
        }
    }
    return 0;
}