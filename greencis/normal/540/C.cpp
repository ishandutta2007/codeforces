#include <iostream>
#include <cstdlib>

using namespace std;

int tail, head;
char f[1000][1000];
char used[1000][1000];

int n,m;
int sx,sy;
int fx,fy;
bool vis = false;

void dfs(int x, int y)
{
    if (x < 0 || x >= n) return;
    if (y < 0 || y >= m) return;
    if (x == fx && y == fy && f[x][y] == 'X')
    {
        cout << "YES";
        exit(0);
    }
    if (f[x][y] == 'X')
            return;
    if (f[x][y] == '.')
    {
        f[x][y] = 'X';
        dfs(x,y+1);
        dfs(x,y-1);
        dfs(x+1,y);
        dfs(x-1,y);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> f[i][j];
    cin >> sx >> sy;
    sx--; sy--;
    f[sx][sy] = '.';
    cin >> fx >> fy;
    fx--; fy--;
    dfs(sx,sy);
    cout << "NO" << endl;
    return 0;
}