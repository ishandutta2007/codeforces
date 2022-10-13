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
const int Z = 1000, oo = 27081993;

int m, n, r, row[555][555], score[555][555];
int maxLeft[555][555], cntLeft[555][555];
int maxRight[555][555], cntRight[555][555];
int flag[2222][2222], rowBorder[2222], leftmost[2222], rightmost[2222];
int sumFlag[2222][2222];

void generateBorder()
{
    for (int i = -1000; i <= 1000; i++)
        for (int j = -1000; j <= 1000; j++)
        {
            sumFlag[i + Z][j + Z] = sumFlag[i + Z][j - 1 + Z];
            if (i * i + j * j <= r * r) sumFlag[i + Z][j + Z]++;
        }
            
    for (int i = -500; i <= 500; i++)
    {
        leftmost[i + Z] = oo; 
        rightmost[i + Z] = -oo;
        for (int j = -500; j <= 500; j++)
        {
            int ok = 1;
            for (int dx = 0, dy = r; dx <= r && ok; dx++)
            {
                while (dx * dx + dy * dy > r * r) dy--;
                if (sumFlag[i - dx + Z][j + dy + Z] != sumFlag[i - dx + Z][j - dy - 1 + Z]) ok = 0;
                if (sumFlag[i + dx + Z][j + dy + Z] != sumFlag[i + dx + Z][j - dy - 1 + Z]) ok = 0;
            }
            
            if (!ok)
            {
                leftmost[i + Z] = min(leftmost[i + Z], j - 1);
                rightmost[i + Z] = j + 1;
            }
        }
    }
}

int main()
{
    //freopen("e.in", "r", stdin);
    int x;
    
    cin >> m >> n >> r;
    
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            row[i][j] = row[i][j - 1] + x;
        }
            
    for (int i = r + 1; i <= m - r; i++)
        for (int j = r + 1; j <= n - r; j++)
            for (int dx = 0, dy = r; dx <= r; dx++)
            {
                while (dx * dx + dy * dy > r * r) dy--;
                score[i][j] += row[i - dx][j + dy] - row[i - dx][j - dy - 1];
                if (dx) score[i][j] += row[i + dx][j + dy] - row[i + dx][j - dy - 1];
            }
            
    for (int i = r + 1; i <= m - r; i++)
    {
        for (int j = r + 1; j <= n - r; j++)
        {
            maxLeft[i][j] = maxLeft[i][j - 1];
            cntLeft[i][j] = cntLeft[i][j - 1];
            if (score[i][j] == maxLeft[i][j]) cntLeft[i][j]++;
            else
                if (score[i][j] > maxLeft[i][j])
                    maxLeft[i][j] = score[i][j], cntLeft[i][j] = 1;
        }
        
        for (int j = n - r; j >= r + 1; j--)
        {
            maxRight[i][j] = maxRight[i][j + 1];
            cntRight[i][j] = cntRight[i][j + 1];
            if (score[i][j] == maxRight[i][j]) cntRight[i][j]++;
            else
                if (score[i][j] > maxRight[i][j])
                    maxRight[i][j] = score[i][j], cntRight[i][j] = 1;
        }
    }
    
    generateBorder();   
    
    int ans = 0;
    long long pairs = 0;
    for (int i = r + 1; i <= m - r; i++)
        for (int j = r + 1; j <= n - r; j++)
        {
            int best = 0, cnt = 0;
            for (int ii = r + 1; ii <= m - r; ii++)
            {
                int di = ii - i;
                if (leftmost[di + Z] == oo) 
                {
                    if (maxLeft[ii][n - r] == best) cnt += cntLeft[ii][n - r];
                    else
                        if (maxLeft[ii][n - r] > best)
                            best = maxLeft[ii][n - r], cnt = cntLeft[ii][n - r];
                    continue;
                }
                
                int jl = j + leftmost[di + Z];
                int jr = j + rightmost[di + Z];
                
                if (jl >= r + 1) 
                {
                    if (maxLeft[ii][jl] == best) cnt += cntLeft[ii][jl];
                    else
                        if (maxLeft[ii][jl] > best)
                            best = maxLeft[ii][jl], cnt = cntLeft[ii][jl];
                }
                
                if (jr <= n - r)
                {
                    if (maxRight[ii][jr] == best) cnt += cntRight[ii][jr];
                    else
                        if (maxRight[ii][jr] > best)
                            best = maxRight[ii][jr], cnt = cntRight[ii][jr];
                }
                
            }
            
            if (!best) continue;
            
            best += score[i][j];
            if (best == ans) pairs += cnt;
            else
                if (best > ans)
                    ans = best, pairs = cnt;
        }
        
    cout << ans << ' ' << pairs / 2 << endl;
}