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
int n,k,a[200111],tb[200111],bg,ed;
double suf[200111],sum[200111];
double dp[200111],nxt[200111];
struct point
{
	double x,y;
	point(double _x=0,double _y=0){x=_x;y=_y;}
	point operator-(const point &t){return point(x-t.x,y-t.y);}
	double det(const point &t){return x*t.y-y*t.x;}
};
point p[200111];
const double eps=1e-6;
double calc(int j,int i)
{
	return dp[j]+(sum[j-1]-sum[i-1])*suf[j];
}
int main()
{
	getii(n,k);
	for(int i=1;i<=n;i++)geti(a[i]);
	double ans=0;
	for(int i=1;i<=n+1;i++)sum[i]=sum[i-1]+a[i];
	for(int i=n;i>=1;i--)suf[i]=suf[i+1]+1.0/a[i];
	for(int i=1;i<=n;i++)ans+=1.0*sum[i]/a[i];
	dp[n+1]=0;
	for(int i=0;i<=n;i++)dp[i]=-1e100;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			p[j]=point(suf[j],dp[j]+sum[j-1]*suf[j]);
		}
		bg=ed=0;
		tb[ed++]=n+1;
		for(int j=n;j>=1;j--)
		{
			while(ed-bg>1&&point(1,sum[j-1]).det(p[tb[bg+1]]-p[tb[bg]])>-eps)
			{
				bg++;
			}
			nxt[j]=p[tb[bg]].y-sum[j-1]*p[tb[bg]].x;
			tb[ed++]=j;
			while(ed-bg>2&&(p[tb[ed-2]]-p[tb[ed-3]]).det(p[tb[ed-1]]-p[tb[ed-3]])>-eps)
			{
				tb[ed-2]=tb[ed-1];
				ed--;
			}
		}
		for(int j=1;j<=n;j++)
		{
			dp[j]=nxt[j];
		}
	}
	cout<<fixed<<setprecision(8)<<ans-dp[1]<<endl;
	return 0;
}