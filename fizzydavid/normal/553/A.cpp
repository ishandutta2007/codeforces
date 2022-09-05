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
#define putsi(x) puti(x),putendl()
#define putsii(x,y) putii(x,y),putendl()
#define putsiii(x,y,z) putiii(x,y,z),putendl()
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
ll n,tot,dp[1011][1011],sum[1011][1011],a[1011],C[2011][2011];
int main()
{
    geti(n);
    for(int i=1;i<=n;i++)geti(a[i]),tot+=a[i];
    C[0][0]=1;
    for(int i=1;i<=2000;i++)
    {
        C[i][0]=1;C[i][i]=1;
        for(int j=1;j<i;j++)
        {
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
    dp[0][0]=1;
    ll t=0;
    for(int i=1;i<=n;i++)
    {
        t+=a[i];
        for(int j=t;j<=tot;j++)
        {
            if(i==1)
            {
                dp[i][j]=C[j-1][a[i]-1];
            }
            else
            {
                dp[i][j]=sum[i-1][j-1]*C[j-1-t+a[i]][a[i]-1]%mod;
            }
        }
        for(int j=1;j<=tot;j++)sum[i][j]=(sum[i][j-1]+dp[i][j])%mod;
    }
    putsi(dp[n][tot]);
    return 0;
}