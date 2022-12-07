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
char s[1005][1005];

bool used[4];

char findChar(int y, int x, int yy, int xx) {
    REP(i, 4) used[i] = false;
    for (int i = y; i <= yy; ++i) {
        int ax = x, axx = xx;
        if (i == y || i == yy) ++ax, --axx;
        for (int j = ax; j <= axx; ++j) {
            if (s[i][j] >= 'a' && s[i][j] <= 'd') {
                used[s[i][j] - 'a'] = true;
            }
        }
    }
    int ret = 0;
    while (used[ret]) ++ret;
    return 'a' + ret;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
    REP(i, n + 2) s[i][0] = s[i][m + 1] = '.';
    REP(i, m + 2) s[0][i] = s[n + 1][i] = s[n + 2][i] = '.';
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
        if (s[i][j] == 'w') s[i][j] = '0';
        else if (s[i][j] == 'b') s[i][j] = '1';
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) if (s[i][j] == '1') {
            if (s[i][j - 1] != '0' || s[i][j + 1] != '0') {
                printf("NO\n");
                return 0;
            }
            char cur = findChar(i - 1, j - 2, i + 1, j + 2);
            s[i][j - 1] = s[i][j] = s[i][j + 1] = cur;
        }
        for (int j = 1; j <= m; ++j) if (s[i][j] == '0') {
            if (s[i + 1][j] != '1' || s[i + 2][j] != '0') {
                printf("NO\n");
                return 0;
            }
            char cur = findChar(i - 1, j - 1, i + 3, j + 1);
            s[i][j] = s[i + 1][j] = s[i + 2][j] = cur;
        }
    }
    printf("YES\n");
    for (int i = 1; i <= n; ++i) {
        s[i][m + 1] = '\0';
        printf("%s\n", s[i] + 1);
    }
    return 0;
}