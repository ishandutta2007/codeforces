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

int n, l, r, x;
int c[15];

int main() {
    scanf("%d%d%d%d", &n, &l, &r, &x);
    REP(i, n) scanf("%d", c + i);
    int ans = 0;
    REP(mask, 1 << n) {
        int mn = 1e9, mx = -1e9, sum = 0, cnt = 0;
        REP(i, n) if (mask & (1 << i)) {
            mn = min(mn, c[i]);
            mx = max(mx, c[i]);
            sum += c[i];
            ++cnt;
        }
        if (cnt > 1 && sum >= l && sum <= r && mx - mn >= x) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}