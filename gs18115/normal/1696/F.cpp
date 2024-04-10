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
void dfs(int x,int p,vector<vector<int> >&adj,vector<int>&dis)
{
    if(p==-1)
        dis[x]=0;
    else
        dis[x]=dis[p]+1;
    for(int&t:adj[x])
    {
        if(dis[t]==-1)
            dfs(t,x,adj,dis);
        else if(t!=p)
            dis[0]=-2; //cycle;
        if(dis[0]==-2)
            break;
    }
    return;
}
int v[105][105][105];
int pa[10005],sz[10005];
int par(int x)
{
    if(pa[x]==-1)
        return x;
    return pa[x]=par(pa[x]);
}
void uni(int x,int y)
{
    x=par(x);
    y=par(y);
    if(x==y)
        return;
    pa[x]=y;
    sz[y]+=sz[x];
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc=1;
    cin>>tc;
    while(tc-->0)
    {
        int n;
        cin>>n;
        for(int i=0;i<n*n;i++)
            pa[i]=-1,sz[i]=1;
        for(int i=0;i<n;i++)
            for(int k=0;k<n;k++)
                v[i][i][k]=1;
        vector<int>cnt(n,0),sum(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                string s;
                cin>>s;
                for(int k=0;k<n;k++)
                    v[i][j][k]=v[j][i][k]=s[k]-'0';
            }
        }
        auto make=[&](int i,int j)->int
        {
            if(i>j)
                return j*n+i;
            return i*n+j;
        };
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    if(v[i][j][k]==1)
                        uni(make(i,k),make(j,k));
        vector<vector<int> >ev(n*n);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                ev[par(make(i,j))].eb(make(i,j));
        auto tst=[&](vector<vector<int> >&adj)->int
        {
            vector<vector<int> >dis(n);
            for(int i=0;i<n;i++)
            {
                dis[i].resize(n,-1);
                dfs(i,-1,adj,dis[i]);
                if(dis[i][0]==-2)
                    return 0;
                for(int j=0;j<n;j++)
                    if(dis[i][j]==-1)
                        return 0; //not connected
            }
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    for(int k=0;k<n;k++)
                        if(v[i][j][k]!=(dis[i][k]==dis[j][k]?1:0))
                            return 0;
            return 1;
        };
        int f=0;
        for(int i=0;f==0&&i<n;i++)
        {
            for(int j=i+1;f==0&&j<n;j++)
            {
                int tar=make(i,j);
                if((int)ev[tar].size()==n-1)
                {
                    vector<vector<int> >adj(n);
                    auto&tv=ev[tar];
                    for(int&t:tv)
                    {
                        int x=t/n;
                        int y=t%n;
                        adj[x].eb(y);
                        adj[y].eb(x);
                    }
                    if(tst(adj)==1)
                    {
                        cout<<"Yes\n";
                        for(int i=0;i<n;i++)
                            for(int&t:adj[i])
                                if(t>i)
                                    cout<<i+1<<' '<<t+1<<'\n';
                        f=1;
                    }
                }
            }
        }
        if(f==0)
            cout<<"No\n";
    }
    return 0;
}