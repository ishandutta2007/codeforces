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
const int mxn=200010;
vector<int>adj[mxn];
int ind[mxn];
int dp[mxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin>>tc;
    for(int tci=0;tci++<tc;)
    {
        int n;
        cin>>n;
        for(int i=0;i++<n;)
            ind[i]=0,adj[i].clear(),dp[i]=1;
        for(int i=0;i++<n;)
        {
            int k;
            cin>>k;
            for(int j=0;j<k;j++)
            {
                int t;
                cin>>t;
                adj[t].eb(i);
                ind[i]++;
            }
        }
        vector<int>nc;
        for(int i=0;i++<n;)
            if(ind[i]==0)
                nc.eb(i);
        int cnt=0;
        int mx=0;
        while(!nc.empty())
        {
            int cur=nc.back();
            nc.pop_back();
            mx=max(mx,dp[cur]);
            cnt++;
            for(int&t:adj[cur])
            {
                dp[t]=max(dp[t],dp[cur]+(cur<t?0:1));
                if(--ind[t]==0)
                    nc.eb(t);
            }
        }
        if(cnt!=n)
            mx=-1;
        cout<<mx<<'\n';
    }
    return 0;
}