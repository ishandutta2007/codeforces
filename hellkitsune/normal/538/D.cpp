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
string s[50];
string ans[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> s[i];
    REP(i, 2 * n - 1) ans[i].resize(2 * n - 1, '.');
    ans[n - 1][n - 1] = 'o';
    for (int i = -(n - 1); i <= n - 1; ++i) for (int j = -(n - 1); j <= n - 1; ++j) if (i != 0 || j != 0) {
        bool flag = true;
        REP(x, n) if (flag) REP(y, n) if (s[x][y] == 'o') {
            int xx = x + i;
            int yy = y + j;
            if (xx < 0 || xx >= n) continue;
            if (yy < 0 || yy >= n) continue;
            if (s[xx][yy] == '.') {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans[i + n - 1][j + n - 1] = 'x';
            REP(x, n) REP(y, n) if (s[x][y] == 'o') {
                int xx = x + i;
                int yy = y + j;
                if (xx < 0 || xx >= n) continue;
                if (yy < 0 || yy >= n) continue;
                if (s[xx][yy] != 'o') s[xx][yy] = 'v';
            }
        }
    }
    REP(i, n) REP(j, n) if (s[i][j] == 'x') {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    REP(i, 2 * n - 1) cout << ans[i] << '\n';
    return 0;
}