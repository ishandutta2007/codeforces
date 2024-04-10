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

int n, k, cnt = 0;
LL a[4000000];
int nx[4000000], pr[4000000];

struct Cmp {
    bool operator()(const int &lhs, const int &rhs) const {
        LL lval = abs(a[nx[lhs]] - a[lhs]);
        LL rval = abs(a[nx[rhs]] - a[rhs]);
        if (lval != rval) return lval < rval;
        return lhs < rhs;
    }
};

set<int, Cmp> se;

int main() {
    scanf("%d%d", &n, &k);
    REP(i, n) {
        LL x;
        scanf("%I64d", &x);
        if ((cnt == 1 && x <= a[0]) || (cnt > 1 && (x == a[cnt - 1] ||
            (x > a[cnt - 1] && a[cnt - 1] > a[cnt - 2]) || (x < a[cnt - 1] && a[cnt - 1] < a[cnt - 2]))))
            --cnt;
        a[cnt++] = x;
    }
    if (cnt & 1) --cnt;
    LL ans = 0;
    for (int i = 0; i < cnt; i += 2)
        ans += a[i + 1] - a[i];
    REP(i, cnt) {
        nx[i] = i + 1;
        pr[i] = i - 1;
    }
    nx[cnt - 1] = -1;
    pr[0] = -1;
    REP(i, cnt - 1) se.insert(i);
    k = cnt / 2 - k;
    REP(kk, k) {
        int ind = *se.begin();
        if (pr[ind] != -1) se.erase(pr[ind]);
        se.erase(ind);
        se.erase(nx[ind]);
        ans -= abs(a[nx[ind]] - a[ind]);
        if (pr[ind] == -1) {
            if (nx[nx[ind]] != -1) {
                pr[nx[nx[ind]]] = -1;
            }
        } else {
            nx[pr[ind]] = nx[nx[ind]];
            if (nx[nx[ind]] != -1) {
                pr[nx[nx[ind]]] = pr[ind];
                se.insert(pr[ind]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}