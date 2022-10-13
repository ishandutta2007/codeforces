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

int m, n, a[1111][1111], deg[1111][1111], visited[1111][1111], isIntersection[16], mask[1111][1111];

int gcd(int x, int y)
{
    return x && y ? gcd(y, x % y) : x + y;
}

int valid(int x, int y)
{
    return x && x <= m && y && y <= n && a[x][y];
}

void visit(int x, int y)
{
    if (visited[x][y]) return;
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) 
        if (valid(x + dx[i], y + dy[i]))
        {
            deg[x][y]++;
            mask[x][y] |= 1 << i;
            visit(x + dx[i], y + dy[i]);
        }
}

int main()
{
    //freopen("e.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
            
    for (int i = 1; i < 16; i++) isIntersection[i] = 1;
    isIntersection[5] = isIntersection[10] = 0;
            
    int cnt = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] && !visited[i][j])
                visit(i, j), cnt++;
    
    if (cnt != 1)
    {
        cout << "-1\n";
        return 0;
    }
    
    int lastRow[1111] = {0}, oddDegCnt = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j]) oddDegCnt += deg[i][j] % 2;
            
    if (oddDegCnt && oddDegCnt != 2)
    {
        cout << "-1\n";
        return 0;
    }
    
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int lastCol = 0;
        for (int j = 1; j <= n; j++)
            if (a[i][j] && isIntersection[mask[i][j]])
            {
                if (lastCol && a[i][j - 1]) ans = gcd(ans, j - lastCol); 
                lastCol = j;
                if (lastRow[j] && a[i - 1][j]) ans = gcd(ans, i - lastRow[j]);
                lastRow[j] = i;
            }
    }
    
    if (ans <= 1) cout << "-1\n";
    else
        for (int i = 2; i <= ans; i++)
            if (ans % i == 0)
                cout << i << ' ';
}