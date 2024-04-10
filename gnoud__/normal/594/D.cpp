#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define forv(a,b) for(auto&a:b)
#define b(x) ((x-1)/T+1)
#define pb push_back
#define sz(a) int(a.size())
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int NN=1e6+10,mod=1e9+7,N=2e5+10;
int n,m,a[N],p[NN],ans[N],dd[NN],D[NN],t[N],vt[NN],s[N],_s[N];
vector<int> e[N],sv[N];
vector<pii> ad[N];
int pw(int a,int i)
{
    int b=1;
    for(;i;i>>=1,a=1ll*a*a%mod) if(i&1) b=1ll*b*a%mod;
    return b;
}
void read(int & x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
}
void snt()
{
    forinc(i,2,NN-10) if(!p[i])
    for(int j=i;j<=NN-10;j+=i) p[j]=i;
}
void update(int i,int x)
{
    for(;i<=n;i+=i&-i) t[i]=(1ll*t[i]*x)%mod;
}
int get(int i)
{
    int g=1;
    for(;i;i-=i&-i) g=(1ll*g*t[i])%mod;
    return g;
}
void Update(int i,int x)
{
    update(i,1ll*(x-1)*D[x]%mod);
}
void unUpdate(int i,int x)
{
    update(i,1ll*D[x-1]*x%mod);
}
int S(int i,int j)
{
    return 1ll*s[j]*_s[i-1]%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("594D.inp","r",stdin);
    //freopen("594D.out","w",stdout);
    read(n);
    forinc(i,1,1e6) D[i]=pw(i,mod-2);
    snt();
    forinc(i,1,n) t[i]=1;
    s[0]=_s[0]=1;
    forinc(i,1,n)
    {
        read(a[i]);
        s[i]=(1ll*s[i-1]*a[i])%mod;
        _s[i]=pw(s[i],mod-2);
        int x=a[i];
        while(x!=1)
        {
            e[i].pb(p[x]);
            x/=p[x];
        }
        sort(e[i].begin(),e[i].end());
        e[i].erase(unique(e[i].begin(),e[i].end()),e[i].end());
    }
    fordec(i,n,1)
    {
        forv(x,e[i])
        {
            sv[i].pb(vt[x]);
            vt[x]=i;
        }
    }
    read(m);
    forinc(i,1,m)
    {
        int u,v;
        read(u),read(v);
        ad[u].pb({v,i});
    }
    forinc(i,1,n)
    {
        forinc(j,0,sz(e[i])-1)
        {
            if(!dd[e[i][j]]) Update(i,e[i][j]);
            dd[e[i][j]]=1;
        }
    }
    forv(x,ad[1]) ans[x.se]=1ll*get(x.fi)*S(1,x.fi)%mod;
    forinc(i,2,n)
    {
        forinc(j,0,sz(e[i-1])-1)
        {
            int x=e[i-1][j];
            unUpdate(i-1,x);
            if(sv[i-1][j]) Update(sv[i-1][j],x);
            forv(o,ad[i]) ans[o.se]=1ll*get(o.fi)*S(i,o.fi)%mod;
        }
    }
    forinc(i,1,m) cout<<ans[i]<<"\n";
}