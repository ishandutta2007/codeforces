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
int d[2002][2002] = {};
queue<PII> q;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) d[i][j] = -1;
    scanf("%d", &k);
    REP(i, k) {
        int x, y;
        scanf("%d%d", &x, &y);
        d[x][y] = 0;
        q.push(mp(x, y));
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (d[x - 1][y] == -1) {
            d[x - 1][y] = d[x][y] + 1;
            q.push(mp(x - 1, y));
        }
        if (d[x + 1][y] == -1) {
            d[x + 1][y] = d[x][y] + 1;
            q.push(mp(x + 1, y));
        }
        if (d[x][y - 1] == -1) {
            d[x][y - 1] = d[x][y] + 1;
            q.push(mp(x, y - 1));
        }
        if (d[x][y + 1] == -1) {
            d[x][y + 1] = d[x][y] + 1;
            q.push(mp(x, y + 1));
        }
    }
    int best = -1, x = -1, y = -1;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) if (d[i][j] > best) {
        best = d[i][j];
        x = i;
        y = j;
    }
    cout << x << ' ' << y << endl;
    return 0;
}