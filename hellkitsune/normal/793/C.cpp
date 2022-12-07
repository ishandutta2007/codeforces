#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int x, y, xx, yy;
PII from, to;

inline bool cmp(const PII &lhs, const PII &rhs) {
    int lsgn = (lhs.first == 0 ? 0 : (lhs.first < 0 ? -1 : 1));
    int rsgn = (rhs.first == 0 ? 0 : (rhs.first < 0 ? -1 : 1));
    if (lsgn != rsgn) {
        return lsgn < rsgn;
    }
    return (LL)lhs.first * rhs.second < (LL)rhs.first * lhs.second;
}

void solve(int x, int xx, int st, int v) {
    if (v == 0) {
        if (st <= x || st >= xx) {
            cout << -1 << endl;
            exit(0);
        }
        return;
    }
    if (v > 0) {
        from = max(from, mp(x - st, v), cmp);
        to = min(to, mp(xx - st, v), cmp);
        return;
    }
    from = max(from, mp(st - xx, -v), cmp);
    to = min(to, mp(st - x, -v), cmp);
}

int main() {
    scanf("%d", &n);
    scanf("%d%d%d%d", &x, &y, &xx, &yy);
    from = mp(0, 1);
    to = mp(1000000000, 1);
    forn(i, n) {
        int rx, ry, vx, vy;
        scanf("%d%d%d%d", &rx, &ry, &vx, &vy);
        solve(x, xx, rx, vx);
        solve(y, yy, ry, vy);
    }
    if (cmp(from, to)) {
        printf("%.20f\n", (double)from.first / from.second);
    } else {
        printf("-1\n");
    }
    return 0;
}