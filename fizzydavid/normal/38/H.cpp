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
inline char getreal(){char c=_buff.get();while(c<=32)c=_buff.get();return c;}
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
int n,m;
int d[55][55];
int mn[55],mx[55];
int pre[55][55*1000];
ll dp[55][55][55];
int gl,gr,sl,sr;
ll calc(int gi,int gv,int ci,int cv)
{
	if(MP(gv,gi)>=MP(cv,ci)||gi==ci)return 0;
	memset(dp,0,sizeof(dp));
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++)
	{
		bool bg=0,bs=0,bc=0;
		if(MP(mn[i],i)<=MP(gv,gi))bg=1;
		if(MP(mx[i],i)>=MP(cv,ci))bc=1;
		int l=gv,r=cv;
		if(i<=gi)l++;
		if(i>=ci)r--;
		if(pre[i][r]-pre[i][l-1]>0)bs=1;
		if(i==gi)bs=bc=0;
		if(i==ci)bg=bs=0;
		for(int j=0;j<i;j++)
		{
			for(int k=0;k+j<i;k++)
			{
				ll &cur=dp[i-1][j][k];
				if(cur==0)continue;
				if(bg)dp[i][j+1][k]+=cur;
				if(bc)dp[i][j][k+1]+=cur;
				if(bs)dp[i][j][k]+=cur;
			}
		}
	}
	ll ans=0;
	for(int i=gl;i<=gr;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(n-i-j>=sl&&n-i-j<=sr)ans+=dp[n][i][j];
		}
	}
	return ans;
}
int main()
{
	memset(d,31,sizeof(d));
	getii(n,m);
	for(int i=1;i<=n;i++)d[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int x,y,l;
		getiii(x,y,l);
		d[x][y]=min(d[x][y],l);
		d[y][x]=min(d[y][x],l);
	}
	getii(gl,gr);
	getii(sl,sr);
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		mn[i]=23333333;
		for(int j=1;j<=n;j++)if(i!=j)mn[i]=min(mn[i],d[i][j]);
		for(int j=1;j<=n;j++)mx[i]=max(mx[i],d[i][j]);
		for(int j=1;j<=n;j++)if(i!=j)pre[i][d[i][j]]++;
		for(int j=1;j<=n*1000;j++)pre[i][j]+=pre[i][j-1];
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ans+=calc(i,mn[i],j,mx[j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}