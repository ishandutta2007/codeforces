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
int n,a[200111],g[200111],cnt[200111],mx[200111],r[400111];
bool f[400111];
int gcd(int x,int y){return y==0?x:gcd(y,x%y);}
int main()
{
    geti(n);
    for(int i=1;i<=n;i++)geti(a[i]);
    for(int i=1;i<=n;i++)g[i]=gcd(i,n);
    ll ans=0;
    for(int l=1;l<n;l++)
    {
        if(n%l==0)
        {
//          cout<<l<<":"<<endl;
            for(int i=1;i<=n;i++)cnt[i]=(g[i]==l)+cnt[i-1];
            memset(mx,0,sizeof(mx));
            for(int i=1;i<=n;i++)mx[i%l]=max(mx[i%l],a[i]);
            for(int i=1;i<=n;i++)f[i]=(a[i]>=mx[i%l]);
            for(int i=n+1;i<=n*2;i++)f[i]=f[i-n];
            for(int i=n*2;i>=1;i--)
            {
                if(i<n*2&&f[i+1])r[i]=r[i+1];else r[i]=i;
            }
            for(int i=1;i<=n;i++)if(f[i])ans+=cnt[min(n,r[i]-i+1)];
//          for(int i=1;i<=n;i++)cout<<f[i];cout<<endl;         
        }
    }
    putsi(ans);
    return 0;
}