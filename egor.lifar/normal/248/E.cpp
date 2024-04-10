#include <iostream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <cassert>
#include <bitset>
#include <string.h>


using namespace std;


const int MaxN = 100001;
const int MaxP = 101;
int n, q;
double dp[MaxN][MaxP];
long long cnt[1000001][6];
int s[MaxN];
double b[MaxP];


void updateDP(int u, int v, int k) {
    memset(b, 0, sizeof(b));
    for (int i = 0; i < MaxP; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            b[i - j] += dp[u][i] * cnt[i][j] * cnt[s[u] - i][k - j] / cnt[s[u]][k];
        }
    }
    for (int i = 0; i < MaxP; i++) {
        dp[u][i] = b[i];
    }
    s[u] -= k;
    s[v] += k;
}


int main() {
    memset(cnt, 0, sizeof(cnt));
    cnt[0][0] = 1;
    for (int i = 1; i <= 1000000; i++) {
        for (int j = 0; j <= min(5, i); j++) {
            if (j == 0 || j == i) {
                cnt[i][j] = 1;
            } else {
                cnt[i][j] = cnt[i - 1][j - 1] + cnt[i - 1][j];
            }
        }
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0;i < n;i++) {
        dp[i][s[i]] = 1;
    }
    scanf("%d", &q);
    double ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dp[i][0];
    }
    for (int i = 0; i < q; i++) {
        int u, v, k;
        scanf("%d %d %d", &u, &v, &k);
        u--;
        v--;
        double res = dp[u][0];
        updateDP(u, v, k);
        ans += dp[u][0] - res;
        printf("%.15lf\n", ans);
    }
    return 0;
}