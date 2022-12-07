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
int a[100][100];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    if (n >= m) {
        REP(i, n) REP(j, m) scanf("%d", a[i] + j);
    } else {
        REP(i, n) REP(j, m) scanf("%d", a[j] + i);
        swap(n, m);
    }
    if (n > k) {
        int best = 10005;
        REP(i, n) {
            int tot = 0;
            REP(j, n) {
                int cnt = 0;
                REP(q, m) cnt += a[i][q] == a[j][q];
                tot += min(cnt, m - cnt);
            }
            best = min(best, tot);
        }
        if (best > k) best = -1;
        printf("%d\n", best);
    } else {
        int best = 10005;
        REP(mask, 1 << m) {
            int tot = 0;
            REP(i, n) {
                int cnt = 0;
                REP(j, m) cnt += a[i][j] == ((mask & (1 << j)) > 0);
                tot += min(cnt, m - cnt);
            }
            best = min(best, tot);
        }
        if (best > k) best = -1;
        printf("%d\n", best);
    }
    return 0;
}