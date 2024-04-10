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

char f[2005][2005];
int cnt[2005][2005];
int n, m;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

queue<PII> q;

void decNeib(int y, int x) {
    REP(k, 4) {
        char &a = f[y + dy[k]][x + dx[k]];
        if (--cnt[y + dy[k]][x + dx[k]] == 1 && a == '.')
            q.push(mp(y + dy[k], x + dx[k]));
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%s", f[i] + 1);
    REP(i, n + 2) f[i][0] = f[i][m + 1] = '*', f[i][m + 2] = '\0';
    REP(j, m + 2) f[0][j] = f[n + 1][j] = '*';
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
        int cur = 0;
        REP(k, 4) if (f[i + dy[k]][j + dx[k]] == '.')
            ++cur;
        cnt[i][j] = cur;
        if (cur == 1) q.push(mp(i, j));
    }
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if (f[i][j] != '.' || cnt[i][j] != 1) continue;
        REP(k, 4) if (f[i + dy[k]][j + dx[k]] == '.') {
            char &a = f[i][j];
            char &b = f[i + dy[k]][j + dx[k]];
            if (k == 0) a = 'v', b = '^';
            else if (k == 1) a = '^', b = 'v';
            else if (k == 2) a = '>', b = '<';
            else a = '<', b = '>';
            decNeib(i, j);
            decNeib(i + dy[k], j + dx[k]);
            break;
        }
    }
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) if (f[i][j] == '.') {
        printf("Not unique\n");
        return 0;
    }
    for (int i = 1; i <= n; ++i) f[i][m + 1] = '\0';
    for (int i = 1; i <= n; ++i)
        printf("%s\n", f[i] + 1);
    return 0;
}