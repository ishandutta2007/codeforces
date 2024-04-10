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
int n,m,s,a[233];
bool vis1[80][10000],vis2[80][10000];
int dp1[80][10000],dp2[80][10000];
int main()
{
    getiii(n,m,s);
    for(int i=1;i<=n;i++)geti(a[i]);
    int tj=min(m,n-m);
    vis1[0][0]=1;
    for(int i=1;i<=m;i++)
    {
//      cout<<i<<":"<<endl;
        for(int j=min(i,tj)-1;j>=0;j--)
            for(int k=0;k<=j*n-j*(j-1)/2;k++)if(vis1[j][k]){
                int nx=j+1,ny=k+m-i-j;
//              cout<<"update"<<"("<<j<<","<<k<<")->("<<nx<<","<<ny<<"):"<<dp1[j][k]-a[i]<<endl;
                if(!vis1[nx][ny])dp1[nx][ny]=dp1[j][k]-a[i],vis1[nx][ny]=1;
                else dp1[nx][ny]=min(dp1[nx][ny],dp1[j][k]-a[i]);
        }
    }
    vis2[0][0]=1;
    for(int i=m+1;i<=n;i++)
    {
//      cout<<i<<":"<<endl;
        for(int j=min(i-m,tj)-1;j>=0;j--)
            for(int k=0;k<=j*n-j*(j-1)/2;k++)if(vis2[j][k]){
                int nx=j+1,ny=k+i-m-1-j;
//              cout<<"update"<<"("<<j<<","<<k<<")->("<<nx<<","<<ny<<"):"<<dp2[j][k]+a[i]<<endl;
                if(!vis2[nx][ny])dp2[nx][ny]=dp2[j][k]+a[i],vis2[nx][ny]=1;
                else dp2[nx][ny]=min(dp2[nx][ny],dp2[j][k]+a[i]);
        }
    }
    int ans=0;
    for(int i=0;i<=tj;i++)
    {
        int bound=i*n-i*(i-1)/2;
        for(int j=0;j<bound;j++)
        {
            if(vis1[i][j])
            {
                if(!vis1[i][j+1])vis1[i][j+1]=1,dp1[i][j+1]=dp1[i][j];
                else dp1[i][j+1]=min(dp1[i][j+1],dp1[i][j]);
            }
            if(vis2[i][j])
            {
                if(!vis2[i][j+1])vis2[i][j+1]=1,dp2[i][j+1]=dp2[i][j];
                else dp2[i][j+1]=min(dp2[i][j+1],dp2[i][j]);
            }
        }
        for(int j=0;j<=bound;j++)if(s-j-i*i>=0&&vis1[i][j]&&vis2[i][min(bound,s-j-i*i)])
        {
            ans=min(ans,dp1[i][j]+dp2[i][min(bound,s-i*i-j)]);
        }
    }
    for(int i=1;i<=m;i++)ans+=a[i];
    putsi(ans);
    return 0;
}