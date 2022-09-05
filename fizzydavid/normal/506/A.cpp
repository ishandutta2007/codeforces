//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,d,g[30111],dp[666][30611],ans;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>d;int x;
    for(int i=1;i<=n;i++){cin>>x;g[x]++;}
    for(int i=1;i<=30000;i++)for(int j=1;j<=600;j++)dp[j][i]=-INF;
    dp[300][d]=0;
    for(int i=d;i<=30000;i++)
    {
        for(int j=1;j<=600;j++)
        {
            if(dp[j][i]!=-INF)
            {
                dp[j][i]+=g[i];int v=dp[j][i];ans=max(ans,v);
                if(i+j-1+d-300<=30000)dp[j-1][i+j-1+d-300]=max(dp[j-1][i+j-1+d-300],v);
                if(i+j+d-300<=30000)dp[j][i+j+d-300]=max(dp[j][i+j+d-300],v);
                if(i+j+1+d-300<=30000)dp[j+1][i+j+1+d-300]=max(dp[j+1][i+j+1+d-300],v);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}