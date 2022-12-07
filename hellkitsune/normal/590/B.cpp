#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
typedef long double Double;

int x, y, xx, yy, v, t;
int vx, vy, wx, wy;

int main() {
    scanf("%d%d%d%d%d%d", &x, &y, &xx, &yy, &v, &t);
    scanf("%d%d%d%d", &vx, &vy, &wx, &wy);
    Double lo = 0, hi = 1e20, mid;
    REP(times, 500) {
        mid = 0.5 * (lo + hi);
        Double posx, posy;
        if (mid > t) {
            posx = x + vx * t;
            posy = y + vy * t;
            posx += wx * (mid - t);
            posy += wy * (mid - t);
        } else {
            posx = x + vx * mid;
            posy = y + vy * mid;
        }
        Double dist = sqrt((posx - xx) * (posx - xx) + (posy - yy) * (posy - yy));
        if (dist <= v * mid) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    printf("%.18f\n", (double)lo);
    return 0;
}