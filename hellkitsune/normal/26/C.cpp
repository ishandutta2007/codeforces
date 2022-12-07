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

int n, m, a, b, c;
char s[102][102];
bool can[26];

void putA(int y, int x) {
    --a;
    REP(i, 26) can[i] = true;
    for (int i = y - 1; i <= y + 1; ++i) for (int j = x - 1; j <= x + 2; ++j) {
        if (s[i][j] != '.') can[s[i][j] - 'a'] = false;
    }
    char ch = 'a';
    while (!can[ch - 'a']) ++ch;
    s[y][x] = s[y][x + 1] = ch;
}

void putB(int y, int x) {
    --b;
    REP(i, 26) can[i] = true;
    for (int i = y - 1; i <= y + 2; ++i) for (int j = x - 1; j <= x + 1; ++j) {
        if (s[i][j] != '.') can[s[i][j] - 'a'] = false;
    }
    char ch = 'a';
    while (!can[ch - 'a']) ++ch;
    s[y][x] = s[y + 1][x] = ch;
}

void putC(int y, int x) {
    --c;
    REP(i, 26) can[i] = true;
    for (int i = y - 1; i <= y + 2; ++i) for (int j = x - 1; j <= x + 2; ++j) {
        if (s[i][j] != '.') can[s[i][j] - 'a'] = false;
    }
    char ch = 'a';
    while (!can[ch - 'a']) ++ch;
    s[y][x] = s[y][x + 1] = ch;
    s[y + 1][x] = s[y + 1][x + 1] = ch;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> a >> b >> c;
    if ((n * m) & 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    REP(i, n + 2) REP(j, m + 2) s[i][j] = '.';
    if (n & 1) {
        if (a < m / 2) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        for (int i = 1; i <= m; i += 2)
            putA(n, i);
    }
    if (m & 1) {
        if (b < n / 2) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        for (int i = 1; i <= n; i += 2)
            putB(i, m);
    }
    for (int i = 1; i < n; i += 2) for (int j = 1; j < m; j += 2) {
        if (a >= 2) putA(i, j), putA(i + 1, j);
        else if (b >= 2) putB(i, j), putB(i, j + 1);
        else if (c > 0) putC(i, j);
        else {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cout << s[i][j];
        cout << '\n';
    }
    return 0;
}