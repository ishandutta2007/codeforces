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

int n;
int a[2000][2000];
LL d[4][2000] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) REP(j, n) cin >> a[i][j];
    REP(i, n) {
        int y = 0, x = i;
        while (y < n && x < n) {
            d[0][i] += a[y][x];
            ++y, ++x;
        }
    }
    REP(i, n) {
        int y = i, x = 0;
        while (y < n && x < n) {
            d[1][i] += a[y][x];
            ++y, ++x;
        }
    }
    REP(i, n) {
        int y = 0, x = i;
        while (y < n && x >= 0) {
            d[2][i] += a[y][x];
            ++y, --x;
        }
    }
    REP(i, n) {
        int y = i, x = n - 1;
        while (y < n && x >= 0) {
            d[3][i] += a[y][x];
            ++y, --x;
        }
    }
    LL ans1 = -1, ans2 = -1;
    int y1, x1, y2, x2;
    REP(i, n) REP(j, n) {
        if ((i & 1) == (j & 1) && (j >= i)) {
            int y = (j - i) >> 1;
            int x = (j + i) >> 1;
            LL cur = d[0][i] + d[2][j] - a[y][x];
            if ((i & 1) && cur > ans2)
                ans2 = cur, y2 = y, x2 = x;
            else if (!(i & 1) && cur > ans1)
                ans1 = cur, y1 = y, x1 = x;
        }
        if ((i & 1) == ((j + n - 1) & 1) && i + j < n) {
            int tx = i + j;
            int y = j + ((n - 1 - tx) >> 1);
            int x = (tx + n - 1) >> 1;
            LL cur = d[0][i] + d[3][j] - a[y][x];
            if ((i & 1) && cur > ans2)
                ans2 = cur, y2 = y, x2 = x;
            else if (!(i & 1) && cur > ans1)
                ans1 = cur, y1 = y, x1 = x;
        }
        if ((i & 1) == (j & 1) && j - i >= 0) {
            int tx = j - i;
            int y = i + (tx >> 1);
            int x = tx >> 1;
            LL cur = d[1][i] + d[2][j] - a[y][x];
            if ((i & 1) && cur > ans2)
                ans2 = cur, y2 = y, x2 = x;
            else if (!(i & 1) && cur > ans1)
                ans1 = cur, y1 = y, x1 = x;
        }
        if ((i & 1) == ((j + n - 1) & 1)) {
            int tx = n - 1 - i + j;
            int x = tx >> 1;
            int y = i + (tx >> 1);
            if (y < n) {
                LL cur = d[1][i] + d[3][j] - a[y][x];
                if ((i & 1) && cur > ans2)
                    ans2 = cur, y2 = y, x2 = x;
                else if (!(i & 1) && cur > ans1)
                    ans1 = cur, y1 = y, x1 = x;
            }
        }
    }
    cout << ans1 + ans2 << '\n';
    cout << y1 + 1 << ' ' << x1 + 1 << ' ' << y2 + 1 << ' ' << x2 + 1 << '\n';
    return 0;
}