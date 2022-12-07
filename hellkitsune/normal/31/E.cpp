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

int n;
string s, ans;
LL d[19][19] = {};
LL mul[18] = {};
int pre[19][19];

int main() {
    cin >> n >> s;
    mul[0] = 1;
    for (int i = 1; i < 18; ++i) mul[i] = mul[i - 1] * 10;
    REP(i, n + 1) REP(j, n + 1) {
        if (i < n) {
            if (d[i + 1][j] <= d[i][j] + (s[i + j] - '0') * mul[n - 1 - i]) {
                d[i + 1][j] = d[i][j] + (s[i + j] - '0') * mul[n - 1 - i];
                pre[i + 1][j] = 0;
            }
        }
        if (j < n) {
            if (d[i][j + 1] <= d[i][j] + (s[i + j] - '0') * mul[n - 1 - j]) {
                d[i][j + 1] = d[i][j] + (s[i + j] - '0') * mul[n - 1 - j];
                pre[i][j + 1] = 1;
            }
        }
    }
    ans.resize(2 * n);
    for (int i = n, j = n; i + j > 0; ) {
        if (pre[i][j] == 0) {
            --i;
            ans[i + j] = 'M';
        } else {
            --j;
            ans[i + j] = 'H';
        }
    }
    cout << ans << endl;
    return 0;
}