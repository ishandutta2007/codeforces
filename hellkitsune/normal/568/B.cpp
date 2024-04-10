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

int n;
int d[4005];
const int MOD = 1e9 + 7;
int c[4005][4005];

int main() {
    scanf("%d", &n);
    REP(i, 4005) c[0][i] = 0;
    c[0][0] = 1;
    for (int i = 1; i < 4005; ++i) {
        c[i][0] = 1;
        for (int j = 1; j < 4005; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            if (c[i][j] >= MOD) c[i][j] -= MOD;
        }
    }
    d[0] = 1;
    for (int i = 1; i <= n; ++i) {
        d[i] = 0;
        REP(j, i) d[i] = (d[i] + (LL)d[j] * c[i - 1][j]) % MOD;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = (ans + (LL)d[n - i] * c[n][i]) % MOD;
    }
    printf("%d\n", ans);
    return 0;
}