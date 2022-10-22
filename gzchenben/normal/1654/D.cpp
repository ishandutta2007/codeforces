#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const long long mod = 998244353;
long long qpow(long long x,long long y)
{
    long long res=1;
    while(y)
    {
        if(y&1) res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}
int n,t;
long long Inv[200005];
vector<pair<int,pair<int,int> > > vec[200005];

int cnt[200005],Maxcnt[200005];
void Add(int x,int flag)
{
    for(int i=2;i*i<=x;i++)
    {
        while(x%i==0)
        {
            cnt[i]+=flag;
            x/=i;
            Maxcnt[i]=max(Maxcnt[i],cnt[i]);
        }
    }
    if(x!=1) 
    {
        cnt[x]+=flag;
        Maxcnt[x]=max(Maxcnt[x],cnt[x]);
    }
}

void dfs1(int Now,int Pre,int x=1,int y=1)
{
    Add(y,-1);
    Add(x,1);
    for(auto &p : vec[Now])
    {
        if(p.first == Pre) continue;
        dfs1(p.first,Now,p.second.first,p.second.second);
    }
    Add(x,-1);
    Add(y,1);
}

long long Nowval,ans;
void dfs2(int Now,int Pre,int x=1,int y=1)
{
    Nowval=Nowval*y%mod*Inv[x]%mod;
    ans=(ans+Nowval)%mod;
    for(auto &p : vec[Now])
    {
        if(p.first == Pre) continue;
        dfs2(p.first,Now,p.second.first,p.second.second);
    }
    Nowval=Nowval*x%mod*Inv[y]%mod;
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) Inv[i]=qpow(i,mod-2);
        for(int i=1;i<=n;i++) vec[i].clear();
        for(int i=1;i<=n;i++) cnt[i]=Maxcnt[i]=0;
        for(int i=1;i<=n-1;i++)
        {
            int u,v,x,y;
            scanf("%d%d%d%d",&u,&v,&x,&y);
            vec[u].push_back(make_pair(v,make_pair(x,y)));
            vec[v].push_back(make_pair(u,make_pair(y,x)));
        }
        dfs1(1,0);
        Nowval=1;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            Nowval=(Nowval*qpow(i,Maxcnt[i]))%mod;
        }
        dfs2(1,0);
        printf("%lld\n",ans);
    }
}