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
const int mxn=300010;
int dep[mxn],pa[mxn];
vector<int>adj[mxn];
int fdp[mxn],dp[mxn];
int mn[mxn],mn2[mxn];
inline void mnpr(int x,int y)
{
    if(y<mn[x])
        mn2[x]=mn[x],mn[x]=y;
    else if(y<mn2[x])
        mn2[x]=y;
    return;
}
void dfs1(int x,int p)
{
    pa[x]=p;
    dep[x]=dep[p]+1;
    fdp[x]=0;
    mn[x]=x;
    mn2[x]=inf;
    for(int&t:adj[x])
        if(t!=p)
            dfs1(t,x),mnpr(x,mn[t]),fdp[x]^=fdp[t]+1;
    return;
}
int cdp[mxn];
bool chk[mxn];
void dfs2(int x,int p)
{
    for(int&t:adj[x])
    {
        if(t==p)
            continue;
        int cd=dp[x]^(fdp[t]+1);
        dp[t]=(cd+1)&fdp[t];
        if(mn[x]==mn[t])
            mnpr(t,mn2[x]);
        else
            mnpr(t,mn[x]);
        dfs2(t,x);
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    dfs1(1,0);
    dp[1]=fdp[1];
    dfs2(1,0);
    vector<int>ans;
    ans.eb(n%2+1);
    int sl=(n-1)%2;
    int nim=0;
    vector<vector<int> >vv(n+1);
    for(int i=1;i++<n;)
        vv[mn2[i]].eb(i);
    for(int i=0;i++<n;)
        sort(all(vv[i]),[&](const int&x,const int&y){return dep[x]>dep[y];});
    for(int i=n;i>1;i--)
    {
        for(int&x:vv[i])
        {
            nim^=cdp[x];
            int t=pa[x];
            nim^=cdp[t];
            cdp[t]^=cdp[x]+1;
            nim^=cdp[t];
            sl^=1;
        }
        ans.eb((nim^sl)==0?2:1);
    }
    reverse(all(ans));
    for(int&t:ans)
        cout<<t;
    cout<<endl;
    return 0;
}