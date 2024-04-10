//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,t;
double p,dp[2111][2111];
double kissme(double x,int k)
{
    double ans=1;
    while(k>0)
    {
        if(k&1)ans=ans*x;
        x=x*x;
        k=k>>1;
    }
    return ans;
}
int main()
{
    cin>>n>>p>>t;
    double ans=0;
    dp[0][0]=1;
    for(int i=0;i<=n;i++)
    {
        for(int j=1;j<=t;j++)
        {
            if(i>0)dp[i][j]=dp[i-1][j-1]*p;
            if(i==n)dp[i][j]+=dp[i][j-1];else dp[i][j]+=dp[i][j-1]*(1-p);
        }
    }
    for(int i=0;i<=n;i++)ans+=1.0*i*dp[i][t];
    cout<<fixed<<setprecision(10)<<ans<<endl;
    return 0;
}