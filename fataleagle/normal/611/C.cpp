#include <bits/stdc++.h>

using namespace std;

int N, M;
char grid[505][505];
int A[505][505];
int B[505][505];

int get(int X[505][505], int a, int b, int c, int d)
{
    if(a>c || b>d)
        return 0;
    a--, b--;
    return X[c][d]-X[a][d]-X[c][b]+X[a][b];
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
        scanf("%s", grid[i]+1);
    for(int i=1; i<N; i++)
        for(int j=1; j<=M; j++)
        {
            A[i][j]=grid[i][j]=='.' && grid[i+1][j]=='.';
            A[i][j]+=A[i][j-1]+A[i-1][j]-A[i-1][j-1];
        }
    for(int i=1; i<=N; i++)
        for(int j=1; j<M; j++)
        {
            B[i][j]=grid[i][j]=='.' && grid[i][j+1]=='.';
            B[i][j]+=B[i][j-1]+B[i-1][j]-B[i-1][j-1];
        }
    int Q;
    scanf("%d", &Q);
    while(Q--)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        printf("%d\n", get(A, a, b, c-1, d)+get(B, a, b, c, d-1));
    }
    return 0;
}