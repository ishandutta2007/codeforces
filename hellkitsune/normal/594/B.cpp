#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const double PI = atan2(0, -1);
int n;
double r, v, s, f, dist;

double solve(double ang) {
    double lo = dist - 1, hi = dist + 1, mid;
    REP(times, 100) {
        mid = 0.5 * (lo + hi);
        double nang = ang - mid;
        if (mid + cos(nang) < dist) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return lo;
}

int main() {
    scanf("%d", &n);
    scanf("%lf%lf", &r, &v);
    v /= r;
    REP(i, n) {
        scanf("%lf%lf", &s, &f);
        dist = 0.5 * (f - s) / r;
        printf("%.12f\n", 2 * min(solve(0.5 * PI), solve(1.5 * PI)) / v);
    }
    return 0;
}