#include <bits/stdc++.h>
using namespace std;

int n, m, q, a[44][44], cnt[44][44][44][44], ans[44][44][44][44];

int isGood(int i, int j, int ii, int jj)
{
    return a[i - 1][j - 1] + a[ii][jj] == a[i - 1][jj] + a[ii][j - 1];
}

int main()
{
    ios::sync_with_stdio(0);
    string s;
    int x, y, xx, yy;
    
    cin >> m >> n >> q;
    for (int i = 1; i <= m; i++) 
    {
        cin >> s;
        for (int j = 1; j <= n; j++) 
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + s[j - 1] - '0';
    }
    
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            for (int ii = i; ii <= m; ii++)
                for (int jj = j; jj <= n; jj++)
                {
                    cnt[i][j][ii][jj] = cnt[i][j][ii - 1][jj] + cnt[i][j][ii][jj - 1] - cnt[i][j][ii - 1][jj - 1];
                    cnt[i][j][ii][jj] += isGood(i, j, ii, jj);
                }
                
    for (int di = 0; di < m; di++)
        for (int dj = 0; dj < n; dj++)
            for (int i = 1; i + di <= m; i++)
                for (int j = 1; j + dj <= n; j++)
                {
                    int ii = i + di, jj = j + dj;
                    
                    ans[i][j][ii][jj] += ans[i + 1][j][ii][jj];
                    ans[i][j][ii][jj] += ans[i][j + 1][ii][jj];
                    ans[i][j][ii][jj] -= ans[i + 1][j + 1][ii][jj];
                    ans[i][j][ii][jj] += cnt[i][j][ii][jj];
                }
                    
    while (q--)
    {
        cin >> x >> y >> xx >> yy;
        cout << ans[x][y][xx][yy] << endl;
    }
}