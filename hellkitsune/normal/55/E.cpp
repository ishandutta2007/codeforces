#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const double PI = atan2(0, -1);

int n, q;
int x[100001], y[100001];
int xx, yy;
double ang[200000];

bool cw(int x, int y, int xx, int yy) {
    return (LL)x * yy - (LL)xx * y < 0;
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", x + i, y + i);
    reverse(x, x + n);
    reverse(y, y + n);
    x[n] = x[0], y[n] = y[0];
    scanf("%d", &q);
    REP(i, q) {
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        bool ok = true;
        REP(i, n) if (cw(x[i] - xx, y[i] - yy, x[i + 1] - xx, y[i + 1] - yy)) {
            ok = false;
            break;
        }
        if (!ok) {
            printf("0\n");
            continue;
        }
        REP(i, n) ang[i] = atan2(y[i] - yy, x[i] - xx);
        for (int i = 1; i < n; ++i) if (ang[i] < ang[i - 1]) {
            ang[i] += 2 * PI;
        }
        REP(i, n) ang[n + i] = ang[i] + 2 * PI;
        int j = 0;
        LL ans = (LL)n * (n - 1) * (n - 2) / 6;
        REP(i, n) {
            if (j < i) ++j;
            while (ang[j] - ang[i] < PI) ++j;
            int cnt = j - i - 1;
            if (cnt < 2) continue;
            ans -= (LL)cnt * (cnt - 1) / 2;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}