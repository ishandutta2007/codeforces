//while(true)rp++;
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
const ll mod=1e9+7;
ll f[200111],revf[200111],dp[2011];
pair<int,int>a[2011];
int h,w,n;
ll kissme(ll x,ll k)
{
    ll ans=1;
    while(k>0)
    {
        if(k&1)ans=ans*x%mod;
        x=x*x%mod;
        k>>=1;
    }
    return ans;
}
int main()
{
    f[0]=1;
    for(int i=1;i<=200010;i++)f[i]=f[i-1]*i%mod;
    revf[200010]=kissme(f[200010],mod-2);
    for(int i=200009;i>=0;i--)revf[i]=revf[i+1]*(i+1)%mod;
    getiii(h,w,n);
    for(int i=1;i<=n;i++)getii(a[i].FF,a[i].SS);
    if(a[1]==MP(1,1))
    {
        puts("0");
        return 0;
    }
    a[++n]=MP(h,w);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        int x=a[i].FF,y=a[i].SS;
        dp[i]=f[x+y-2]*revf[x-1]%mod*revf[y-1]%mod;
        for(int j=1;j<i;j++)
            if(a[j].FF<=a[i].FF&&a[j].SS<=a[i].SS)
                dp[i]=(dp[i]-f[x-a[j].FF+y-a[j].SS]*revf[x-a[j].FF]%mod*revf[y-a[j].SS]%mod*dp[j]%mod+mod)%mod;
    }
    putsi(dp[n]);
    return 0;
}