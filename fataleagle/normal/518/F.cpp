#include <bits/stdc++.h>

using namespace std;

int N, M;
char grid[2001][2001];
bool U[2001][2001];
bool D[2001][2001];
bool L[2001][2001];
bool R[2001][2001];
int PRUD[2001][2001];
int PULR[2001][2001];

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++)
        scanf("%s", grid[i]);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(grid[i][j]=='#')
            {
                U[i][j]=false;
                L[i][j]=false;
            }
            else
            {
                if(i==0)
                    U[i][j]=true;
                else
                    U[i][j]=U[i-1][j];
                if(j==0)
                    L[i][j]=true;
                else
                    L[i][j]=L[i][j-1];
            }
    for(int i=N-1; i>=0; i--)
        for(int j=M-1; j>=0; j--)
            if(grid[i][j]=='#')
            {
                D[i][j]=false;
                R[i][j]=false;
            }
            else
            {
                if(i==N-1)
                    D[i][j]=true;
                else
                    D[i][j]=D[i+1][j];
                if(j==M-1)
                    R[i][j]=true;
                else
                    R[i][j]=R[i][j+1];
            }
    for(int i=1; i<N-1; i++)
        for(int j=1; j<M-1; j++)
            if(grid[i][j]=='#')
                PULR[i][j]=0;
            else
                PULR[i][j]=PULR[i-1][j]+L[i][j]+R[i][j];
    for(int i=N-2; i>0; i--)
        for(int j=M-2; j>0; j--)
            if(grid[i][j]=='#')
                PRUD[i][j]=0;
            else
                PRUD[i][j]=PRUD[i][j+1]+U[i][j]+D[i][j];
    long long ans=0;
    for(int i=1; i<N-1; i++)
        ans+=R[i][0];
    for(int i=1; i<M-1; i++)
        ans+=D[0][i];
    for(int i=1; i<N-1; i++)
        for(int j=1; j<M-1; j++)
        {
            if(U[i][j])
            {
                ans+=L[i][j]+R[i][j];
                if(j<M-2)
                {
                    ans+=D[i][j+1];
                    if(grid[i][j+1]=='.')
                        ans+=PRUD[i][j+2];
                }
            }
            if(D[i][j])
            {
                ans+=L[i][j]+R[i][j];
                if(j<M-2)
                {
                    ans+=U[i][j+1];
                    if(grid[i][j+1]=='.')
                        ans+=PRUD[i][j+2];
                }
            }
            if(L[i][j])
            {
                if(i>1)
                {
                    ans+=R[i-1][j];
                    if(grid[i-1][j]=='.')
                        ans+=PULR[i-2][j];
                }
            }
            if(R[i][j])
            {
                if(i>1)
                {
                    ans+=L[i-1][j];
                    if(grid[i-1][j]=='.')
                        ans+=PULR[i-2][j];
                }
            }
        }
    printf("%lld\n", ans);
    return 0;
}