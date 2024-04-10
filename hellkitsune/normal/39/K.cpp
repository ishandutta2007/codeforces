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

int n, m, k;
char s[1003][1003];
int hsum[1003][1003], vsum[1003][1003];
int sum[1003][1003] = {};
bool used[1003][1003] = {};
int y[100], x[100], yy[100], xx[100];
int cnt = 0;
LL ans = 0;

void solve(int x, int y, int xx, int yy) {
    int cur = sum[yy][xx] - sum[y - 1][xx] - sum[yy][x - 1] + sum[y - 1][x - 1];
    int lo = xx, hi = m, mid;
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        if (sum[yy][mid] - sum[y - 1][mid] - sum[yy][x - 1] + sum[y - 1][x - 1] == cur)
            lo = mid;
        else
            hi = mid - 1;
    }
    int hor1 = lo - xx + 1;
    lo = 1, hi = x;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (sum[yy][xx] - sum[y - 1][xx] - sum[yy][mid - 1] + sum[y - 1][mid - 1] == cur)
            hi = mid;
        else
            lo = mid + 1;
    }
    int hor2 = x - lo + 1;
    lo = yy, hi = n;
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        if (sum[mid][xx] - sum[mid][x - 1] - sum[y - 1][xx] + sum[y - 1][x - 1] == cur)
            lo = mid;
        else
            hi = mid - 1;
    }
    int ver1 = lo - yy + 1;
    lo = 1, hi = y;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (sum[yy][xx] - sum[yy][x - 1] - sum[mid - 1][xx] + sum[mid - 1][x - 1] == cur)
            hi = mid;
        else
            lo = mid + 1;
    }
    int ver2 = y - lo + 1;
    if (hor1 * hor2 > ver1 * ver2) {
        for (int i = y; i >= 1; --i) {
            if (i < y && hsum[i][xx] - hsum[i][x - 1] > 0) break;
            for (int ii = yy; ii <= n; ++ii) {
                if (ii > yy && hsum[ii][xx] - hsum[ii][x - 1] > 0) break;
                int cnt1, cnt2;
                lo = xx, hi = m;
                while (lo < hi) {
                    mid = (lo + hi + 1) >> 1;
                    if (sum[ii][mid] - sum[i - 1][mid] - sum[ii][x - 1] + sum[i - 1][x - 1] == cur)
                        lo = mid;
                    else
                        hi = mid - 1;
                }
                cnt1 = lo - xx + 1;
                lo = 1, hi = x;
                while (lo < hi) {
                    mid = (lo + hi) >> 1;
                    if (sum[ii][xx] - sum[i - 1][xx] - sum[ii][mid - 1] + sum[i - 1][mid - 1] == cur)
                        hi = mid;
                    else
                        lo = mid + 1;
                }
                cnt2 = x - lo + 1;
                ans += cnt1 * cnt2;
            }
        }
    } else {
        for (int i = x; i >= 1; --i) {
            if (i < x && vsum[i][yy] - vsum[i][y - 1] > 0) break;
            for (int ii = xx; ii <= m; ++ii) {
                if (ii > xx && vsum[ii][yy] - vsum[ii][y - 1] > 0) break;
                int cnt1, cnt2;
                lo = yy, hi = n;
                while (lo < hi) {
                    mid = (lo + hi + 1) >> 1;
                    if (sum[mid][ii] - sum[mid][i - 1] - sum[y - 1][ii] + sum[y - 1][i - 1] == cur)
                        lo = mid;
                    else
                        hi = mid - 1;
                }
                cnt1 = lo - yy + 1;
                lo = 1, hi = y;
                while (lo < hi) {
                    mid = (lo + hi) >> 1;
                    if (sum[yy][ii] - sum[yy][i - 1] - sum[mid - 1][ii] + sum[mid - 1][i - 1] == cur)
                        hi = mid;
                    else
                        lo = mid + 1;
                }
                cnt2 = y - lo + 1;
                ans += cnt1 * cnt2;
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    REP(i, n) scanf("%s", s[i + 1] + 1);
    REP(i, n + 2) s[i][0] = s[i][m + 1] = '.';
    REP(i, m + 2) s[0][i] = s[n + 1][i] = '.';
    for (int i = 1; i <= n; ++i) {
        hsum[i][0] = 0;
        for (int j = 1; j <= m; ++j) {
            hsum[i][j] = hsum[i][j - 1] + (s[i][j] == '*');
        }
    }
    for (int i = 1; i <= m; ++i) {
        vsum[i][0] = 0;
        for (int j = 1; j <= n; ++j) {
            vsum[i][j] = vsum[i][j - 1] + (s[j][i] == '*');
        }
    }
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (s[i][j] == '*');
    }
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) if (!used[i][j] && s[i][j] == '*') {
        int ii = i, jj = j;
        while (ii < n && s[ii + 1][j] == '*') ++ii;
        while (jj < m && s[i][jj + 1] == '*') ++jj;
        y[cnt] = i;
        x[cnt] = j;
        yy[cnt] = ii;
        xx[cnt] = jj;
        ++cnt;
        for (int p = i; p <= ii; ++p) for (int q = j; q <= jj; ++q) {
            used[p][q] = true;
        }
    }
    assert(cnt == k);
    REP(i, k) for (int j = i + 1; j < k; ++j) for (int q = j + 1; q < k; ++q) {
        int cx = min(min(x[i], x[j]), x[q]);
        int cxx = max(max(xx[i], xx[j]), xx[q]);
        int cy = min(min(y[i], y[j]), y[q]);
        int cyy = max(max(yy[i], yy[j]), yy[q]);
        bool ok = true;
        REP(p, k) if (p != i && p != j && p != q) {
            if (x[p] <= cxx && cx <= xx[p] && y[p] <= cyy && cy <= yy[p]) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        solve(cx, cy, cxx, cyy);
    }
    REP(i, k) for (int j = i + 1; j < k; ++j) {
        int cx = min(x[i], x[j]);
        int cxx = max(xx[i], xx[j]);
        int cy = min(y[i], y[j]);
        int cyy = max(yy[i], yy[j]);
        bool ok = true;
        REP(p, k) if (p != i && p != j) {
            if (x[p] <= cxx && cx <= xx[p] && y[p] <= cyy && cy <= yy[p]) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        solve(cx, cy, cxx, cyy);
    }
    REP(i, k)
        solve(x[i], y[i], xx[i], yy[i]);
    cout << ans << endl;
    return 0;
}