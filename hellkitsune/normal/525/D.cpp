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
char s[2000][2005];
queue<PII> q;

bool check(int y, int x) {
    int cnt = 0;
    for (int i = y; i <= y + 1; ++i) for (int j = x; j <= x + 1; ++j) if (s[i][j] == '.') {
        ++cnt;
    }
    return cnt != 3;
}

void destroyWalls(int y, int x) {
    for (int i = y; i <= y + 1; ++i) for (int j = x; j <= x + 1; ++j) if (s[i][j] != '.') {
        s[i][j] = '.';
        q.push(mp(i, j));
    }
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%s", s[i]);
    REP(i, n - 1) REP(j, m - 1) {
        if (!check(i, j)) {
            destroyWalls(i, j);
        }
    }
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = y - 1; i <= y; ++i) if (i >= 0 && i < n - 1) {
            for (int j = x - 1; j <= x; ++j) if (j >= 0 && j < m - 1) {
                if (!check(i, j)) {
                    destroyWalls(i, j);
                }
            }
        }
    }
    REP(i, n) printf("%s\n", s[i]);
    return 0;
}