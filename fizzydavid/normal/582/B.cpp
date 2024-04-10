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
int n,t,a[111],dp[311][311],dp2[111][311],mx[111][311];
int main()
{
    getii(n,t);
    for(int i=1;i<=n;i++)
        geti(a[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=a[i];j++)
            for(int k=a[i];k>=j;k--)
                dp[j][a[i]]=max(dp[j][a[i]],dp[j][k]+1);
    for(int i=1;i<=300;i++)
        for(int j=i+1;j<=300;j++)
            dp[i][j]=max(dp[i][j],dp[i][j-1]);
    ll ans=0;
    for(int i=1;i<=300;i++)mx[0][i]=dp[i][i];
    for(int i=1;i<=min(n,t);i++)
    {
        for(int j=1;j<=300;j++)
        {
            for(int k=1;k<j;k++)
            {
                int v=dp2[i-1][k]+dp[k][j];
                if(v>dp2[i][j])
                {
                    dp2[i][j]=v;
                    mx[i][j]=max(mx[i-1][k],dp[j][j]);
                }
                else if(v==dp2[i][j])
                {
                    mx[i][j]=max(mx[i][j],max(mx[i-1][k],dp[j][j]));
                }
            }
            ans=max(ans,dp2[i][j]+1ll*mx[i][j]*(t-i));
        }
    }
    putsi(ans);
    return 0;
}