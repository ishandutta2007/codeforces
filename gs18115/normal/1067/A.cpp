#include<iostream>
using namespace std;
typedef long long LL;
const LL MOD=998244353;
const LL MAXN=1e5+10;
LL N,i,j;
LL ans;
LL A[MAXN];
LL S[205][2];
LL dp[MAXN][205][2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
        cin>>A[i];
    if(N==1)
    {
        if(A[0]==-1)
            cout<<200;
        else
            cout<<1;
        cout<<endl;
        return 0;
    }
    if(A[0]==-1)
        for(i=0;i<=200;i++)
            dp[0][i][0]=1;
    else
        dp[0][A[0]][0]=1;
    for(i=1;i<N;i++)
    {
        if(A[i]==-1)
        {
            for(j=1;j<=200;j++)
            {
                S[j][0]=(S[j-1][0]+dp[i-1][j][0])%MOD;
                S[j][1]=(S[j-1][1]+dp[i-1][j][1])%MOD;
            }
            for(j=1;j<=200;j++)
            {
                dp[i][j][0]=(S[j-1][0]+S[j-1][1])%MOD;
                dp[i][j][1]=(dp[i-1][j][0]+S[200][1]-S[j-1][1]+MOD)%MOD;
            }
        }
        else
        {
            for(j=1;j<A[i];j++)
                dp[i][A[i]][0]=(dp[i][A[i]][0]+dp[i-1][j][0]+dp[i-1][j][1])%MOD;
            dp[i][A[i]][1]=(dp[i][A[i]][1]+dp[i-1][A[i]][0])%MOD;
            for(j=A[i];j<=200;j++)
                dp[i][A[i]][1]=(dp[i][A[i]][1]+dp[i-1][j][1])%MOD;
        }
    }
    for(i=1;i<=200;i++)
        ans=(ans+dp[N-1][i][1])%MOD;
    cout<<ans<<endl;
    return 0;
}