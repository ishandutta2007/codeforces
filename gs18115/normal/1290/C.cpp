#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define semicolon 
#define ryan bear
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
int pa[300010],tp[300010];
int sz[300010],ct[300010];
int fix[300010];
int ans;
pi par(int x)
{
    if(pa[x]==-1)
        return pi(x,0);
    pi t=par(pa[x]);
    return pi(t.fi,t.se^tp[x]);
}
inline int calc(int x)
{
    if(fix[x]!=-1)
        return fix[x]==1?sz[x]-ct[x]:ct[x];
    return min(ct[x],sz[x]-ct[x]);
}
inline void uni(int x,int y,bool inv)
{
    pi xt=par(x);
    pi yt=par(y);
    if(xt.fi==yt.fi)
        return;
    ans-=calc(xt.fi)+calc(yt.fi);
    if(sz[xt.fi]>sz[yt.fi])
        swap(xt,yt);
    pa[xt.fi]=yt.fi;
    if(inv^xt.se^yt.se)
    {
        tp[xt.fi]=1,ct[xt.fi]=sz[xt.fi]-ct[xt.fi];
        if(fix[xt.fi]!=-1)
            fix[xt.fi]=1^fix[xt.fi];
    }
    ct[yt.fi]+=ct[xt.fi];
    sz[yt.fi]+=sz[xt.fi];
    if(fix[xt.fi]!=-1)
        fix[yt.fi]=fix[xt.fi];
    ans+=calc(yt.fi);
    return;
}
vector<int>v[300010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    vector<int>off(n);
    fill(pa,pa+k,-1);
    fill(fix,fix+k,-1);
    fill(sz,sz+k,1);
    for(int i=0;i<n;i++)
    {
        char c;
        cin>>c;
        off[i]='1'-c;
    }
    for(int i=0;i<k;i++)
    {
        int m;
        cin>>m;
        for(int j=0;j<m;j++)
        {
            int t;
            cin>>t;
            v[--t].eb(i);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(v[i].size()==1)
        {
            pi t=par(v[i][0]);
            ans-=calc(t.fi);
            fix[t.fi]=off[i]^t.se;
            ans+=calc(t.fi);
        }
        else if(v[i].size()==2)
            uni(v[i][0],v[i][1],off[i]);
        cout<<ans<<'\n';
    }
    cout.flush();
    return 0;
}