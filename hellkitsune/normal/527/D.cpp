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
int x[200000], w[200000], ord[200000], nx[200000], nw[200000];
const int INF = 1e9 + 5;

bool cmp(const int &lhs, const int &rhs) {
    return x[lhs] < x[rhs];
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", x + i, w + i);
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    REP(i, n) nx[i] = x[ord[i]], nw[i] = w[ord[i]];
    REP(i, n) x[i] = nx[i], w[i] = nw[i];
    int r = -INF, cnt = 0;
    REP(i, n) {
        if (x[i] - w[i] >= r) {
            ++cnt;
            r = x[i] + w[i];
        }
        r = min(r, x[i] + w[i]);
    }
    printf("%d\n", cnt);
    return 0;
}