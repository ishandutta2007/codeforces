#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
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
vector<int>adj[200010];
vector<int>adj2[200010];
int sz[200010];
bool chk[100010];
unordered_map<int,bool>chk2[100010];
inline void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i++<n;)
        adj[i].clear(),sz[i]=0,chk[i]=0,adj2[i].clear(),chk2[i].clear();
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].eb(v);
        adj[v].eb(u);
        chk2[u][v]=chk2[v][u]=1;
        sz[u]++,sz[v]++;
    }
    if((ll)k*(k-1)>m*2)
    {
        cout<<-1<<'\n';
        return;
    }
    for(int i=0;i++<n;)
        for(int&t:adj[i])
            if(sz[t]>=k-1)
                adj2[i].eb(t);
    priority_queue<pi,vector<pi>,greater<pi> >pq;
    for(int i=0;i++<n;)
        if(sz[i]<k)
            pq.ep(sz[i],i);
    while(!pq.empty())
    {
        int x=pq.top().se;
        pq.pop();
        if(chk[x])
            continue;
        chk[x]=1;
        if(sz[x]==k-1)
        {
            vector<int>cliq(1,x);
            for(int&t:adj[x])
                if(!chk[t])
                    cliq.eb(t);
            bool flag=0;
            for(int i1=0;i1<(int)cliq.size();i1++)
            {
                for(int i2=i1+1;i2<(int)cliq.size();i2++)
                {
                    if(!chk2[cliq[i1]][cliq[i2]])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag)
                    break;
            }
            if(!flag)
            {
                cout<<2<<'\n';
                for(int&t:cliq)
                    cout<<t<<' ';
                cout<<'\n';
                return;
            }
        }
        for(int&t:adj[x])
        {
            if(--sz[t]<k)
                if(!chk[t])
                    pq.ep(sz[t],t);
        }
    }
    vector<int>vv;
    for(int i=0;i++<n;)
    {
        if(!chk[i])
            vv.eb(i);
    }
    if(!vv.empty())
    {
        cout<<1<<' '<<vv.size()<<'\n';
        for(int&t:vv)
            cout<<t<<' ';
        cout<<'\n';
    }
    else
        cout<<-1<<'\n';
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t-->0)
        solve();
    return 0;
}