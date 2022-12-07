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

int n, q;
int a[2000000];
int r[2000000];

int go(int st) {
    int ret = 0;
    for (int cur = st; cur < n + st; cur = r[cur])
        ++ret;
    return ret;
}

int solve(LL mx) {
    int l = 0;
    LL cur = a[0];
    int from = 0, to = n - 1;
    for (int rr = 1; rr < 2 * n; ++rr) {
        cur += a[rr];
        bool flag = l > 0 && l < n;
        while (cur > mx) {
            r[l] = rr;
            if (flag && r[l] - l < to - from) {
                from = l;
                to = r[l];
            }
            flag = false;
            cur -= a[l++];
        }
    }
    for (int i = l; i < 2 * n; ++i)
        r[i] = 2 * n;
    int ans = go(from);
    for (int st = from + 1; st < to; ++st)
        ans = min(ans, go(st % n));
    return ans;
}

int main() {
    scanf("%d%d", &n, &q);
    REP(i, n) scanf("%d", a + i);
    REP(i, n) a[n + i] = a[i];
    REP(i, q) {
        LL x;
        scanf("%I64d", &x);
        printf("%d\n", solve(x));
    }
    return 0;
}