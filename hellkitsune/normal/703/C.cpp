#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, w, v, u;
int x[10000], y[10000];

int main() {
    scanf("%d%d%d%d", &n, &w, &v, &u);
    forn(i, n) scanf("%d%d", x + i, y + i);
    bool ok = true;
    forn(i, n) {
        if ((LL)x[i] * u - (LL)y[i] * v < 0) {
            ok = false;
            break;
        }
    }
    double ans = (double)w / u;
    if (ok) {
        printf("%.12f\n", ans);
        return 0;
    }
    double mx = 0;
    forn(i, n) {
        double xx = (x[i] - (double)y[i] * v / u);
        mx = max(mx, xx);
    }
    ans += mx / v;
    printf("%.12f\n", ans);
    return 0;
}