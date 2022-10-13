#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int REV[] = {2, 3, 0, 1};
const string DIRECTION = "URDL";

int n, sx, sy, a[555][555];
int A, cntOne, reachOne, visited[555][555];
char ans[3000300];
set <int> row[555], col[555];

int inside(int x, int y)
{
    return x && y && x <= n && y <= n;
}

int getMaxCol(int y)
{
    if (col[y].empty()) return 0;
    return *col[y].rbegin();
}

int getMinCol(int y)
{
    if (col[y].empty()) return n + 1;
    return *col[y].begin();
}

int getMaxRow(int x)
{
    if (row[x].empty()) return 0;
    return *row[x].rbegin();
}

int getMinRow(int x)
{
    if (row[x].empty()) return n + 1;
    return *row[x].begin();
}

int inRange(int x, int y, int dir)
{
    if (!dir) return getMinCol(y) <= x;
    if (dir == 1) return getMaxRow(x) >= y;
    if (dir == 2) return getMaxCol(y) >= x;
    return getMinRow(x) <= y;
}

void dfs(int x, int y, int dir)
{
    visited[x][y] = 1;
    
    if (!a[x][y]) ans[A++] = '1';
    if (a[x][y] == 1) reachOne++;
    
    row[x].insert(y);
    col[y].insert(x);
    
    for (int i = 0; i < 4; i++) 
    {
        int xx = x + dx[i], yy = y + dy[i];
        if (inside(xx, yy) && inRange(xx, yy, i) && !visited[xx][yy])
        {
            ans[A++] = DIRECTION[i];
            dfs(xx, yy, i);
        }
    }
    
    ans[A++] = '2';
    if (x != sx || y != sy) ans[A++] = DIRECTION[REV[dir]];
    row[x].erase(y);
    col[y].erase(x);
}

int main()
{
    ios::sync_with_stdio(0);
    
    cin >> n >> sx >> sy;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j]) 
            {
                row[i].insert(j);
                col[j].insert(i);
                cntOne++;
            }
        }
            
    dfs(sx, sy, 0);
    
    if (reachOne < cntOne) cout << "NO\n";
    else 
    {
        cout << "YES\n";
        for (int i = 0; i < A; i++) cout << ans[i];
    }
}