#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

char u[4005][4005];
int n,m,x,y,ans = 2e9;
vector<int> g[4005];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        u[y][x] = u[x][y] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < g[i].size(); ++j)
        for (int k = j + 1; k < g[i].size(); ++k) {
            int v1 = i, v2 = g[i][j], v3 = g[i][k];
            if (u[v2][v3]) ans = min(ans, int(g[v1].size() + g[v2].size() + g[v3].size() - 6));
        }
    }

    if (ans == 2e9) ans = -1;
    cout << ans;

    return 0;
}