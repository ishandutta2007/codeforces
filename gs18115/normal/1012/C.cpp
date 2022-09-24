#include<iostream>
using namespace std;
typedef long long LL;
const LL INF=1e18;
const LL MAXN=5010;
LL N,i,j;
LL A[MAXN],B[MAXN][MAXN],C[MAXN];
LL dp[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    A[0]=A[N+1]=-INF;
    for(i=1;i<=N;i++)
        cin>>A[i];
    for(i=1;i<=N;i++)
        C[i]=max(0LL,A[i-1]-A[i]+1LL)+max(0LL,A[i+1]-A[i]+1LL);
    for(i=1;i<=N;i++)
        dp[i]=INF;
    for(i=1;i<=N;i++)
    {
        for(j=1;j<<1<=N+1;j++)
            B[i][j]=dp[j-1]+C[i];
        if(i>2)
            for(j=2;j<<1<=N+1;j++)
                B[i][j]=min(B[i][j],B[i-2][j-1]-max(0LL,A[i-1]-A[i-2]+1LL)+max(0LL,A[i-1]-min(A[i],A[i-2])+1LL)+max(0LL,A[i+1]-A[i]+1LL));
        if(i>1)
        {
            for(j=1;j<<1<=N+1;j++)
                dp[j]=min(dp[j],B[i-1][j]);
        }
    }
    for(i=1;i<<1<=N+1;i++)
        cout<<min(dp[i],B[N][i])<<' ';
    cout<<endl;
    return 0;
}