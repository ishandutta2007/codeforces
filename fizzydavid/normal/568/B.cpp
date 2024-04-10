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
const int mod=1e9+7;
ll dp[2][5011],sum[5011],f[5011],revf[5011];
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
    for(int i=1;i<=5000;i++)f[i]=f[i-1]*i%mod;
    revf[5000]=kissme(f[5000],mod-2);
    for(int i=4999;i>=0;i--)revf[i]=revf[i+1]*(i+1)%mod;
    sum[0]=1;
    for(int i=1;i<=5000;i++)
    {
        int p=i&1;
        dp[p][1]=1;sum[i]=1;
        for(int j=2;j<=i;j++)
        {
            dp[p][j]=(dp[p^1][j-1]+dp[p^1][j]*j%mod)%mod;
            sum[i]=(sum[i]+dp[p][j])%mod;
        }
    }
    int n;
    cin>>n;
    ll ans=1;
    for(int i=1;i<n;i++)
    {
        ans=(ans+sum[i]*f[n]%mod*revf[i]%mod*revf[n-i]%mod)%mod;
    }
    cout<<ans<<endl;
    return 0;
}