#include<bits/stdc++.h>
#define maxn 200020
#define mod 1000000007
#define pi pair<int, int>
#define x first
#define y second

using namespace std;
typedef long long ll;

int n;
ll ans,p[maxn],q[maxn],u,v,cf,cg,u0,v0,pcnt,lcnt,sum;
bool xx[maxn],yy[maxn];
map <ll, ll> f;
map <ll, ll> g;
map <ll, ll> ::iterator s;
set <pi> ::iterator t;
set <pi> a[maxn],b[maxn];

ll pow_(ll u,ll v)
{
    if (v==0) return 1;
    ll tt=pow_(u,v/2);
    tt=tt*tt%mod;
    if (v%2) tt=tt*u%mod;
    return tt;
}

ll c(ll u,ll v)
{
    return (p[v]*q[u]%mod)*q[v-u]%mod;
}
void dfsy(ll u);
void dfsx(ll u)
{
    pi tt;xx[u]=false;lcnt++;
    while (!a[u].empty()){
        t=a[u].begin();
        tt=*t;
        a[tt.x].erase(tt);pcnt++;
        if (yy[tt.y]) dfsy(tt.y);
    }
}

void dfsy(ll u)
{
    pi tt;yy[u]=false;lcnt++;
    while (!b[u].empty()){
        t=b[u].begin();
        tt=*t;
        b[tt.y].erase(tt);pcnt++;
        if (xx[tt.x]) dfsx(tt.x);
    }
}

int main()
{
    p[0]=1;q[0]=1;
    for (int i=1;i<maxn;i++)
    {
        p[i]=p[i-1]*i%mod;
        q[i]=pow_(p[i],mod-2);
    }
    scanf("%d",&n);
    f.clear();g.clear();cf=cg=0;
    while (n--)
    {
        scanf("%d%d",&u,&v);
        s=f.find(u);
        if (s==f.end()){
            cf++;
            f[u]=cf;
        }
        s=g.find(v);
        if (s==g.end()){
            cg++;
            g[v]=cg;
        }
        u0=f[u];v0=g[v];
        a[u0].insert({u0,v0});
        b[v0].insert({u0,v0});
    }
    ans=1;
    memset(xx,true,sizeof(xx));
    memset(yy,true,sizeof(yy));
    for (int i=1;i<maxn;i++)
        if (xx[i]&&!a[i].empty()){
            lcnt=0;pcnt=0;
            dfsx(i);
            sum=0;
            pcnt/=2;
            for (int j=0;j<=min(lcnt,pcnt);j++)
                sum=(sum+c(j,lcnt))%mod;
            ans=ans*sum%mod;
        }
    printf("%d\n",ans);
    return 0;
}