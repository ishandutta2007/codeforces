#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

#define y1 my1

using namespace std;

double x1, y1, x2, y2;
double vmax, tchange, vx, vy, wx, wy;

int main()
{
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
    scanf("%lf%lf", &vmax, &tchange);
    scanf("%lf%lf%lf%lf", &vx, &vy, &wx, &wy);
    double L = 0, R = 1e15;
    for (int it = 0; it < 200; it++) {
        double mid = (L + R) / 2;
        double curx = x1 + vx * min(tchange, mid), cury = y1 + vy * min(tchange, mid);
        curx += max(0.0, mid - tchange) * wx;
        cury += max(0.0, mid - tchange) * wy;
        double dx = x2 - curx;
        double dy = y2 - cury;
        if (dx * dx + dy * dy < mid * mid * vmax * vmax) {
            R = mid;
        } else {
            L = mid;
        }
    }
    printf("%.18f", L);
    return 0;
}