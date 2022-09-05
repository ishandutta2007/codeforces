#include <bits/stdc++.h>
#define y1 asd
using namespace std;

int n, x1, y1, x2, y2;

int main() {
    scanf("%d %d %d %d %d", &n, &x1, &y1, &x2, &y2);
    long double l = 0, r = 1e18;
    while (n--) {
        int rx, ry, vx, vy;
        scanf("%d %d %d %d", &rx, &ry, &vx, &vy);
        if (!vx) {
            if (rx <= x1 || rx >= x2) puts("-1"), exit(0);
        } else {
            // rx + k * vx > x1; rx + k * vx < x2
            if (vx > 0) {
                if (rx >= x2) puts("-1"), exit(0);
                l = max(l, (long double)(x1 - rx) / vx);
                r = min(r, (long double)(x2 - rx) / vx);
            } else {
                if (rx <= x1) puts("-1"), exit(0);
                l = max(l, (long double)(x2 - rx) / vx);
                r = min(r, (long double)(x1 - rx) / vx);
            }
        }
        if (!vy) {
            if (ry <= y1 || ry >= y2) puts("-1"), exit(0);
        } else {
            if (vy > 0) {
                if (ry >= y2) puts("-1"), exit(0);
                l = max(l, (long double)(y1 - ry) / vy);
                r = min(r, (long double)(y2 - ry) / vy);
            } else {
                if (ry <= y1) puts("-1"), exit(0);
                l = max(l, (long double)(y2 - ry) / vy);
                r = min(r, (long double)(y1 - ry) / vy);
            }
        }
    }
    if (l + 1e-11 > r) puts("-1");
    else printf("%.9Lf\n", l);
    return 0;
}