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
void update(int &x,int v){x=x+v>=mod?x+v-mod:x+v;}
int pre[100111];
vector<pair<int,bool> > con[100111];
void adde(int x,int y,bool d)
{
//	cerr<<"adde:"<<x<<","<<y<<" "<<d<<endl;
	con[x].PB(MP(y,d));
	con[y].PB(MP(x,d));
}
int isfree[100111];
pair<int,int> ANS;
pair<int,int> combine(pair<int,int> p,pair<int,int> q)
{
	return MP((1ll*p.FF*q.FF+1ll*p.SS*q.SS)%mod,(1ll*p.SS*q.FF+1ll*p.FF*q.SS)%mod);
}
bool vis[100111];
int a[100111],an;
bool nxt[100111];
namespace NCyc
{
	void dfs(int x,int pre=-1)
	{
		int p=an++;
		vis[x]=1;
		a[p]=x;
		for(int i=0;i<con[x].size();i++)
		{
			int u=con[x][i].FF;
			if(vis[u])continue;
			nxt[p]=con[x][i].SS;
			dfs(u,x);
		}
	}
	int dp[100111][2][2];
	pair<ll,ll> solve_noncycle(int x)
	{
//		cerr<<"solve_noncycle:"<<x<<endl;
		an=0;
		dfs(x);
//		for(int i=0;i<an;i++)cerr<<a[i]<<" "<<nxt[i]<<endl;
		for(int t=0;t<=an;t++)for(int i=0;i<2;i++)for(int j=0;j<2;j++)dp[t][i][j]=0;
		dp[0][0][0]=1;
		for(int i=0;i<an;i++)
		{
//			cerr<<i<<":"<<dp[i][0][0]<<" "<<dp[i][0][1]<<" "<<dp[i][1][0]<<" "<<dp[i][1][1]<<endl;
			
			for(int t=0;t<isfree[a[i]];t++)
			{
				int ndp[2][2]={};
				for(int cur=0;cur<2;cur++)
				{
					for(int sum=0;sum<2;sum++)
					{
						update(ndp[cur][sum],dp[i][cur][sum]);
						update(ndp[cur|1][sum],dp[i][cur][sum]);
					}
				}
				swap(ndp,dp[i]);
			}
//			cerr<<i<<":"<<dp[i][0][0]<<" "<<dp[i][0][1]<<" "<<dp[i][1][0]<<" "<<dp[i][1][1]<<endl;
			if(i<an-1)
			{
				if(nxt[i]==0)
				{
					for(int cur=0;cur<2;cur++)
					{
						for(int sum=0;sum<2;sum++)
						{
							update(dp[i+1][0][sum^cur],dp[i][cur][sum]);
							update(dp[i+1][1][sum^1],dp[i][cur][sum]);
						}
					}
				}
				else
				{
					for(int cur=0;cur<2;cur++)
					{
						for(int sum=0;sum<2;sum++)
						{
							update(dp[i+1][1][sum^cur],dp[i][cur][sum]);
							update(dp[i+1][0][sum^1],dp[i][cur][sum]);
						}
					}
					
				}
			}
			else return MP((dp[i][0][0]+dp[i][1][1])%mod,
			        (dp[i][0][1]+dp[i][1][0])%mod);
		}
	}
};
namespace Cyc
{
	int S;
	void dfs(int x,int pre=-1)
	{
		int p=an++;
		a[p]=x;
		bool f=1;
		for(int i=0;i<con[x].size();i++)
		{
			int u=con[x][i].FF;
			if(u==pre&&f)
			{
				f=0;
				continue;
			}
			if(!vis[u])
			{
				vis[u]=1;
				dfs(u,x);
				nxt[p]=con[x][i].SS;
			}
		}
	}
	int dp[100111][2][2];
	pair<ll,ll> solve_cycle(int x)
	{
		S=x;
//		cerr<<"solve_cycle:"<<x<<endl;
		an=0;
		dfs(x);
//		for(int i=0;i<an;i++)cerr<<a[i]<<" "<<nxt[i]<<endl;
		
		int ans[2]={0,0};
		for(int st=0;st<2;st++)
		{
			for(int t=0;t<=an;t++)for(int i=0;i<2;i++)for(int j=0;j<2;j++)dp[t][i][j]=0;
			dp[0][0][0]=1;
			for(int i=0;i<an;i++)
			{
//				cerr<<i<<":"<<dp[i][0][0]<<" "<<dp[i][0][1]<<" "<<dp[i][1][0]<<" "<<dp[i][1][1]<<endl;
				assert(!isfree[a[i]]);
				if(i<an-1)
				{
					if(nxt[i]==0)
					{
						for(int cur=0;cur<2;cur++)
						{
							for(int sum=0;sum<2;sum++)
							{
								if(i!=0||cur==st)update(dp[i+1][0][sum^cur],dp[i][cur][sum]);
								if(i!=0||1==st)update(dp[i+1][1][sum^1],dp[i][cur][sum]);
							}
						}
					}
					else
					{
						for(int cur=0;cur<2;cur++)
						{
							for(int sum=0;sum<2;sum++)
							{
								if(i!=0||cur==st)update(dp[i+1][1][sum^cur],dp[i][cur][sum]);
								if(i!=0||1==st)update(dp[i+1][0][sum^1],dp[i][cur][sum]);
							}
						}
					}
				}
				else
				{
					for(int cur=0;cur<2;cur++)for(int sum=0;sum<2;sum++)
					{
						update(ans[sum^(st|cur)^st],dp[i][cur][sum]);
					}
				}
			}
		}
		return MP(ans[0],ans[1]);
	}
};

bool used[100111];
int main()
{
	getii(n,m);
	for(int i=1;i<=n;i++)
	{
		int k;
		geti(k);
		for(int j=1;j<=k;j++)
		{
			int v;
			geti(v);
			int ti=i;
			if(v<0)ti=-ti,v=-v;
			used[v]=1;
			if(pre[v]!=0)
			{
				if(1ll*ti*pre[v]>0)adde(abs(pre[v]),i,0);
				else adde(abs(pre[v]),i,1);
				pre[v]=0;
			}
			else pre[v]=ti;
		}
	}
	for(int i=1;i<=m;i++)isfree[abs(pre[i])]++;
//	for(int i=1;i<=n;i++)cerr<<isfree[i]<<" ";cerr<<endl;
	ANS=MP(1,0);
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		if(con[i].size()<=1)
		{
			pair<ll,ll> curans=NCyc::solve_noncycle(i);
//			cerr<<"curans="<<curans.FF<<","<<curans.SS<<endl;
			ANS=combine(ANS,curans);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		pair<ll,ll> curans=Cyc::solve_cycle(i);
//		cerr<<"curans="<<curans.FF<<","<<curans.SS<<endl;
		ANS=combine(ANS,curans);
	}
//	cerr<<ans<<endl;
	for(int i=1;i<=m;i++)if(!used[i])ANS=combine(ANS,MP(2,0));
//	cerr<<ANS.FF<<" "<<ANS.SS<<endl;
	ll ans=(ANS.SS%mod+mod)%mod;
	cout<<ans<<endl;
	return 0;
}