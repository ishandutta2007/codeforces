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

int n, m, b, mod;
int a[500];
int d[501][501] = {};

int main() {
    scanf("%d%d%d%d", &n, &m, &b, &mod);
    REP(i, n) scanf("%d", a + i);
    d[0][0] = 1;
    REP(z, n) {
        int cnt = a[z];
        REP(i, m) for (int j = 0; j <= b - cnt; ++j) {
            int &x = d[i + 1][j + cnt];
            x += d[i][j];
            if (x >= mod) x -= mod;
        }
    }
    int ans = 0;
    REP(i, b + 1) {
        ans += d[m][i];
        if (ans >= mod) ans -= mod;
    }
    printf("%d\n", ans);
    return 0;
}