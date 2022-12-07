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
int h[100000][5], v[100000][5];
LL d[32];
const LL INF = 1e15;
int pos[32][5], tmp[6];

int main() {
    scanf("%d%d", &n, &m);
    REP(i, m - 1) REP(j, n) scanf("%d", h[i] + j);
    REP(i, m) REP(j, n) scanf("%d", v[i] + j);
    REP(mask, 1 << n) {
        REP(j, n) tmp[j] = (mask & (1 << j)) > 0;
        tmp[n] = tmp[0];
        REP(j, n) pos[mask][j] = tmp[j] ^ tmp[j + 1];
    }
    REP(i, 1 << n) d[i] = INF;
    d[(1 << n) - 1] = 0;
    REP(i, m - 1) {
        for (int j = (1 << n) - 1; j >= 0; --j) REP(k, n) if (j & (1 << k)) {
            d[j ^ (1 << k)] = min(d[j ^ (1 << k)], d[j] + h[i][k]);
        }
        REP(j, 1 << n) REP(k, n) if (pos[j][k]) {
            d[j] += v[i + 1][k];
        }
    }
    printf("%I64d\n", d[0]);
    return 0;
}