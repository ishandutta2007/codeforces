//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
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
int n;
vector<int> con[55];
double dp[55][55];
int sz[55];
double C[55][55];
void dfs(int x,int pre=-1)
{
	sz[x]=1;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre)continue;
		dfs(u,x);
		sz[x]+=sz[u];
	}
	if(sz[x]==1)
	{
		for(int i=0;i<=n;i++)dp[x][i]=1;
		return;
	}
	static double f[55],nf[55];
	memset(f,0,sizeof(f));
	f[0]=1;
	int ssz=0;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre)continue;
		memset(nf,0,sizeof(nf));
		for(int j=0;j<=sz[u];j++)
		{
			double coef=C[sz[u]][j]/sz[u];
			for(int v=0;v<sz[u];v++)
			{
				int nl;
				double tcoef;
				if(v<j)nl=j-1,tcoef=1;else nl=v,tcoef=0.5;
				for(int t=0;t<=ssz;t++)
				{
					nf[t+j]+=f[t]*coef*dp[u][nl]*tcoef;
				}
			}
		}
		ssz+=sz[u];
		swap(f,nf);
	}
	for(int L=0;L<sz[x];L++)
	{
		dp[x][L]=f[L]/C[sz[x]-1][L];
	}
	for(int L=sz[x];L<=n;L++)dp[x][L]=dp[x][L-1];
}
int main()
{
	C[0][0]=1;
	for(int i=0;i<=50;i++)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)
		{
			C[i][j]=C[i-1][j-1]+C[i-1][j];
		}
	}
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		con[x].PB(y);
		con[y].PB(x);
	}
	for(int i=1;i<=n;i++)
	{
		dfs(i);
		cout<<fixed<<setprecision(10)<<dp[i][0]<<endl;
	}
	return 0;
}