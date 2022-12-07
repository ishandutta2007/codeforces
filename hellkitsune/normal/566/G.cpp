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

int n, m, t;
PII a[100000], b[100000], h[200001];
double ang[100000];
int sz = 0;

inline bool cw(PII &a, PII &b, PII &c) {
    return LL(b.first - a.first) * (c.second - b.second) - LL(b.second - a.second) * (c.first - b.first) < 0;
}

inline bool ccw(PII &a, PII &b, PII &c) {
    return LL(b.first - a.first) * (c.second - b.second) - LL(b.second - a.second) * (c.first - b.first) > 0;
}

inline LL s(int x, int y, int xx, int yy) {
    return (LL)x * yy - (LL)xx * y;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &t, &t);
    REP(i, n) scanf("%d%d", &a[i].first, &a[i].second);
    REP(i, m) scanf("%d%d", &b[i].first, &b[i].second);
    sort(b, b + m);
    m = unique(b, b + m) - b;
    for (int i = 0; i < m; h[sz++] = b[i++]) {
        for (; sz > 1 && !cw(h[sz - 2], h[sz - 1], b[i]); --sz);
    }
    REP(i, sz) ang[i] = atan2(h[i].second, h[i].first);
    REP(i, n) {
        double cur = atan2(a[i].second, a[i].first);
        if (cur >= ang[0]) {
            if (a[i].second >= h[0].second) {
                printf("Max\n");
                return 0;
            }
        } else if (cur <= ang[sz - 1]) {
            if (a[i].first >= h[sz - 1].first) {
                printf("Max\n");
                return 0;
            }
        } else {
            int ind = lower_bound(ang, ang + sz, cur, greater<double>()) - ang - 1;
            if (ind == sz - 1) --ind;
            if (ind == -1) ++ind;
            if (!ccw(h[ind], a[i], h[ind + 1])) {
                printf("Max\n");
                return 0;
            }
        }
    }
    printf("Min\n");
    return 0;
}