#include <bits/stdc++.h>

using namespace std;

int N, T;
int A[100];
int X[100];
int B[2*100*100];
int dp1[2*100*100][100];
int dp2[100*100][100];
int cnt[100];

int main()
{
    scanf("%d%d", &N, &T);
    for(int i=0; i<N; i++)
    {
        scanf("%d", A+i);
        X[i]=A[i];
    }
    sort(X, X+N);
    for(int i=0; i<N; i++)
        A[i]=lower_bound(X, X+N, A[i])-X, cnt[A[i]]++;
    for(int i=0; i<2*N*N; i++)
        B[i]=A[i%N];
    dp1[0][B[0]]=1;
    for(int i=1; i<2*N*N; i++)
    {
        for(int j=0; j<N; j++)
            dp1[i][j]=dp1[i-1][j];
        for(int j=0; j<=B[i]; j++)
            dp1[i][B[i]]=max(dp1[i][B[i]], dp1[i-1][j]+1);
    }
    if(T<=2*N)
        return printf("%d\n", *max_element(dp1[N*T-1], dp1[N*T-1]+N)), 0;
    dp2[N*N-1][B[N*N-1]]=1;
    for(int i=N*N-2; i>=0; i--)
    {
        for(int j=0; j<N; j++)
            dp2[i][j]=dp2[i+1][j];
        for(int j=B[i]; j<N; j++)
            dp2[i][B[i]]=max(dp2[i][B[i]], dp2[i+1][j]+1);
    }
    int ans=0;
    for(int i=0; i<N; i++)
        ans=max(ans, cnt[i]*(T-2*N)+dp1[N*N-1][i]+dp2[0][i]);
    printf("%d\n", ans);
    return 0;
}