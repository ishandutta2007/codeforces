#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
int grid[1001][1001];
int U[1001][1001];
int D[1001][1001];
int L[1001][1001];
int R[1001][1001];

void update_UD(int c)
{
    int last=0;
    for(int i=1; i<=N; i++)
    {
        if(!grid[i][c])
        {
            U[i][c]=0;
            last=0;
            continue;
        }
        if(!last)
            last=i;
        U[i][c]=last;
    }
    last=0;
    for(int i=N; i>=1; i--)
    {
        if(!grid[i][c])
        {
            D[i][c]=0;
            last=0;
            continue;
        }
        if(!last)
            last=i;
        D[i][c]=last;
    }
}

void update_LR(int r)
{
    int last=0;
    for(int i=1; i<=M; i++)
    {
        if(!grid[r][i])
        {
            L[r][i]=0;
            last=0;
            continue;
        }
        if(!last)
            last=i;
        L[r][i]=last;
    }
    last=0;
    for(int i=M; i>=1; i--)
    {
        if(!grid[r][i])
        {
            R[r][i]=0;
            last=0;
            continue;
        }
        if(!last)
            last=i;
        R[r][i]=last;
    }
}

int best_U(int x, int y)
{
    if(!grid[x][y])
        return 0;
    int ox=x;
    int lo=L[x][y];
    int hi=R[x][y];
    int maxi=hi-lo+1;
    for(x--; x>=1; x--)
    {
        if(!grid[x][y])
            break;
        lo=max(lo, L[x][y]);
        hi=min(hi, R[x][y]);
        maxi=max(maxi, (hi-lo+1)*(ox-x+1));
    }
    return maxi;
}

int best_D(int x, int y)
{
    if(!grid[x][y])
        return 0;
    int ox=x;
    int lo=L[x][y];
    int hi=R[x][y];
    int maxi=hi-lo+1;
    for(x++; x<=N; x++)
    {
        if(!grid[x][y])
            break;
        lo=max(lo, L[x][y]);
        hi=min(hi, R[x][y]);
        maxi=max(maxi, (hi-lo+1)*(x-ox+1));
    }
    return maxi;
}

int best_L(int x, int y)
{
    if(!grid[x][y])
        return 0;
    int oy=y;
    int lo=U[x][y];
    int hi=D[x][y];
    int maxi=hi-lo+1;
    for(y--; y>=1; y--)
    {
        if(!grid[x][y])
            break;
        lo=max(lo, U[x][y]);
        hi=min(hi, D[x][y]);
        maxi=max(maxi, (hi-lo+1)*(oy-y+1));
    }
    return maxi;
}

int best_R(int x, int y)
{
    if(!grid[x][y])
        return 0;
    int oy=y;
    int lo=U[x][y];
    int hi=D[x][y];
    int maxi=hi-lo+1;
    for(y++; y<=M; y++)
    {
        if(!grid[x][y])
            break;
        lo=max(lo, U[x][y]);
        hi=min(hi, D[x][y]);
        maxi=max(maxi, (hi-lo+1)*(y-oy+1));
    }
    return maxi;
}

int main()
{
    scanf("%d%d%d", &N, &M, &Q);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            scanf("%d", grid[i]+j);
    for(int i=1; i<=N; i++)
        update_LR(i);
    for(int i=1; i<=M; i++)
        update_UD(i);
    int a, b, c;
    for(int i=0; i<Q; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        if(a==1)
        {
            grid[b][c]^=1;
            update_LR(b);
            update_UD(c);
        }
        else
            printf("%d\n", max(max(best_U(b, c), best_D(b, c)), max(best_L(b, c), best_R(b, c))));
    }
    return 0;
}