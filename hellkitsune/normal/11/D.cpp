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

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
LL d[1 << 19][19] = {};
int cnt[1 << 19] = {}, low[1 << 19] = {};
bool g[19][19] = {};
LL ans = 0;

int main() {
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int x, y;
        scanf("%d%d", &x, &y), --x, --y;
        g[x][y] = g[y][x] = true;
    }
    REP(i, 1 << n) {
        REP(j, n) if (i & (1 << j)) {
            low[i] = j;
            cnt[i] = cnt[i ^ (1 << j)] + 1;
            break;
        }
    }
    REP(i, n) d[1 << i][i] = 1;
    REP(i, 1 << n) for (int j = low[i] + 1; j < n; ++j) if ((i & (1 << j)) == 0) {
        REP(k, n) if (g[k][j])
            d[i | (1 << j)][j] += d[i][k];
    }
    REP(i, 1 << n) if (cnt[i] >= 3) {
        REP(j, n) if ((i & (1 << j)) && g[low[i]][j])
            ans += d[i][j];
    }
    cout << ans / 2 << endl;
    return 0;
}