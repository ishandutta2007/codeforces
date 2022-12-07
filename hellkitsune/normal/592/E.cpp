#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
typedef long double Double;

int n, c, d;
Double ang[800000];
const Double PI = atan2(Double(0), Double(-1));
const Double EPS = 1e-18;

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &c, &d);
    REP(i, n) {
        int r, w;
        scanf("%d%d", &r, &w);
        Double x = r - c;
        Double y = w - d;
        ang[i] = atan2(y, x);
    }
    sort(ang, ang + n);
    REP(i, n + 3) ang[n + i] = ang[i] + 2 * PI;
    int j = 0;
    LL ans = (LL)n * (n - 1) * (n - 2) / 6;
    int lo = 0, hi = 0;
    REP(i, n) {
        while (ang[j + 1] - ang[i] < PI + EPS) ++j;
        while (ang[lo] - ang[i] < PI - EPS) ++lo;
        while (ang[hi + 1] - ang[i] < PI + EPS) ++hi;
        ans -= (LL)(j - i) * (j - i - 1) / 2;
        ans += (LL)(hi - lo) * (hi - lo + 1) / 2;
    }
    cout << ans << endl;
    return 0;
}