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

int n, a[1000001][21] = {};

const int MOD = 1e9 + 7;

int p[1000001];

int main() {
    scanf("%d", &n);
    REP(i, n) {
        int x;
        scanf("%d", &x);
        ++a[x][0];
    }
    for (int i = 1000000; i > 0; --i) {
        REP(j, 20) if (a[i][j]) {
            for (int k = j; (1 << k) <= i; ++k) if ((1 << k) & i)
                a[i ^ (1 << k)][k + 1] += a[i][j];
        }
    }
    REP(i, 1000001) for (int j = 1; j <= 20; ++j)
        a[i][0] += a[i][j];
    p[0] = 1;
    for (int i = 1; i <= 1000000; ++i)
        p[i] = (p[i - 1] << 1) % MOD;
    LL ans = (p[n] - 1) % MOD;
    for (int i = 1; i <= 1000000; ++i) {
        if (a[i][0] == 0) continue;
        int cnt = 0;
        for (int j = 1; j <= i; j <<= 1) if (i & j) ++cnt;
        if (cnt & 1) {
            ans = (ans + MOD - p[a[i][0]] + 1) % MOD;
        } else
            ans = (ans + p[a[i][0]] - 1) % MOD;
    }
    cout << ans << endl;
    return 0;
}