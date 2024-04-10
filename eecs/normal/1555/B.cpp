#include <bits/stdc++.h>
using namespace std;

int T, w, h, x1, y1, x2, y2, x, y;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &w, &h);
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d %d", &x, &y);
        int ans = INT_MAX;
        if (x + x2 - x1 <= w) ans = min(ans, max(0, x - x1));
        if (x + x2 - x1 <= w) ans = min(ans, max(0, x2 - (w - x)));
        if (y + y2 - y1 <= h) ans = min(ans, max(0, y - y1));
        if (y + y2 - y1 <= h) ans = min(ans, max(0, y2 - (h - y)));
        if (ans == INT_MAX) puts("-1");
        else printf("%d\n", ans);
    }
    return 0;
}