#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int m, n, kept[555][555], empty, k;
string a[555];

void visit(int x, int y)
{
    kept[x][y] = 1;
    if (--empty == k)
    {
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++)
                if (a[i][j] == '.' && !kept[i][j]) cout << 'X';
                else cout << a[i][j];
            cout << "\n";
        }
        exit(0);
    }
    
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx >= 0 && xx < m && yy >= 0 && yy < n && a[xx][yy] == '.' && !kept[xx][yy]) 
            visit(xx, yy);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    
    cin >> m >> n >> k;
    for (int i = 0; i < m; i++) 
    {
        cin >> a[i];
        for (int j = 0; j < n; j++) empty += (a[i][j] == '.');
    }
    
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == '.')
                visit(i, j);
}