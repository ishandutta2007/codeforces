#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/2)
#define MAXN 2000

typedef long long lint;

using namespace std;

double dp[MAXN+1][MAXN+1];
int usedr[MAXN+1], usedc[MAXN+1];

int main(int argc, char ** argv)
{
        int n, m;

        scanf("%d %d", &n, &m);

        dp[0][0] = 0.0;
        for (int nr = 0; nr <= n; nr++)
                for (int nc = 0; nc <= n; nc++) {
                        if (nr == 0 && nc == 0) continue;

                        double up = 0;
                        if (nr > 0)
                                up += (1.0 * nr/n) * (1 - 1.0 * nc/n) * dp[nr-1][nc];
                        if (nc > 0)
                                up += (1 - 1.0 * nr/n) * (1.0 * nc/n) * dp[nr][nc-1];
                        if (nr > 0 && nc > 0)
                                up += (1.0 * nr/n) * (1.0 * nc/n) * dp[nr-1][nc-1];

                        dp[nr][nc] = (1 + up) / (1.0 - (1 - 1.0 * nr/n) * (1 - 1.0 * nc/n));
                }

        memset(usedr, 0, sizeof(usedr));
        memset(usedc, 0, sizeof(usedc));

        for (int i = 0; i < m; i++) {
                int r, c;
                scanf("%d %d", &r, &c); r--, c--;
                usedr[r] = 1;
                usedc[c] = 1;
        }

        int fr = n - accumulate(usedr, usedr+n, 0);
        int fc = n - accumulate(usedc, usedc+n, 0);

        printf("%.10f\n", dp[fr][fc]);

        return 0;
}