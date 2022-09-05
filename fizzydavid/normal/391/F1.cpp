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
const int maxn=3011;
const int maxk=1511;
ll dp[maxn][maxk],a[maxn],n,k,v[maxn][maxk],mx[maxn][maxk],ans;
int main()
{
    getii(n,k);
    for(int i=1;i<=n;i++)
    {
        geti(a[i]);
    }
    mx[0][0]=-LINF;
    for(int i=1;i<=n;i++)mx[i][0]=max(mx[i-1][0],-a[i]);
    for(int j=1;j<=k;j++)
    {
        mx[0][j]=-LINF;
        for(int i=1;i<=n;i++)
        {
            dp[i][j]=max(0ll,mx[i-1][j-1]+a[i]);
            ans=max(ans,dp[i][j]);
            v[i][j]=max(v[i-1][j],dp[i][j]);
            mx[i][j]=max(mx[i-1][j],v[i][j]-a[i]);
        }
    }
    putsi(ans);
    return 0;
}