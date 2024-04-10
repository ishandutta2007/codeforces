#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const ll inf=1e18;
int n,i,j;
ll A[100010];
int pa[125];
vector<int>adj[125];
vector<int>v[66];
ll dis[125];
queue<int>q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>A[i];
        if(A[i]==0)
        {
            n--,i--;
            continue;
        }
        for(j=0;j<60;j++)
            if(A[i]>>j&1ll)
                v[j].eb(i);
    }
    for(i=0;i<60;i++)
        if(v[i].size()>2)
            return cout<<3<<endl,0;
    for(i=0;i<60;i++)
    {
        if(v[i].size()==2)
        {
            adj[v[i][0]].eb(v[i][1]);
            adj[v[i][1]].eb(v[i][0]);
        }
    }
    for(i=0;i<n;i++)
    {
        sort(all(v[i]));
        v[i].erase(unique(all(v[i])),v[i].end());
    }
    ll ans=inf;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            dis[j]=inf;
        dis[i]=0;
        q.push(i);
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            for(int h:adj[t])
            {
                if(dis[h]==inf)
                {
                    dis[h]=dis[t]+1;
                    pa[h]=t;
                    q.push(h);
                }
                else if(pa[t]!=h&&pa[h]!=t&&dis[t]+dis[h]+1>2)
                    ans=min(ans,dis[t]+dis[h]+1);
            }
        }
    }
    if(ans==inf)
        ans=-1;
    cout<<ans<<endl;
    return 0;
}