#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
const int oo = 27081993;

int n, f[44][1 << 20];
string a[22];

int dp(int diagonal, int mask)
{
    if (diagonal == n * 2 - 2) return 0;
    int &res = f[diagonal][mask];
    if (res > -oo) return res;
    
    int maskChar[26] = {0};
    
    for (int row = 0; row < n; row++)
        if (mask >> row & 1)
        {
            int col = diagonal - row;
            if (col < 0 || col >= n) continue;
            if (row + 1 < n) maskChar[a[row + 1][col] - 'a'] |= 1 << (row + 1);
            if (col + 1 < n) maskChar[a[row][col + 1] - 'a'] |= 1 << row;
        }
    
    for (int i = 0; i < 26; i++)
        if (maskChar[i])
        {
            int score = 0;
            if (!i) score += (diagonal % 2 ? 1 : -1);
            if (i == 1) score += (diagonal % 2 ? -1 : 1);
            score -= dp(diagonal + 1, maskChar[i]);
            res = max(res, score);
        }
        
    return res;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    for (int i = 0; i < n * 2 - 1; i++)
        for (int j = 0; j < 1 << n; j++)
            f[i][j] = -oo;
            
    int ans = dp(0, 1);
    if (a[0][0] == 'a') ans--;
    if (a[0][0] == 'b') ans++;
    
    if (!ans) puts("DRAW");
    else puts(ans < 0 ? "FIRST" : "SECOND");
}