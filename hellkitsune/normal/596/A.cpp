#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int x, y, xx, yy, n;

int main() {
    scanf("%d", &n);
    scanf("%d%d", &x, &y), xx = x, yy = y;
    REP(i, n - 1) {
        int a, b;
        scanf("%d%d", &a, &b);
        x = min(x, a);
        xx = max(xx, a);
        y = min(y, b);
        yy = max(yy, b);
    }
    if (x == xx || y == yy) printf("-1\n");
    else printf("%d\n", (xx - x) * (yy - y));
    return 0;
}