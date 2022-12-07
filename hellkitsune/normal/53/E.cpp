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

int n, m, k;
bool g[10][10] = {};
int d[1027][1027];
int pc[1024];

int main() {
    REP(i, 1024) pc[i] = __builtin_popcount(i);
    scanf("%d%d%d", &n, &m, &k);
    REP(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from][to] = g[to][from] = true;
    }
    REP(mask1, 1 << n) REP(mask2, 1 << n) if ((mask1 & mask2) == mask2) {
        if (pc[mask1] == 2 && mask1 == mask2) {
            int u = -1, v;
            REP(i, n) if (mask1 & (1 << i)) {
                if (u == -1) u = i;
                else v = i;
            }
            if (g[u][v]) {
                d[mask1][mask2] = 1;
            } else {
                d[mask1][mask2] = 0;
            }
            continue;
        }
        REP(i, n) if (mask2 & (1 << i)) {
            REP(j, n) if (g[i][j] && !(mask2 & (1 << j)) && (mask1 & (1 << j))) {
                d[mask1][mask2] += d[mask1 ^ (1 << i)][mask2 ^ (1 << i)];
                d[mask1][mask2] += d[mask1 ^ (1 << i)][mask2 ^ (1 << i) ^ (1 << j)];
            }
            break;
        }
    }
    int ans = 0;
    REP(mask, 1 << n) if (pc[mask] == k) {
        ans += d[(1 << n) - 1][mask];
    }
    printf("%d\n", ans);
    return 0;
}