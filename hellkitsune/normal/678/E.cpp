#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
double p[18][18];
double d[17][1 << 17];

int main() {
    scanf("%d", &n);
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    REP(i, n) REP(j, n) scanf("%lf", p[n - 1 - i] + (n - 1 - j));
    --n;
    REP(i, n) d[i][(1 << n) - 1] = p[n][i];
    for (int mask = (1 << n) - 2; mask > 0; --mask) {
        REP(i, n) if (mask & (1 << i)) {
            double &res = d[i][mask] = 0;
            REP(j, n) if (!(mask & (1 << j))) {
                int nmask = mask | (1 << j);
                res = max(res, p[i][j] * d[i][nmask] + (1 - p[i][j]) * d[j][nmask]);
            }
        }
    }
    double ans = 0;
    REP(i, n) ans = max(ans, d[i][1 << i]);
    printf("%.15f\n", ans);
    return 0;
}