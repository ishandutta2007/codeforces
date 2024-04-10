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
int dp[200010][2][2][2][2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int>cv;
        for(int i=0;i<n;i++)
            cv.eb(s[i]=='L'?0:1);
        for(int i=0;i<=n;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    for(int l=0;l<2;l++)
                        for(int m=0;m<2;m++)
                            dp[i][j][k][l][m]=n;
        dp[2][0][1][0][1]=(cv[0]^0)+(cv[1]^0);
        dp[2][0][0][1][0]=(cv[0]^0)+(cv[1]^1);
        dp[2][1][0][0][0]=(cv[0]^1)+(cv[1]^0);
        dp[2][1][1][1][1]=(cv[0]^1)+(cv[1]^1);
        for(int i=2;i<n;i++)
        {
            for(int j=0;j<2;j++)
            {
                for(int k=0;k<2;k++)
                {
                    for(int l=0;l<2;l++)
                    {
                        for(int m=0;m<2;m++)
                        {
                            //cout<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<m<<' '<<dp[i][j][k][l][m]<<endl;
        dp[i+1][j][k][l^1][0]=min(dp[i+1][j][k][l^1][0],dp[i][j][k][l][m]+(cv[i]^l^1));
        if(m==0)
            dp[i+1][j][k][l][1]=min(dp[i+1][j][k][l][1],dp[i][j][k][l][m]+(cv[i]^l));
                        }
                    }
                }
            }
        }
        int ans=n;
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                for(int l=0;l<2;l++)
                    for(int m=0;m<2;m++)
                        if(j!=l||k+m==0)
                            ans=min(ans,dp[n][j][k][l][m]);
        cout<<ans;
        cout<<'\n';
    }
    cout.flush();
    return 0;
}