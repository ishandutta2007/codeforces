#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF=1e18;
const LL MOD=1e9+7;
LL N,L,R,i;
LL N1,N2,N3;
LL dp[234567][3];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>L>>R;
    N1=(R+5)/3-(L+4)/3;
    N2=(R+4)/3-(L+3)/3;
    N3=(R+3)/3-(L+2)/3;
    dp[0][0]=1;
    for(i=1;i<=N;i++)
    {
        dp[i][0]=(dp[i-1][0]*N3+dp[i-1][1]*N2+dp[i-1][2]*N1)%MOD;
        dp[i][1]=(dp[i-1][0]*N1+dp[i-1][1]*N3+dp[i-1][2]*N2)%MOD;
        dp[i][2]=(dp[i-1][0]*N2+dp[i-1][1]*N1+dp[i-1][2]*N3)%MOD;
    }
    cout<<dp[N][0]<<endl;
    return 0;
}