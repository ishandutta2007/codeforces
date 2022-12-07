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

int n, k, a;
int m;
bool b[200002] = {};
int x[200000];

int main() {
    scanf("%d%d%d%d", &n, &k, &a, &m);
    REP(i, m) scanf("%d", x + i), --x[i];
    int lo = 0, hi = m + 1, mid;
    b[n] = true;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        REP(i, mid) b[x[i]] = true;
        int cur = 0;
        for (int beg = 0; beg < n; ) if (!b[beg]) {
            int end = beg + 1;
            while (!b[end]) ++end;
            cur += (end - beg + 1) / (a + 1);
            beg = end;
        } else {
            ++beg;
        }
        if (cur >= k) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
        REP(i, mid) b[x[i]] = false;
    }
    if (lo == m + 1) printf("-1\n");
    else printf("%d\n", lo);
    return 0;
}