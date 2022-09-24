#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF=1e18;
LL dp[1234567][4];
char S[1234567];
LL N,i;
LL A[1234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    cin>>S+1;
    for(i=1;i<=N;i++)
        cin>>A[i];
    dp[0][0]=0;
    dp[0][1]=dp[0][2]=dp[0][3]=INF;
    for(i=1;i<=N;i++)
    {
        if(S[i]=='h')
        {
            dp[i][0]=dp[i-1][0]+A[i];
            dp[i][1]=min(dp[i-1][0],dp[i-1][1]);
            dp[i][2]=dp[i-1][2];
            dp[i][3]=dp[i-1][3];
        }
        else if(S[i]=='a')
        {
            dp[i][0]=dp[i-1][0];
            dp[i][1]=dp[i-1][1]+A[i];
            dp[i][2]=min(dp[i-1][1],dp[i-1][2]);
            dp[i][3]=dp[i-1][3];
        }
        else if(S[i]=='r')
        {
            dp[i][0]=dp[i-1][0];
            dp[i][1]=dp[i-1][1];
            dp[i][2]=dp[i-1][2]+A[i];
            dp[i][3]=min(dp[i-1][2],dp[i-1][3]);
        }
        else if(S[i]=='d')
        {
            dp[i][0]=dp[i-1][0];
            dp[i][1]=dp[i-1][1];
            dp[i][2]=dp[i-1][2];
            dp[i][3]=dp[i-1][3]+A[i];
        }
        else
        {
            dp[i][0]=dp[i-1][0];
            dp[i][1]=dp[i-1][1];
            dp[i][2]=dp[i-1][2];
            dp[i][3]=dp[i-1][3];
        }
        dp[i][0]=min(dp[i][0],INF);
        dp[i][1]=min(dp[i][1],INF);
        dp[i][2]=min(dp[i][2],INF);
        dp[i][3]=min(dp[i][3],INF);
    }
    cout<<min({dp[N][0],dp[N][1],dp[N][2],dp[N][3]})<<endl;
    return 0;
}