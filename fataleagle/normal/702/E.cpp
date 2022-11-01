#include <bits/stdc++.h>

using namespace std;

int N;
long long K;
int F[41][100000];
long long G[41][100000];
int H[41][100000];

int main()
{
    scanf("%d%lld", &N, &K);
    for(int i=0; i<N; i++)
        scanf("%d", F[0]+i);
    for(int i=0; i<N; i++)
        scanf("%lld", G[0]+i), H[0][i]=G[0][i];
    for(int i=1; i<=33; i++)
        for(int j=0; j<N; j++)
        {
            F[i][j]=F[i-1][F[i-1][j]];
            G[i][j]=G[i-1][j]+G[i-1][F[i-1][j]];
            H[i][j]=min(H[i-1][j], H[i-1][F[i-1][j]]);
        }
    for(int i=0; i<N; i++)
    {
        int x=i;
        long long p=0;
        int q=0x3f3f3f3f;
        long long k=K;
        for(int j=33; j>=0; j--) if((1LL<<j)<=k)
            k-=1LL<<j, p+=G[j][x], q=min(q, H[j][x]), x=F[j][x];
        printf("%lld %d\n", p, q);
    }
    return 0;
}