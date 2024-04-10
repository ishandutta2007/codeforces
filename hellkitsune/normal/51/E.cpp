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

int n, m;
bool g[700][700] = {};
int deg[700] = {};
int cnt[700][700];

int main() {
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from][to] = true;
        g[to][from] = true;
        ++deg[from];
        ++deg[to];
    }
    if (n < 5) {
        printf("0\n");
        return 0;
    }
    LL pent = 0, triPlus = 0, tri = 0;
    REP(i, n) for (int j = i + 1; j < n; ++j) {
        int sum = 0;
        REP(k, n) if (g[i][k] && g[j][k]) ++sum;
        cnt[i][j] = cnt[j][i] = sum;
    }
    REP(i, n) for (int j = i + 1; j < n; ++j) if (g[i][j]) REP(k, n) if (k != i && k != j) {
        pent += cnt[i][k] * cnt[j][k];
    }
    REP(i, n) for (int j = i + 1; j < n; ++j) if (g[i][j]) {
        REP(k, n) if (g[i][k] && g[j][k]) {
            triPlus += deg[k] - 2;
            ++tri;
        }
    }
    LL ans = pent - 3 * triPlus - tri;
    assert(ans % 5 == 0);
    ans /= 5;
    cout << ans << endl;
    return 0;
}