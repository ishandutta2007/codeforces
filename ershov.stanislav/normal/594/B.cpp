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

using namespace std;

const int maxn = 5e5 + 100;
const double PI = acos(-1);

int n;
double r, v;

int main() {
#ifdef LOCAL
    freopen("text.in", "r", stdin);
#endif
    scanf("%d%lf%lf", &n, &r, &v);
    for (int i = 0; i < n; i++) {
        double s, f;
        scanf("%lf%lf", &s, &f);
        double dist = f - s;
        double ans = floor(dist / 2 / PI / r) * 2 * PI * r / v;
        dist -= floor(dist / 2 / PI / r) * 2 * PI * r;
        double L = 0, R = PI;
        for (int t = 0; t < 100; t++) {
            double mid = (L + R) / 2;
            if ((mid + sin(mid)) * r > dist / 2) {
                R = mid;
            } else {
                L = mid;
            }
        }
        ans += r / v * L * 2;
        printf("%.18f\n", ans);
    }
    return 0;
}