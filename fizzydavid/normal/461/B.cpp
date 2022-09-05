//by yjz
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
    register ll r=0;register bool ng=0;register char c;c=getchar();
    while(c!='-'&&(c<'0'||c>'9'))c=getchar();
    if(c=='-')ng=1,c=getchar();
    while(c!=' '&&c!='\n')r=r*10+c-'0',c=getchar();
    if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
    if(x<0)putchar('-'),x=-x;
    register short a[20]={},sz=0;
    while(x>0)a[sz++]=x%10,x/=10;
    if(sz==0)putchar('0');
    for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
const int mod=1e9+7;
int n;
vector<int>con[100111];
ll dp0[100111],dp1[100111];
bool f[100111];
ll kissme(ll x)
{
    ll k=mod-2,ans=1;
    while(k>0)
    {
        if(k&1)ans=ans*x%mod;
        x=x*x%mod;
        k>>=1;
    }
    return ans;
}
void dfs(int x)
{
    for(int i=0;i<con[x].size();i++)
        dfs(con[x][i]);
    if(f[x])dp1[x]=1;else dp0[x]=1;
    for(int i=0;i<con[x].size();i++)
    {
        int u=con[x][i];
        if(f[x])
        {
            dp1[x]=dp1[x]*(dp0[u]+dp1[u])%mod;
        }
        else
        {
            dp0[x]=dp0[x]*(dp0[u]+dp1[u])%mod;
        }
    }
    if(!f[x])
    {
        for(int i=0;i<con[x].size();i++)
        {
            int u=con[x][i];
            dp1[x]=(dp1[x]+dp0[x]*kissme(dp0[u]+dp1[u])%mod*dp1[u]%mod)%mod;
        }
    }
}
int main()
{
    geti(n);
    for(int i=2;i<=n;i++)
    {
        int x;
        geti(x);
        x++;
        con[x].PB(i);
    }
    for(int i=1;i<=n;i++)geti(f[i]);
    dfs(1);
    putsi(dp1[1]);
    return 0;
}