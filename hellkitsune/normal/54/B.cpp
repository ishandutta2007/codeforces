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

int n, m;
char s[20][25];
int best = 1234567, besty, bestx, ans = 0;

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%s", s[i]);
    for (int y = 1; y <= n; ++y) if (n % y == 0) {
        for (int x = 1; x <= m; ++x) if (m % x == 0) {
            bool ok = true;
            for (int yy = 0; yy < n && ok; yy += y) for (int xx = 0; xx < m && ok; xx += x) {
                for (int cy = 0; cy < n && ok; cy += y) for (int cx = 0; cx < m; cx += x) if (cy != yy || cx != xx) {
                    bool bad = true;
                    for (int i = 0; i < y && bad; ++i) REP(j, x) if (s[yy + i][xx + j] != s[cy + i][cx + j]) {
                        bad = false;
                        break;
                    }
                    if (bad) {
                        ok = false;
                        break;
                    }
                    bad = true;
                    for (int i = 0; i < y && bad; ++i) REP(j, x) if (s[yy + i][xx + j] != s[cy + y - 1 - i][cx + x - 1 - j]) {
                        bad = false;
                        break;
                    }
                    if (bad) {
                        ok = false;
                        break;
                    }
                    if (y != x) continue;
                    bad = true;
                    for (int i = 0; i < y && bad; ++i) REP(j, x) if (s[yy + i][xx + j] != s[cy + j][cx + x - 1 - i]) {
                        bad = false;
                        break;
                    }
                    if (bad) {
                        ok = false;
                        break;
                    }
                    bad = true;
                    for (int i = 0; i < y && bad; ++i) REP(j, x) if (s[yy + i][xx + j] != s[cy + y - 1 - j][cx + i]) {
                        bad = false;
                        break;
                    }
                    if (bad) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                ++ans;
                if (x * y < best || (x * y == best && y < bestx)) {
                    best = x * y;
                    bestx = y;
                    besty = x;
                }
            }
        }
    }
    printf("%d\n", ans);
    printf("%d %d\n", bestx, besty);
    return 0;
}