#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, ax, ay, bx, by;
int x[2000], y[2000];

LL d(int x, int y) {
    return (LL)x * x + (LL)y * y;
}

int main() {
    scanf("%d%d%d%d%d", &n, &ax, &ay, &bx, &by);
    REP(i, n) scanf("%d%d", x + i, y + i);
    LL ans = 0;
    REP(i, n) ans = max(ans, d(bx - x[i], by - y[i]));
    REP(i, n) {
        LL dist = d(ax - x[i], ay - y[i]);
        LL dist2 = 0;
        REP(j, n) if (d(ax - x[j], ay - y[j]) > dist) {
            dist2 = max(dist2, d(bx - x[j], by - y[j]));
        }
        ans = min(ans, dist + dist2);
    }
    cout << ans << endl;
    return 0;
}