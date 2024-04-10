#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
int N, M;
char grid[500][501];
int dp[501][501];
int ndp[501][501];

void addmod(int& x, int v)
{
    x+=v;
    if(x>=MOD)
        x-=MOD;
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++)
        scanf("%s", grid[i]);
    dp[0][N-1]=grid[0][0]==grid[N-1][M-1];
    int C;
    for(C=0; C<(N+M-2)/2; C++)
    {
        //x0 + y0 = C
        //N + M - C - 2 = x1 + y1
        for(int x0=0; x0<N && C-x0>=0; x0++)
        {
            int y0=C-x0;
            for(int x1=0; x1<N && N+M-C-2-x1>=0; x1++)
            {
                int y1=N+M-C-2-x1;
                if(x0+1<N && x1-1>=0 && grid[x0+1][y0]==grid[x1-1][y1])
                    addmod(ndp[x0+1][x1-1], dp[x0][x1]);
                if(x0+1<N && y1-1>=0 && grid[x0+1][y0]==grid[x1][y1-1])
                    addmod(ndp[x0+1][x1], dp[x0][x1]);
                if(y0+1<M && x1-1>=0 && grid[x0][y0+1]==grid[x1-1][y1])
                    addmod(ndp[x0][x1-1], dp[x0][x1]);
                if(y0+1<M && y1-1>=0 && grid[x0][y0+1]==grid[x1][y1-1])
                    addmod(ndp[x0][x1], dp[x0][x1]);
            }
        }
        for(int i=0; i<500; i++)
            for(int j=0; j<500; j++)
                dp[i][j]=ndp[i][j], ndp[i][j]=0;
    }
    int ans=0;
    if((N+M-1)%2==1)
    {
        for(int i=0; i<N; i++)
            addmod(ans, dp[i][i]);
    }
    else
    {
        for(int i=0; i<N; i++)
        {
            if(C-i+1<M && grid[i][C-i]==grid[i][C-i+1])
                addmod(ans, dp[i][i]);
            if(i+1<N && grid[i][C-i]==grid[i+1][C-i])
                addmod(ans, dp[i][i+1]);
        }
    }
    printf("%d\n", ans);
    return 0;
}