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

int n, m;
char s[500][505];
int y, x, yy, xx;
bool flag = false;

void go(int y, int x) {
    s[y][x] = 'X';
    if (y == yy && x == xx) flag = true;
    if (y > 0 && s[y - 1][x] == '.') go(y - 1, x);
    if (y < n - 1 && s[y + 1][x] == '.') go(y + 1, x);
    if (x > 0 && s[y][x - 1] == '.') go(y, x - 1);
    if (x < m - 1 && s[y][x + 1] == '.') go(y, x + 1);
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%s", s[i]);
    scanf("%d%d%d%d", &y, &x, &yy, &xx), --y, --x, --yy, --xx;
    s[y][x] = '.';
    int cnt = 0;
    if (yy > 0 && s[yy - 1][xx] == '.') ++cnt;
    if (yy < n - 1 && s[yy + 1][xx] == '.') ++cnt;
    if (xx > 0 && s[yy][xx - 1] == '.') ++cnt;
    if (xx < m - 1 && s[yy][xx + 1] == '.') ++cnt;
    if (yy == y && xx == x) {
        if (cnt > 0) printf("YES\n");
        else printf("NO\n");
        return 0;
    }
    if (s[yy][xx] == '.') {
        if (cnt < 2) {
            printf("NO\n");
            return 0;
        }
    } else {
        s[yy][xx] = '.';
    }
    go(y, x);
    if (flag) printf("YES\n");
    else printf("NO\n");
    return 0;
}