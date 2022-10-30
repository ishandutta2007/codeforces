#include <bits/stdc++.h>

using namespace std;

int K;
bool adj[100][100];

int main()
{
    scanf("%d", &K);
    int N=0;
    for(int i=1; i<=100; i++)
    {
        if(i*(i-1)*(i-2)/6>K)
        {
            N=i-1;
            break;
        }
    }
    K-=N*(N-1)*(N-2)/6;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            adj[i][j]=i!=j;
    while(K>0 && N<100)
    {
        int M=N;
        for(int i=1; i<=N; i++) if(i*(i-1)/2>K)
        {
            M=i-1;
            break;
        }
        K-=M*(M-1)/2;
        for(int i=0; i<M; i++)
            adj[N][i]=adj[i][N]=true;
        N++;
    }
    printf("%d\n", N);
    for(int i=0; i<N; i++, printf("\n"))
        for(int j=0; j<N; j++)
            printf("%d", adj[i][j]);
    return 0;
}