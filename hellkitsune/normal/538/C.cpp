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
int d[100000], h[100000];

int main() {
    ios_base::sync_with_stdio(false);
    scanf("%d%d", &n, &m);
    REP(i, m) scanf("%d%d", d + i, h + i);
    int mx = 0;
    REP(i, m - 1) {
        int dif = abs(d[i] - d[i + 1]) - abs(h[i] - h[i + 1]);
        if (dif < 0) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
        mx = max(mx, max(h[i], h[i + 1]) + dif / 2);
    }
    mx = max(mx, h[0] + d[0] - 1);
    mx = max(mx, h[m - 1] + n - d[m - 1]);
    printf("%d\n", mx);
    return 0;
}