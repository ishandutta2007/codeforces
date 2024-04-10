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
int pa[200010],pr[200010],sz[200010];
inline pi par(int x)
{
    int y=0;
    while(pa[x]!=0)
        y^=pr[x],x=pa[x];
    return pi(x,y);
}
vector<pair<int,pair<int*,int> > >rbv;
inline void rb(int p)
{
    while(!rbv.empty()&&rbv.back().fi==p)
        *rbv.back().se.fi=rbv.back().se.se,rbv.pop_back();
    return;
}
inline void uni(int x,int y,int p)
{
    int odd=par(x).se^par(y).se;
    x=par(x).fi;
    y=par(y).fi;
    if(x==y)
        return;
    if(sz[x]>sz[y])
        swap(x,y);
    rbv.eb(p,pair<int*,int>(sz+y,sz[y]));
    sz[y]+=sz[x];
    rbv.eb(p,pair<int*,int>(pa+x,0));
    pa[x]=y;
    pr[x]=odd^1;
    return;
}
int ans[200010];
vector<pi>edge;
void dnc(int n,int s,int e,int mx)
{
    if(s>e)
        return;
    int m=s+(e-s)/2;
    if(mx==inf)
    {
        ans[m]=inf;
        dnc(n+1,s,m-1,mx);
        dnc(n+1,m+1,e,mx);
        return;
    }
    ans[m]=m;
    for(int i=s;i<m;i++)
    {
        if(par(edge[i].fi)==par(edge[i].se))
            ans[m]=inf;
        uni(edge[i].fi,edge[i].se,n);
    }
    if(ans[m]==m)
    {
        for(int i=mx-1;i>=m;i--)
        {
            if(par(edge[i].fi)==par(edge[i].se))
            {
                ans[m]=i+1;
                break;
            }
            uni(edge[i].fi,edge[i].se,n+1);
        }
    }
    rb(n+1);
    if(m<(int)edge.size())
    {
        if(par(edge[m].fi)==par(edge[m].se))
            dnc(n+1,m+1,e,inf);
        else
            uni(edge[m].fi,edge[m].se,n),dnc(n+1,m+1,e,ans[m]==inf?inf:mx);
    }
    rb(n);
    for(int i=mx-1;i>=ans[m];i--)
        uni(edge[i].fi,edge[i].se,n);
    dnc(n+1,s,m-1,ans[m]==inf?mx:ans[m]);
    rb(n);
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i++<n;)
        sz[i]=1;
    edge.resize(m);
    for(pi&t:edge)
        cin>>t.fi>>t.se;
    vector<pi>qv(q);
    vector<int>cv;
    for(pi&t:qv)
        cin>>t.fi>>t.se,t.fi--;
    dnc(1,0,m,m);
    for(pi&t:qv)
        cout<<(t.se<ans[t.fi]?"YES\n":"NO\n");
    cout.flush();
    return 0;
}