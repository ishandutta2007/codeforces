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

int a, b, cc, n, m;
int ans[100][100] = {};
char f[200][201] = {};

int main() {
    scanf("%d%d%d%d%d", &n, &m, &a, &b, &cc);
    int r = a / m, c = a % m;
    for (int i = c; i < m; ++i) if ((i - c) & 1) {
        ans[r][i] = 2;
    } else {
        ans[r][i] = 3;
    }
    for (int i = 0; i < c; ++i) if ((c - i) & 1) {
        ans[r + 1][i] = 3;
    } else {
        ans[r + 1][i] = 2;
    }
    REP(i, r) REP(j, m) ans[i][j] = 1;
    REP(i, c) ans[r][i] = 1;

    cc -= m;
    r = n - cc / m - 1;
    c = m - cc % m;
    for (int i = r; i < n; ++i) for (int j = c; j < m; ++j) if ((i - r) & 1) {
        if ((j - c) & 1) {
            ans[i][j] = 3;
        } else {
            ans[i][j] = 2;
        }
    } else {
        if ((j - c) & 1) {
            ans[i][j] = 5;
        } else {
            ans[i][j] = 4;
        }
    }
    for (int i = r + 1; i < n; ++i) for (int j = 0; j < c; ++j) if ((i - r - 1) & 1) {
        if ((c - j) & 1) {
            ans[i][j] = 3;
        } else {
            ans[i][j] = 2;
        }
    } else {
        if (j - c & 1) {
            ans[i][j] = 5;
        } else {
            ans[i][j] = 4;
        }
    }

    REP(i, n) REP(j, m) {
        if (ans[i][j] == 0) {
            f[2 * i][2 * j] = '.';
            f[2 * i][2 * j + 1] = '.';
            f[2 * i + 1][2 * j] = '.';
            f[2 * i + 1][2 * j + 1] = '.';
        } else if (ans[i][j] == 1) {
            f[2 * i][2 * j] = '#';
            f[2 * i][2 * j + 1] = '#';
            f[2 * i + 1][2 * j] = '#';
            f[2 * i + 1][2 * j + 1] = '#';
        } else if (ans[i][j] == 2) {
            f[2 * i][2 * j] = '\\';
            f[2 * i][2 * j + 1] = '#';
            f[2 * i + 1][2 * j] = '.';
            f[2 * i + 1][2 * j + 1] = '\\';
        } else if (ans[i][j] == 3) {
            f[2 * i][2 * j] = '#';
            f[2 * i][2 * j + 1] = '/';
            f[2 * i + 1][2 * j] = '/';
            f[2 * i + 1][2 * j + 1] = '.';
        } else if (ans[i][j] == 4) {
            f[2 * i][2 * j] = '.';
            f[2 * i][2 * j + 1] = '/';
            f[2 * i + 1][2 * j] = '/';
            f[2 * i + 1][2 * j + 1] = '#';
        } else {
            f[2 * i][2 * j] = '\\';
            f[2 * i][2 * j + 1] = '.';
            f[2 * i + 1][2 * j] = '#';
            f[2 * i + 1][2 * j + 1] = '\\';
        }
    }
    REP(i, 2 * n) f[i][2 * m] = '\0';
    REP(i, 2 * n) printf("%s\n", f[i]);
    return 0;
}