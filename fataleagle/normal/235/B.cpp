#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int N;
double A[100001];
double dp[100001];

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%lf", A+i);
    double ans=0.0;
    for(int i=1; i<=N; i++)
        ans+=A[i]+2*(dp[i]=(dp[i-1]+A[i-1])*A[i]);
    printf("%.9f\n", ans);
    return 0;
}