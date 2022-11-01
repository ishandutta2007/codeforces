#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>

using namespace std;

int dis[61][61][61];
int tra[1001][61][61];

#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, m, r;
    ios::sync_with_stdio(false);
    cin >> n >> m >> r;
    REP(k, m)
    {
        REP(i, n) REP(j, n) cin >> dis[k][i][j];
        REP(x, n) REP(y, n) REP(z, n) if (x!=y&&x!=z&&y!=z)
            dis[k][y][z] = min(dis[k][y][z], dis[k][y][x]+dis[k][x][z]);
    }
    REP(i, n) REP(j, n) tra[0][i][j] = 0x7f7f7f7f;
    REP(i, n) REP(j, n) REP(k, m) tra[0][i][j] = min(tra[0][i][j], dis[k][i][j]);
    REP(t, 1001)
    {
        if (!t) continue;
        REP(i, n) REP(j, n) tra[t][i][j] = tra[t-1][i][j];
        REP(k, n) REP(i, n) REP(j, n)
            tra[t][i][j] = min(tra[t][i][j], tra[t-1][i][k]+tra[0][k][j]);
    }
    while (r--)
    {
        int u, v, k;
        cin >> u >> v >> k;
        --u, --v;
        cout << tra[k][u][v] << endl;
    }
    return 0;
}