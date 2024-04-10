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
const int mod=998244353;
inline int add(int x,int y)
{
    return x+y<mod?x+y:x+y-mod;
}
inline int sub(int x,int y)
{
    return x<y?x+mod-y:x-y;
}
inline int mul(int x,int y)
{
    return(ll)x*y%mod;
}
inline int pw(int x,int y)
{
    int r=1;
    while(y>0)
    {
        if(y%2==1)
            r=mul(r,x);
        x=mul(x,x);
        y/=2;
    }
    return r;
}
vector<pair<int,pi> >adj[200010];
int curp[200010],curq[200010];
int maxq[200010];
int curd,hap;
vector<int>pdiv[200010];
void dfs(int x,int p)
{
    hap=add(hap,curd);
    for(auto&t:adj[x])
    {
        if(t.fi==p)
            continue;
        for(int&tt:pdiv[t.se.fi])
        {
            if(curq[tt]==0)
                curp[tt]++;
            else
                curq[tt]--;
        }
        for(int&tt:pdiv[t.se.se])
        {
            if(curp[tt]==0)
                curq[tt]++;
            else
                curp[tt]--;
        }
        for(int&tt:pdiv[t.se.se])
            maxq[tt]=max(maxq[tt],curq[tt]);
        int pcurd=curd;
        curd=mul(curd,mul(t.se.fi,pw(t.se.se,mod-2)));
        dfs(t.fi,x);
        curd=pcurd;
        for(int&tt:pdiv[t.se.se])
        {
            if(curq[tt]==0)
                curp[tt]++;
            else
                curq[tt]--;
        }
        for(int&tt:pdiv[t.se.fi])
        {
            if(curp[tt]==0)
                curq[tt]++;
            else
                curp[tt]--;
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int>prime;
    vector<bool>sieve(200010,1);
    for(int i=2;i<200010;i++)
    {
        if(!sieve[i])
            continue;
        prime.eb(i);
        for(int j=i;j<200010;j+=i)
        {
            sieve[j]=0;
            int k=j;
            while(k%i==0)
            {
                pdiv[j].eb(i);
                k/=i;
            }
        }
    }
    int t=0;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            int u,v,x,y;
            cin>>u>>v>>x>>y;
            adj[u].eb(v,pi(y,x));
            adj[v].eb(u,pi(x,y));
        }
        curd=1,hap=0;
        int hap2=1;
        dfs(1,0);
        for(int i=1;i<=n;i++)
            for(int j=0;j<maxq[i];j++)
                hap=mul(hap,i),hap2=mul(hap2,i);
        cout<<hap<<'\n';
        for(int i=0;i<=n;i++)
            curp[i]=curq[i]=maxq[i]=0,adj[i].clear();
    }
    return 0;
}