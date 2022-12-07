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

int n, x, y, xx, yy;
int dist[2][4], side[2];

void solve(int *dist, int x, int y, int &side) {
    if (x == 0) {
        side = 0;
        dist[0] = y;
        dist[1] = n - y;
        dist[2] = 2 * n - y;
        dist[3] = n + y;
    } else if (y == n) {
        side = 1;
        dist[1] = x;
        dist[2] = n - x;
        dist[0] = n + x;
        dist[3] = 2 * n - x;
    } else if (x == n) {
        side = 2;
        dist[2] = n - y;
        dist[3] = y;
        dist[0] = n + y;
        dist[1] = 2 * n - y;
    } else {
        side = 3;
        dist[0] = x;
        dist[3] = n - x;
        dist[1] = n + x;
        dist[2] = 2 * n - x;
    }
}

int main() {
    cin >> n >> x >> y >> xx >> yy;
    solve(dist[0], x, y, side[0]);
    solve(dist[1], xx, yy, side[1]);
    int ans = 1e9;
    if (side[0] == side[1]) ans = max(abs(x - xx), abs(y - yy));
    REP(i, 4) ans = min(ans, dist[0][i] + dist[1][i]);
    printf("%d\n", ans);
    return 0;
}