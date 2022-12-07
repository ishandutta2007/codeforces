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
LL a[4000000], b[4000000];
int nx[4000000], pr[4000000];

struct Cmp {
    bool operator()(const int &lhs, const int &rhs) const {
        if (b[lhs] != b[rhs]) return b[lhs] < b[rhs];
        return lhs < rhs;
    }
};

set<int, Cmp> se;

priority_queue<LL, vector<LL>, greater<LL> > q;

const int MASK = (1 << 22) - 1;

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
    REP(i, cnt - 1) b[i] = abs(a[i + 1] - a[i]);
    REP(i, cnt - 1) q.push((b[i] << 22) | i);
    k = cnt / 2 - k;
    REP(kk, k) {
        int ind = q.top() & MASK;
        LL val = q.top() >> 22;
        q.pop();
        if (b[ind] != val) {
            ++k;
            continue;
        }
        ans -= val;
        b[ind] = b[nx[ind]] = -1;
        if (pr[ind] == -1) {
            if (nx[nx[ind]] != -1) {
                pr[nx[nx[ind]]] = -1;
            }
        } else {
            nx[pr[ind]] = nx[nx[ind]];
            if (nx[nx[ind]] != -1) {
                pr[nx[nx[ind]]] = pr[ind];
                b[pr[ind]] = abs(a[nx[nx[ind]]] - a[pr[ind]]);
                q.push((b[pr[ind]] << 22) | pr[ind]);
            } else {
                b[pr[ind]] = -1;
            }
        }
    }
    printf("%I64d\n", ans);
    return 0;
}