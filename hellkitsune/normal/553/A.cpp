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

int k;
int c[1005][1005] = {};
const int MOD = 1e9 + 7;

int main() {
    REP(i, 1005) c[0][i] = 0;
    c[0][0] = 1;
    for (int i = 1; i < 1005; ++i) {
        c[i][0] = 1;
        for (int j = 1; j < 1005; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            if (c[i][j] >= MOD) c[i][j] -= MOD;
        }
    }
    scanf("%d", &k);
    LL ans = 1;
    int n = 0;
    REP(i, k) {
        int x;
        scanf("%d", &x);
        ans = (ans * c[n + x - 1][x - 1]) % MOD;
        n += x;
    }
    cout << ans << endl;
    return 0;
}