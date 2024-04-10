//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c==' '||c=='\n')c=_buff.get();return c;}
int n,r,f[55],s[55];
double p[55];
//dp[i][j] minimal expected time to complete i~n level having spent time j
//dp[i][j]=min(dp[i+1][j+f[i]]*p[i]+dp[i+1][j+s[i]]*(1-p[i]),dp[1][0])
//dp[n+1][0~r]=0 dp[n+1][r+1~inf]=inf
double dp[55][5011];
double solve(double G)
{
	for(int i=0;i<=r;i++)dp[n+1][i]=0;
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<=r;j++)
		{
			dp[i][j]=min((min(G,j+f[i]>r?1e20:dp[i+1][j+f[i]])+f[i])*p[i]+
	                     (min(G,j+s[i]>r?1e20:dp[i+1][j+s[i]])+s[i])*(1-p[i]),G);
		}
	}
	return dp[1][0];
}
int main()
{
	cin>>n>>r;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i]>>s[i]>>p[i];
		p[i]/=100;
	}
	double l=0,r=1e20;
	for(int i=0;i<100;i++)
	{
		double m=(l+r)/2;
		double rm=solve(m);
		if(rm<m)r=m;else l=m;
	}
	cout<<fixed<<setprecision(9)<<l<<endl;
	return 0;
}