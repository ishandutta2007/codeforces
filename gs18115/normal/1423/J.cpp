#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
const int mod=1e9+7;
inline int add(int x,int y)
{
    return x+y<mod?x+y:x+y-mod;
}
int dp[61][3];
inline int solve(ll n)
{
    for(int i=0;i<=60;i++)
        for(int j=0;j<3;j++)
            dp[i][j]=0;
    dp[0][0]=1;
    for(int i=0;i<60;i++)
    {
        const int cur=n>>i&1;
        for(int j=0;j<3;j++)
        {
            int c1=dp[i][j];
            int c2=add(c1,add(c1,c1));
            if(cur==j%2)
            {
                dp[i+1][j/2]=add(dp[i+1][j/2],c1);
                if(i>0)
                    dp[i+1][1+j/2]=add(dp[i+1][1+j/2],i>1?c2:c1);
            }
            else
            {
                dp[i+1][(j-cur+1)/2]=add(dp[i+1][(j-cur+1)/2],i==0?c1:(i>1?c2:add(c1,c1)));
                if(i>1)
                    dp[i+1][(j-cur+3)/2]=add(dp[i+1][(j-cur+3)/2],c1);
            }
        }
    }
    return dp[60][0];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t-->0)
    {
        ll n;
        cin>>n;
        cout<<solve(n)<<'\n';
    }
    return 0;
}