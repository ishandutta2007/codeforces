#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

const int maxn = 100010;
const long double PI = acos((long double)-1);
int n;
pair<long double, long double> P, p[maxn];

int main() {
    cin >> n >> P.x >> P.y;
    long double mx = 0, mn = 1e18;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y;
        long double d = (p[i].x - P.x) * (p[i].x - P.x) + (p[i].y - P.y) * (p[i].y - P.y);
        mx = max(mx, d), mn = min(mn, d);
    }
    for (int i = 1; i <= n; i++) {
        int j = i % n + 1;
        if (p[i].x == p[j].x) {
            long double l = min(p[i].y, p[j].y), r = max(p[i].y, p[j].y);
            auto calc = [&](long double y) {
                long double x = p[i].x;
                return (x - P.x) * (x - P.x) + (y - P.y) * (y - P.y);
            };
            for (int j = 1; j <= 200; j++) {
                long double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
                long double foo = calc(m1), bar = calc(m2);
                mn = min({mn, foo, bar});
                if (foo > bar) l = m1;
                else r = m2;
            }
        } else {
            long double l = min(p[i].x, p[j].x), r = max(p[i].x, p[j].x);
            long double k = (p[j].y - p[i].y) / (p[j].x - p[i].x);
            auto calc = [&](long double x) {
                long double y = p[i].y + k * (x - p[i].x);
                return (x - P.x) * (x - P.x) + (y - P.y) * (y - P.y);
            };
            for (int j = 1; j <= 200; j++) {
                long double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
                long double foo = calc(m1), bar = calc(m2);
                mn = min({mn, foo, bar});
                if (foo > bar) l = m1;
                else r = m2;
            }
        }
    }
    cout << setprecision(10) << fixed << PI * (mx - mn) << endl;
    return 0;
}