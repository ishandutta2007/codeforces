#include<iostream>
#include<vector>
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
const ll mod=1e9+7;
int n,i;
ll v[100010];
vector<int>adj[100010];
vector<ll>d,c;
ll ans,ans2;
ll gcd(ll x,ll y)
{
    while(y>0)
        swap(x%=y,y);
    return x;
}
void dfs(int x,int p)
{
    vector<ll>tmp=d,tmp2=c;
    vector<ll>t1,t2;
    ll tt=ans2;
    for(int i=0;i<d.size();i++)
    {
        ll&t=d[i];
        ll p=gcd(t,v[x]);
        ans2=(ans2-c[i]*(t-p)%mod+mod)%mod;
        t=p;
    }
    d.eb(v[x]);
    c.eb(1);
    ans2+=v[x];
    t1.eb(d[0]);
    t2.eb(c[0]);
    for(int i=1;i<d.size();i++)
    {
        if(d[i]!=t1.back())
            t1.eb(d[i]),t2.eb(c[i]);
        else
            t2.back()+=c[i];
    }
    d=t1;
    c=t2;
    ans+=ans2;
    for(int t:adj[x])
        if(t!=p)
            dfs(t,x);
    d=tmp;
    c=tmp2;
    ans2=tt;  //rollback
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(i=0;i<n;i++)
        cin>>v[i];
    for(i=1;i<n;i++)
    {
        int s,e;
        cin>>s>>e;
        adj[--s].eb(--e);
        adj[e].eb(s);
    }
    dfs(0,-1);
    cout<<ans%mod<<endl;
    return 0;
}