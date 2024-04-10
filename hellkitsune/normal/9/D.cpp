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

int n, h;
LL d[36][36][36] = {};

int main() {
    cin >> n >> h;
    for (int i = 1; i <= n; ++i)
        d[1][i][i] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) for (int k = j; k <= n; ++k) {
            d[i][j][k] = (j == k) ? 0 : (d[i - 1][j + 1][k] + d[i - 1][j][k - 1]);
            for (int p = j + 1; p < k; ++p) {
                for (int q = 0; q < i - 1; ++q) {
                    d[i][j][k] += d[i - 1][j][p - 1] * d[q][p + 1][k];
                    d[i][j][k] += d[q][j][p - 1] * d[i - 1][p + 1][k];
                }
                d[i][j][k] += d[i - 1][j][p - 1] * d[i - 1][p + 1][k];
            }
        }
    }
    LL ans = 0;
    for (int i = h; i <= n; ++i)
        ans += d[i][1][n];
    cout << ans << endl;
    return 0;
}