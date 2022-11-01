#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[100][100];
int B[100][100];
int C[100][100];

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            A[i][j]=1;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
        {
            scanf("%d", B[i]+j);
            if(B[i][j])
                continue;
            for(int k=0; k<N; k++)
                A[k][j]=0;
            for(int k=0; k<M; k++)
                A[i][k]=0;
        }
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
        {
            for(int k=0; k<N; k++)
                C[i][j]|=A[k][j];
            for(int k=0; k<M; k++)
                C[i][j]|=A[i][k];
        }
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(B[i][j]!=C[i][j])
            {
                printf("NO\n");
                return 0;
            }
    printf("YES\n");
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            printf("%d%c", A[i][j], " \n"[j==M-1]);
    return 0;
}