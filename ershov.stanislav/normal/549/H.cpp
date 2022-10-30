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

double a, b, c, d;

double get_min(double a, double b, double d) {
    double ans = a * b;
    ans = min(ans, (a - d) * (b + d));
    ans = min(ans, (a + d) * (b + d));
    ans = min(ans, (a - d) * (b - d));
    ans = min(ans, (a + d) * (b - d));
    return ans;
}
double get_max(double a, double b, double d) {
    double ans = a * b;
    ans = max(ans, (a - d) * (b + d));
    ans = max(ans, (a + d) * (b + d));
    ans = max(ans, (a - d) * (b - d));
    ans = max(ans, (a + d) * (b - d));
    return ans;
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    cin >> a >> b >> c >> d;

    double L = 0, R = max(abs(a), abs(b)) + 10;
    for (int i = 0; i < 300; i++) {
        double mid = (L + R) / 2;
        if (get_max(a, d, mid) - get_min(b, c, mid) >= 0 && get_min(a, d, mid) - get_max(b, c, mid) <= 0) {
            R = mid;
        } else {
            L = mid;
        }
    }
    printf("%.10lf", L);
    return 0;
}