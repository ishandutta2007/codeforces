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
int dp1[2][65536],dp2[2][65536];
int *dp[2],*ndp[2];
void update(int &v,int x){v=v+x>=mod?v+x-mod:v+x;}
int n,m;
int go(int x,int y,int grid)
{
//	cout<<"go:"<<x<<","<<y<<" "<<grid<<endl;
	for(int i=0;i<(1<<m+1);i++)ndp[0][i]=ndp[1][i]=0;
	for(int cur=0;cur<(1<<m+1);cur++)
	{
		int &v0=dp[0][cur],&v1=dp[1][cur];
		if(!v0&&!v1)continue;
//		cout<<cur<<":"<<v0<<","<<v1<<endl;
		int lft=(cur>>y)&1,up=(cur>>(y+1))&1;
		if(grid==0)
		{
			int nc=cur&~(3<<y);
			update(ndp[0][nc],v0);
			update(ndp[1][nc],v1);
		}
		else
		{
			update(ndp[0][cur|(3<<y)],v0);
			update(ndp[1][cur|(3<<y)],v1);
			if(up||lft)
			{
				int nc=cur&~(3<<y)|up<<y|lft<<y+1;
				update(ndp[0][nc],v0);
				update(ndp[1][nc],v1);	
			}
			else
			{
				update(ndp[1][cur],v0);
			}
		}
	}
	swap(dp,ndp);
	if(y==m-1)
	{
		for(int i=0;i<(1<<m);i++)
		{
			ndp[0][i<<1]=dp[0][i],update(ndp[0][i<<1],dp[0][i+(1<<m)]);
			ndp[1][i<<1]=dp[1][i],update(ndp[1][i<<1],dp[1][i+(1<<m)]);
			ndp[0][i<<1|1]=ndp[1][i<<1|1]=0;
		}
		swap(dp,ndp);
	}
}
char g[255][255];
int main()
{
	dp[0]=dp1[0];
	dp[1]=dp1[1];
	ndp[0]=dp2[0];
	ndp[1]=dp2[1];
	getii(n,m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			g[i][j]=getreal();
	if(n<m)
	{
		for(int i=0;i<m;i++)
			for(int j=0;j<i;j++)
				swap(g[i][j],g[j][i]);
		swap(n,m);
	}
	dp[0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			go(i,j,g[i][j]=='.');
	ll ans=0;
	for(int i=0;i<(1<<m+1);i++)ans+=dp[0][i]+dp[1][i];
	cout<<ans%mod<<endl;
	return 0;
}