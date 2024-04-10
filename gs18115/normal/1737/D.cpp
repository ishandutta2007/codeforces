#include<iostream>
#include<vector>
#include<queue>
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
const int mxn=510;
vector<pi>adj[mxn];
int w[mxn*mxn];
int dis[mxn][mxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t-->0)
    {
        int n,m;
        cin>>n>>m;
        vector<pi>ev;
        for(int i=0;i++<n;)
            for(int j=0;j++<n;)
                dis[i][j]=inf;
        for(int i=0;i++<n;)
            dis[i][i]=0;
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v>>w[i];
            adj[u].eb(v,i);
            adj[v].eb(u,i);
            dis[u][v]=dis[v][u]=1;
            ev.eb(u,v);
        }
        for(int i=0;i++<n;)
            for(int j=0;j++<n;)
                for(int k=0;k++<n;)
                    dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
        ll ans=INF;
        for(int i=0;i<m;i++)
        {
            int u=ev[i].fi,v=ev[i].se;
            ans=min(ans,(ll)w[i]*(dis[1][u]+dis[n][v]+1));
            ans=min(ans,(ll)w[i]*(dis[1][v]+dis[n][u]+1));
            for(int j=0;j++<n;)
                ans=min(ans,(ll)w[i]*(dis[1][j]+dis[j][n]+min(dis[v][j],dis[u][j])+2));
        }
        cout<<ans<<'\n';
        for(int i=0;i++<n;)
            adj[i].clear();
    }
    return 0;
}