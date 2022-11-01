#include <bits/stdc++.h>

using namespace std;

const int MAX=100;
int N, K;
double P[20];
double dp[1<<20];
double ans[20];

int main()
{
    scanf("%d%d", &N, &K);
    for(int i=0; i<N; i++)
        scanf("%lf", P+i);
    for(int i=0; i<(1<<N); i++)
    {
        double s=0.0;
        for(int j=0; j<N; j++) if((i>>j)&1)
            s+=P[j];
        dp[i]=s/(1-s);
        if(s==1.0)
            dp[i]=0.0;
        if(__builtin_popcount(i)&1)
            dp[i]*=-1.0;
    }
    for(int i=0; i<N; i++)
        for(int j=0; j<(1<<N); j++) if(!((j>>i)&1))
            dp[j|(1<<i)]+=dp[j];
    for(int i=0; i<(1<<N); i++)
        if(__builtin_popcount(i)&1)
            dp[i]*=-1.0;
    for(int i=0; i<(1<<N); i++) if(__builtin_popcount(i)>=K)
        for(int j=0; j<N; j++) if(!((i>>j)&1))
            ans[j]+=dp[i];
    for(int i=0; i<N; i++)
    {
        if(P[i]<1e-9)
            printf("0.0 ");
        else if(P[i]>1-1e-9)
            printf("1.0 ");
        else
            printf("%.9f ", 1.0-P[i]*ans[i]);
    }
    printf("\n");
    return 0;
}