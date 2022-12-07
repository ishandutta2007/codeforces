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

int n;
int x[200000], y[200000];
int ord[200000];
vector<int> hull;
int eq[200000];
bool ans[200000] = {};

bool cmp(const int &lhs, const int &rhs) {
    if (x[lhs] != x[rhs]) return x[lhs] > x[rhs];
    return y[lhs] < y[rhs];
}

bool ccw(LL x, LL y, LL xx, LL yy, LL xxx, LL yyy) {
    return (x - xx) * (yy - yyy) * y * xxx - (y - yy) * (xx - xxx) * x * yyy >= 0;
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", x + i, y + i);
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    REP(i, n) eq[i] = -1;
    for (int beg = 0; beg < n; ) {
        int end = beg + 1;
        while (end < n && x[ord[beg]] == x[ord[end]] && y[ord[beg]] == y[ord[end]]) ++end;
        for (int i = beg + 1; i < end; ++i) {
            eq[ord[i]] = ord[beg];
        }
        beg = end;
    }
    REP(ind, n) {
        int i = ord[ind];
        if (eq[i] != -1) continue;
        if (hull.empty()) {
            hull.pb(i);
        } else if ((int)hull.size() == 1) {
            if (x[hull[0]] == x[i]) {
                hull[0] = i;
            } else if (y[hull[0]] < y[i]) {
                hull.pb(i);
            }
        } else if (y[hull.back()] < y[i]) {
            int sz = (int)hull.size();
            while (sz > 1 && !ccw(x[hull[sz - 2]], y[hull[sz - 2]], x[hull[sz - 1]], y[hull[sz - 1]], x[i], y[i]))
                --sz;
            hull.resize(sz);
            hull.pb(i);
        }
    }
    for (int x : hull) ans[x] = true;
    REP(i, n) if (eq[i] != -1) {
        ans[i] = ans[eq[i]];
    }
    REP(i, n) if (ans[i]) printf("%d ", i + 1);
    printf("\n");
    return 0;
}