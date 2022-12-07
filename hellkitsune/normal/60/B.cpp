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

bool used[12][12][12];
int k, n, m;
string s;
int ans = 0;
int dx[6] = {0, 0, 0, 0, -1, 1};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {-1, 1, 0, 0, 0, 0};

void dfs(int x, int y, int z) {
    used[x][y][z] = true;
    ++ans;
    REP(i, 6) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        int zz = z + dz[i];
        if (!used[xx][yy][zz]) {
            dfs(xx, yy, zz);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> k >> n >> m;
    REP(i, k + 2) REP(j, n + 2) REP(p, m + 2) used[i][j][p] = true;
    REP(i, k) REP(j, n) {
        cin >> s;
        REP(p, m) if (s[p] == '.') {
            used[i + 1][j + 1][p + 1] = false;
        }
    }
    int x, y;
    cin >> x >> y;
    dfs(1, x, y);
    cout << ans << endl;
    return 0;
}