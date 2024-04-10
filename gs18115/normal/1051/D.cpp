#include<iostream>
using namespace std;
typedef long long LL;
const LL MOD=998244353;
LL dp[1234][2345][5];
LL N,K,i,j;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>K;
    dp[1][1][0]=dp[1][2][1]=dp[1][2][2]=dp[1][1][3]=1;
    for(i=2;i<=N;i++)
    {
        for(j=1;j<=K;j++)
        {
            dp[i][j][0]+=dp[i-1][j][0];
            dp[i][j][0]+=dp[i-1][j][1];
            dp[i][j][0]+=dp[i-1][j][2];
            dp[i][j+1][0]+=dp[i-1][j][3];
            dp[i][j+1][1]+=dp[i-1][j][0];
            dp[i][j][1]+=dp[i-1][j][1];
            dp[i][j+2][1]+=dp[i-1][j][2];
            dp[i][j+1][1]+=dp[i-1][j][3];
            dp[i][j+1][2]+=dp[i-1][j][0];
            dp[i][j+2][2]+=dp[i-1][j][1];
            dp[i][j][2]+=dp[i-1][j][2];
            dp[i][j+1][2]+=dp[i-1][j][3];
            dp[i][j+1][3]+=dp[i-1][j][0];
            dp[i][j][3]+=dp[i-1][j][1];
            dp[i][j][3]+=dp[i-1][j][2];
            dp[i][j][3]+=dp[i-1][j][3];
            dp[i][j][0]%=MOD;
            dp[i][j][1]%=MOD;
            dp[i][j][2]%=MOD;
            dp[i][j][3]%=MOD;
            dp[i][j+1][0]%=MOD;
            dp[i][j+1][1]%=MOD;
            dp[i][j+1][2]%=MOD;
            dp[i][j+1][3]%=MOD;
            dp[i][j+2][0]%=MOD;
            dp[i][j+2][1]%=MOD;
            dp[i][j+2][2]%=MOD;
            dp[i][j+2][3]%=MOD;
        }
    }
    cout<<(dp[N][K][0]+dp[N][K][1]+dp[N][K][2]+dp[N][K][3])%MOD<<endl;
    return 0;
}