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
int dp[100010];
int dpmx[100010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r,n;
    cin>>r>>n;
    vector<pair<int,pi> >v(n);
    for(auto&t:v)
        cin>>t.fi>>t.se.fi>>t.se.se;
    v.insert(v.begin(),pair<int,pi>(0,pi(1,1)));
    for(int i=0;i++<n;)
    {
        dp[i]=-inf;
        for(int j=i;j-->0;)
        {
            if(v[i].fi-v[j].fi>=r*2-2)
            {
                dp[i]=max(dp[i],dpmx[j]+1);
                break;
            }
            if(v[i].fi-v[j].fi>=abs(v[i].se.fi-v[j].se.fi)+abs(v[i].se.se-v[j].se.se))
                dp[i]=max(dp[i],dp[j]+1);
        }
        dpmx[i]=max(dpmx[i-1],dp[i]);
    }
    cout<<dpmx[n]<<endl;
    return 0;
}