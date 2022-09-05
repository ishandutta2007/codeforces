#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, cl, ce, v, q, l[maxn], e[maxn];

int main() {
    scanf("%d %d %d %d %d", &n, &m, &cl, &ce, &v);
    for (int i = 1; i <= cl; i++) {
        scanf("%d", &l[i]);
    }
    for (int i = 1; i <= ce; i++) {
        scanf("%d", &e[i]);
    }
    scanf("%d", &q);
    while (q--) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int ans = INT_MAX;
        int d = abs(x1 - x2);
        if (x1 == x2) ans = abs(y1 - y2);
        int pos = lower_bound(l + 1, l + cl + 1, y1) - l - 1;
        if (pos >= 1 && pos <= cl) ans = min(ans, abs(y1 - l[pos]) + abs(y2 - l[pos]) + d);
        pos++;
        if (pos >= 1 && pos <= cl) ans = min(ans, abs(y1 - l[pos]) + abs(y2 - l[pos]) + d);
        pos = lower_bound(l + 1, l + cl + 1, y2) - l - 1;
        if (pos >= 1 && pos <= cl) ans = min(ans, abs(y1 - l[pos]) + abs(y2 - l[pos]) + d);
        pos++;
        if (pos >= 1 && pos <= cl) ans = min(ans, abs(y1 - l[pos]) + abs(y2 - l[pos]) + d);
        pos = lower_bound(e + 1, e + ce + 1, y1) - e - 1;
        if (pos >= 1 && pos <= ce) ans = min(ans, abs(y1 - e[pos]) + abs(y2 - e[pos]) + (d + v - 1) / v);
        pos++;
        if (pos >= 1 && pos <= ce) ans = min(ans, abs(y1 - e[pos]) + abs(y2 - e[pos]) + (d + v - 1) / v);
        pos = lower_bound(e + 1, e + ce + 1, y2) - e - 1;
        if (pos >= 1 && pos <= ce) ans = min(ans, abs(y1 - e[pos]) + abs(y2 - e[pos]) + (d + v - 1) / v);
        pos++;
        if (pos >= 1 && pos <= ce) ans = min(ans, abs(y1 - e[pos]) + abs(y2 - e[pos]) + (d + v - 1) / v);
        printf("%d\n", ans);
    }
    return 0;
}