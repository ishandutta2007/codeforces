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
const ll INF=1e18+7;
inline pi query(vector<int>&v)
{
    sort(all(v));
    v.erase(unique(all(v)),v.end());
    cout<<"? "<<v.size();
    for(int&t:v)
        cout<<' '<<t;
    cout<<endl;
    int a,b;
    cin>>a>>b;
    v.clear();
    if(a==-1)
        return pi(1/0,1/0);
    return pi(a,b);
}
vector<int>adj[1010];
int md;
void dfs0(int x,int p,int dp)
{
    md=max(md,dp);
    for(int&t:adj[x])
        if(t!=p)
            dfs0(t,x,dp+1);
    return;
}
void dfs(int x,int p,int dp,int d,vector<int>&v)
{
    if(dp>=d)
        v.eb(x);
    for(int&t:adj[x])
        if(t!=p)
            dfs(t,x,dp+1,d,v);
    return;
}
void dfs2(int x,int p,int dp,int d,vector<int>&v)
{
    if(dp==d)
        v.eb(x);
    for(int&t:adj[x])
        if(t!=p)
            dfs2(t,x,dp+1,d,v);
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin>>tc;
    while(tc-->0)
    {
        int n;
        cin>>n;
        for(int i=0;i++<n;)
            adj[i].clear();
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].eb(v);
            adj[v].eb(u);
        }
        vector<int>v;
        for(int i=0;i++<n;)
            v.eb(i);
        pi qr=query(v);
        int rt=qr.fi;
        int d=qr.se;
        md=0;
        dfs0(rt,0,0);
        int s=(d+1)/2;
        int e=min(md,d);
        int qp=-1;
        while(s<=e)
        {
            int m=s+(e-s)/2;
            v.clear();
            dfs(rt,0,0,m,v);
            qr=query(v);
            if(qr.se==d)
                qp=qr.fi,s=m+1;
            else
                e=m-1;
        }
        v.clear();
        dfs2(qp,0,0,d,v);
        int qp2=query(v).fi;
        if(qp2<qp)
            swap(qp,qp2);
        cout<<"! "<<qp<<' '<<qp2<<endl;
        string ans;
        cin>>ans;
    }
    return 0;
}