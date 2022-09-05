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

int n,dp[100111],p[100111],pn,t[100],tn;
bool f[100111];
int main()
{
    for(int i=2;i<=100000;i++)
    {
        if(f[i])continue;else p[pn++]=i;
        for(int j=i*2;j<=100000;j+=i)p[j]=1;
    }
    geti(n);
    while(n--)
    {
        int x,mx=0;
        tn=0;
        geti(x);
        for(int i=0;i<pn&&p[i]*p[i]<=x;i++)
        {
            if(x%p[i]==0)
            {
                t[tn++]=p[i];
                mx=max(mx,dp[p[i]]);
                while(x%p[i]==0)x/=p[i];
            }
        }
        if(x>1)t[tn++]=x,mx=max(mx,dp[x]);
        for(int i=0;i<tn;i++)
            dp[t[i]]=mx+1;
    }
    int ans=1;
    for(int i=1;i<=100000;i++)ans=max(ans,dp[i]);
    putsi(ans);
    return 0;
}