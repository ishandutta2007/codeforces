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
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

double a, b, c, d, na, nb, nc, nd;

int main() {
    cin >> na >> nc >> nd >> nb;
    double ans = 1e20;
    REP(mask, 16) {
        int x, y, z, t;
        if (mask & 1) x = 1;
        else x = -1;
        if (mask & 2) y = 1;
        else y = -1;
        if (mask & 4) z = 1;
        else z = -1;
        if (mask & 8) t = 1;
        else t = -1;
        if (x * y != z * t) continue;

        double ca, cb, cc, cd;
        a = na, b = nb, c = nc, d = nd;
        if (mask & 1) ca = max(0.0, -a), a = max(0.0, a);
        else ca = max(0.0, a), a = min(0.0, a);
        if (mask & 2) cb = max(0.0, -b), b = max(0.0, b);
        else cb = max(0.0, b), b = min(0.0, b);
        if (mask & 4) cc = max(0.0, -c), c = max(0.0, c);
        else cc = max(0.0, c), c = min(0.0, c);
        if (mask & 8) cd = max(0.0, -d), d = max(0.0, d);
        else cd = max(0.0, d), d = min(0.0, d);
        a = abs(a);
        b = abs(b);
        c = abs(c);
        d = abs(d);
        if (a * b > c * d) swap(a, c), swap(b, d), swap(ca, cc), swap(cb, cd);

        double cur = max(ca, cb);
        cur = max(cur, cc);
        cur = max(cur, cd);
        double lo = cur, hi = min(c + cc, d + cd), mid;
        if (lo < hi) REP(i, 300) {
            mid = (lo + hi) / 2;
            if ((a + mid - ca) * (b + mid - cb) > (c - mid + cc) * (d - mid + cd))
                hi = mid;
            else
                lo = mid;
        }

        ans = min(ans, lo);
    }
    printf("%.12f\n", ans);
    return 0;
}