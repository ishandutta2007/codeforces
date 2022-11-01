#include <bits/stdc++.h>

using namespace std;

int N, K;
char grid[3][101];
int dp[101][3];

int solve(int t, int row)
{
    if(t*3<N && grid[row][t*3]!='.')
        return 0;
    if(t==N-1)
        return 1;
    int& ret=dp[t][row];
    if(ret!=-1)
        return ret;
    ret=0;
    if(t*3+1>=N || grid[row][t*3+1]=='.')
    {
        if(row-1>=0 && (t*3+1>=N || grid[row-1][t*3+1]=='.'))
            ret|=solve(t+1, row-1);
        if(t*3+1>=N || grid[row][t*3+1]=='.')
            ret|=solve(t+1, row);
        if(row+1<3 && (t*3+1>=N || grid[row+1][t*3+1]=='.'))
            ret|=solve(t+1, row+1);
    }
    return ret;
}

void _main()
{
    scanf("%d%d", &N, &K);
    for(int i=0; i<3; i++)
        scanf("%s", grid[i]);
    int sx=-1;
    for(int i=0; i<3; i++)
        if(grid[i][0]=='s')
            sx=i, grid[i][0]='.';
    memset(dp, -1, sizeof dp);
    if(solve(0, sx))
        printf("YES\n");
    else
        printf("NO\n");
}

int main()
{
    int TEST;
    scanf("%d", &TEST);
    while(TEST--)
        _main();
    return 0;
}