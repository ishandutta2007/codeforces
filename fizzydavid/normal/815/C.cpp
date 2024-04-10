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
int n,B;
vector<int> go[5011];
ll dp[2][5011][5011];
int a[5011],b[5011],sz[5011];
void dfs(int x)
{
	dp[0][x][0]=0;
	dp[1][x][0]=0;
	for(int i=0;i<go[x].size();i++)
	{
		int u=go[x][i];
		dfs(u);
		for(int j=sz[x];j>=0;j--)
		{
			for(int k=1;k<=sz[u];k++)
			{
				dp[0][x][j+k]=min(dp[0][x][j+k],dp[0][x][j]+dp[0][u][k]);
				dp[1][x][j+k]=min(dp[1][x][j+k],dp[1][x][j]+dp[0][u][k]);
				dp[1][x][j+k]=min(dp[1][x][j+k],dp[1][x][j]+dp[1][u][k]);
			}
		}
		sz[x]+=sz[u];
	}
	for(int j=sz[x];j>=0;j--)dp[1][x][j+1]=dp[1][x][j]+a[x];
	dp[1][x][0]=1ll*mod*mod;
	for(int j=sz[x];j>=0;j--)dp[0][x][j+1]=min(dp[0][x][j+1],dp[0][x][j]+b[x]);
	sz[x]++;
}
int main()
{
	memset(dp,31,sizeof(dp));
	getii(n,B);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		getii(x,y);
		a[i]=x-y;
		b[i]=x;
		int p;
		if(i>1)
		{
			geti(p);
			go[p].PB(i);
		}
	}
	dfs(1);
	for(int i=n;i>=0;i--)
	{
		if(dp[0][1][i]<=B||dp[1][1][i]<=B)
		{
			putsi(i);
			return 0;
		}
	}
	return 0;
}