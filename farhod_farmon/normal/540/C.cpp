#include <bits/stdc++.h>
using namespace std;
int a, b, used[600][600];
char c;

void dfs( int x, int y )
{
    used[x][y]++;
    if( used[x][y] >= 3 || x < 1 || y < 1 || x > a || y > b )return;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

int main()
{
    int i, j;
    cin >> a >> b;
    for( i = 1; i <= a; i++ ){
        for( j = 1; j <= b; j++ ){
            cin >> c;
            if( c == '.' )used[i][j] = 1;
            else used[i][j] = 2;
        }
    }
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    used[x1][y1] = 1;
    dfs(x1, y1);
    if( used[x2][y2] >= 3 )cout << "YES";
    else cout << "NO";
}