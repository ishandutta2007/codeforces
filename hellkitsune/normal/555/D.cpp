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

int n, m;
int x[200000], ord[200000], rev[200000];

bool cmp(const int &lhs, const int &rhs) {
    return x[lhs] < x[rhs];
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%d", x + i);
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    REP(i, n) rev[ord[i]] = i;
    sort(x, x + n);
    REP(i, m) {
        int pos, len;
        scanf("%d%d", &pos, &len), --pos;
        pos = rev[pos];
        int p = -1;
        int j = 0;
        int cnt = 0;
        while (true) {
            int ppos;
            if (j == 0) {
                ppos = (upper_bound(x, x + n, x[pos] + len) - x) - 1;
            } else {
                ppos = lower_bound(x, x + n, x[pos] - len) - x;
            }

            if (ppos != pos) cnt = 0;
            if (ppos == pos && ++cnt == 2) {
                printf("%d\n", ord[pos] + 1);
                break;
            } else if (ppos == p) {
                int times = len / abs(x[pos] - x[p]);
                if (times & 1) {
                    p = pos;
                    pos = ppos;
                    j ^= 1;
                }
                len %= abs(x[pos] - x[p]);
                continue;
            }
            len -= abs(x[pos] - x[ppos]);
            p = pos;
            pos = ppos;

            j ^= 1;
        }
    }
    return 0;
}