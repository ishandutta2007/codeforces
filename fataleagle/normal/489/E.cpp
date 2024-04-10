#include <bits/stdc++.h>

using namespace std;

int N, L;
int A[1001], B[1001];
int path[1001];
double F[1001][1001];
double dp[1001];

void trace(int x)
{
    if(x)
    {
        trace(path[x]);
        printf("%d%c", x, " \n"[x==N]);
    }
}

int main()
{
    scanf("%d%d", &N, &L);
    for(int i=1; i<=N; i++)
        scanf("%d%d", A+i, B+i);
    for(int i=0; i<=N; i++)
        for(int j=i+1; j<=N; j++)
            F[i][j]=sqrt(abs((A[j]-A[i])-L));
    double lo=0.0, mid, hi=1e9;
    while(fabs(lo-hi)>1e-9)
    {
        mid=(lo+hi)/2;
        for(int i=1; i<=N; i++)
            dp[i]=1e18;
        dp[0]=0;
        for(int i=0; i<=N; i++)
            for(int j=i+1; j<=N; j++)
                dp[j]=min(dp[j], dp[i]+F[i][j]-mid*B[j]);
        if(dp[N]>=0)
            lo=mid;
        else
            hi=mid;
    }
    for(int i=1; i<=N; i++)
        dp[i]=1e18;
    dp[0]=0;
    for(int i=0; i<=N; i++)
        for(int j=i+1; j<=N; j++)
        {
            double c=dp[i]+F[i][j]-lo*B[j];
            if(c<dp[j])
                dp[j]=c, path[j]=i;
        }
    trace(N);
    return 0;
}