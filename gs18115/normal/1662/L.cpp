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
struct fen
{
    vector<int>tr;
    vector<ll>posv;
    int n;
    inline void init()
    {
        sort(all(posv));
        posv.erase(unique(all(posv)),posv.end());
        n=posv.size();
        tr.resize(n,-inf);
        return;
    }
    inline void upd(ll y,int p)
    {
        int i=upper_bound(all(posv),y)-posv.begin();
        for(;i<=n;i+=i&-i)
            tr[i-1]=max(tr[i-1],p);
        return;
    }
    inline int qry(ll y)
    {
        int ret=-inf;
        int i=upper_bound(all(posv),y)-posv.begin();
        for(;i>0;i-=i&-i)
            ret=max(ret,tr[i-1]);
        return ret;
    }
};
struct fen2d
{
    fen tr[200010];
    vector<ll>posv;
    int n;
    inline void initpos()
    {
        sort(all(posv));
        posv.erase(unique(all(posv)),posv.end());
        n=posv.size();
        return;
    }
    inline void init(ll x,ll y)
    {
        int i=upper_bound(all(posv),x)-posv.begin();
        for(;i<=n;i+=i&-i)
            tr[i-1].posv.eb(y);
        return;
    }
    inline void init()
    {
        for(int i=0;i<n;i++)
            tr[i].init();
        return;
    }
    inline void upd(ll x,ll y,int p)
    {
        int i=upper_bound(all(posv),x)-posv.begin();
        for(;i<=n;i+=i&-i)
            tr[i-1].upd(y,p);
        return;
    }
    inline int qry(ll x,ll y)
    {
        int ret=-inf;
        int i=upper_bound(all(posv),x)-posv.begin();
        for(;i>0;i-=i&-i)
            ret=max(ret,tr[i-1].qry(y));
        return ret;
    }
}ft1,ft2;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    ll v;
    cin>>n>>v;
    vector<pl>ta(n);
    for(pl&t:ta)
        cin>>t.fi;
    for(pl&t:ta)
        cin>>t.se;
    for(pl&t:ta)
        ft1.posv.eb(t.se),ft2.posv.eb(-t.se);
    ft1.posv.eb(0);
    ft2.posv.eb(0);
    ft1.initpos();
    ft2.initpos();
    ft1.init(0,0);
    ft2.init(0,0);
    for(int i=0;i<n;i++)
    {
        ll t=ta[i].fi;
        ll a=ta[i].se;
        ll x1=a;
        ll y1=t*v-a;
        ll x2=-a;
        ll y2=t*v+a;
        ft1.init(x1,y1);
        ft2.init(x2,y2);
    }
    ft1.init();
    ft2.init();
    ft1.upd(0,0,0);
    ft2.upd(0,0,0);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ll t=ta[i].fi;
        ll a=ta[i].se;
        ll x1=a;
        ll y1=t*v-a;
        ll x2=-a;
        ll y2=t*v+a;
        int cur=max(ft1.qry(x1,y1),ft2.qry(x2,y2))+1;
        ft1.upd(x1,y1,cur);
        ft2.upd(x2,y2,cur);
        ans=max(ans,cur);
    }
    cout<<ans<<endl;
    return 0;
}