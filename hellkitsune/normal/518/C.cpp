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

int n, m, k;
int a[100000], pos[100000];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    REP(i, n) scanf("%d", a + i), --a[i];
    REP(i, n) pos[a[i]] = i;
    LL ans = 0;
    REP(i, m) {
        int x;
        scanf("%d", &x), --x;
        ans += pos[x] / k + 1;
        int cur = pos[x];
        if (cur > 0) {
            swap(a[cur], a[cur - 1]);
            pos[a[cur - 1]] = cur - 1;
            pos[a[cur]] = cur;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}