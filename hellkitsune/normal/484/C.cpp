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

char s[1000005], t[1000005];
int n, m;
PII pos[1000000];
int d[21][1000001];
int f[1000001];

int main() {
    scanf("%s%d", s, &m);
    n = strlen(s);
    t[n] = '\0';
    REP(query, m) {
        int k, dd;
        scanf("%d%d", &k, &dd);
        REP(i, k) pos[i] = mp(i % dd, i);
        sort(pos, pos + k);
        REP(i, k) d[0][pos[i].second + 1] = i;
        d[0][0] = 0;
        int mx = 1;
        while ((1 << mx) <= n - k + 1) ++mx;
        for (int z = 1; z < mx; ++z) REP(i, k + 1)
            d[z][i] = d[z - 1][d[z - 1][i]];
        REP(i, n) {
            int x0 = min(i, k - 1);
            int fi = max(0, i - k + 1);
            int cnt = n - k + 1 - fi;
            int x = x0 + 1;
            int j;
            for (j = 0; (1 << j) <= cnt; ++j) if (cnt & (1 << j))
                x = d[j][x];
            if (x == 0) {
                x = x0 + 1;
                cnt = 0;
                for (--j; j >= 0; --j) if (d[j][x] != 0) {
                    x = d[j][x];
                    cnt |= 1 << j;
                }
                f[i] = fi + cnt;
            } else {
                f[i] = n - k + x;
            }
        }
        REP(i, n) t[f[i]] = s[i];
        REP(i, n) s[i] = t[i];
        printf("%s\n", s);
    }
    return 0;
}