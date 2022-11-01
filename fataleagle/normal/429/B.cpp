#include <bits/stdc++.h>

using namespace std;

int N, M;
int grid[1002][1002];
int tl[1002][1002];
int tr[1002][1002];
int bl[1002][1002];
int br[1002][1002];

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            scanf("%d", &grid[i][j]);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            tl[i][j]=max(tl[i-1][j], tl[i][j-1])+grid[i][j];
    for(int i=1; i<=N; i++)
        for(int j=M; j>=1; j--)
            tr[i][j]=max(tr[i-1][j], tr[i][j+1])+grid[i][j];
    for(int i=N; i>=1; i--)
        for(int j=1; j<=M; j++)
            bl[i][j]=max(bl[i+1][j], bl[i][j-1])+grid[i][j];
    for(int i=N; i>=1; i--)
        for(int j=M; j>=1; j--)
            br[i][j]=max(br[i+1][j], br[i][j+1])+grid[i][j];
    int maxi=0;
    for(int i=2; i<=N-1; i++)
        for(int j=2; j<=M-1; j++)
            maxi=max(maxi, tl[i][j-1]+tr[i-1][j]+bl[i+1][j]+br[i][j+1]);
    for(int i=2; i<=N-1; i++)
        for(int j=2; j<=M-1; j++)
            maxi=max(maxi, tl[i-1][j]+tr[i][j+1]+bl[i][j-1]+br[i+1][j]);
    printf("%d\n", maxi);
    return 0;
}