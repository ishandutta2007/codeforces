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

int n, m, q;
char s[111111][12];
const int OFF = 128, BITS = 7, MASK = 127;
int dy[111111][12], dx[111111][12];
char qu[5];
int mx;

void go(int &y, int &x, int upTo) {
    REP(z, mx) {
        if (s[y][x] == '^') {
            --y;
            if (y == upTo || y == 0) break;
        } else if (s[y][x] == '<') {
            if (--x == 0) break;
        } else {
            if (++x > m) break;
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1), s[i][0] = s[i][m + 1] = 'f';
    REP(i, m + 2) s[0][i] = s[n + 1][i] = 'f';
    mx = (OFF + 2) * m;
    for (int i = OFF; i <= n; i += OFF) for (int j = 1; j <= m; ++j) {
        int y = i, x = j;
        go(y, x, i - OFF);
        if (y != i - OFF && y != 0 && x != 0 && x != m + 1)
            dy[i][j] = -1;
        else {
            dy[i][j] = y;
            dx[i][j] = x;
        }
    }
    REP(query, q) {
        scanf("%s", qu);
        if (qu[0] == 'C') {
            int Y, X;
            scanf("%d%d%s", &Y, &X, qu);
            s[Y][X] = qu[0];
            if (Y & MASK) {
                Y &= ~MASK;
                Y += OFF;
            }
            for (int j = 1; j <= m; ++j) {
                int y = Y, x = j;
                go(y, x, Y - OFF);
                if (y != Y - OFF && y != 0 && x != 0 && x != m + 1)
                    dy[Y][j] = -1;
                else {
                    dy[Y][j] = y;
                    dx[Y][j] = x;
                }
            }
        } else {
            int y, x;
            scanf("%d%d", &y, &x);
            if (y & MASK) {
                int upTo = y & ~MASK;
                go(y, x, upTo);
                if (y != upTo && y != 0 && x != 0 && x != m + 1) {
                    printf("-1 -1\n");
                    continue;
                }
            }
            bool flag = false;
            while (y != 0 && x != 0 && x != m + 1) {
                int newY = dy[y][x];
                x = dx[y][x];
                y = newY;
                if (y == -1) {
                    printf("-1 -1\n");
                    flag = true;
                    break;
                }
            }
            if (flag) continue;
            printf("%d %d\n", y, x);
        }
    }
    return 0;
}