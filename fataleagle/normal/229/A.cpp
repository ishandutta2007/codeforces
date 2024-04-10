#include <bits/stdc++.h>

using namespace std;

int N, M;
char grid[101][10002];
int L[101][10001];
int R[101][10001];

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
        scanf("%s", grid[i]+1);
    for(int i=1; i<=N; i++)
    {
        bool allzero=true;
        for(int j=1; j<=M; j++)
        {
            allzero&=grid[i][j]=='0';
            if(grid[i][j]=='1')
                L[i][j]=j;
            else if(j>1)
                L[i][j]=L[i][j-1];
            else
                L[i][j]=-1;
        }
        if(allzero)
        {
            printf("-1\n");
            return 0;
        }
        for(int j=M; j>=1; j--)
        {
            if(grid[i][j]=='1')
                R[i][j]=j;
            else if(j<M)
                R[i][j]=R[i][j+1];
            else
                R[i][j]=-1;
        }
    }
    int ans=0x3f3f3f3f;
    for(int j=1; j<=M; j++)
    {
        int sum=0;
        for(int i=1; i<=N; i++)
        {
            int l, r;
            if(L[i][j]==-1)
                l=M-L[i][M]+j;
            else
                l=j-L[i][j];
            if(R[i][j]==-1)
                r=M-j+R[i][1];
            else
                r=R[i][j]-j;
            sum+=min(l, r);
        }
        ans=min(ans, sum);
    }
    printf("%d\n", ans);
    return 0;
}