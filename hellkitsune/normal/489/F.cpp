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

int d[505][505] = {}, d2[505][505];
int cnt[505] = {};
int dd[505];
string s;
int n, m, MOD;
int c0 = 0, c1 = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> MOD;
    REP(i, m) {
        cin >> s;
        REP(j, n) if (s[j] == '1')
            ++cnt[j];
    }
    REP(i, n) if (cnt[i] == 0)
        ++c0;
    else if (cnt[i] == 1)
        ++c1;
    d[c0][c1] = 1;
    REP(i, 505) dd[i] = (i * (i - 1)) >> 1;
    for (int k = n - m; k > 0; ) {
        memset(d2, 0, sizeof d2);
        for (int i = 0; i <= k; ++i) {
            int mx = (k - i) << 1;
            for (int j = 0; j <= mx; ++j) if (d[i][j]) {
                if (i && j) d2[i - 1][j] = (d2[i - 1][j] + d[i][j] * (LL)i * j) % MOD;
                if (i > 1) d2[i - 2][j + 2] = (d2[i - 2][j + 2] + d[i][j] * (LL)dd[i]) % MOD;
                if (j > 1) d2[i][j - 2] = (d2[i][j - 2] + d[i][j] * (LL)dd[j]) % MOD;
            }
        }
        --k;
        for (int i = 0; i <= k; ++i) {
            int mx = (k - i) << 1;
            for (int j = 0; j <= mx; ++j)
                d[i][j] = d2[i][j];
        }
    }
    cout << d[0][0] << '\n';
    return 0;
}