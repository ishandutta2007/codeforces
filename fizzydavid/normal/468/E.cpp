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
typedef unsigned long long ull;
const ull mxmod=1ull*mod*mod*17;
//const ull mxmod=1ull*mod;

ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
int K,n,m,n1,n2;
ll ans[55];
vector<int> v;
ull adj[55][55];
namespace solver1
{
	ull dp[1<<17],ndp[1<<17];
	int cnt1[1<<17];
	void solve(ll ans[])
	{
//		cerr<<"SOLVE1"<<endl;
//		cerr<<"n1="<<n1<<" n2="<<n2<<endl;
		assert(n1<=17);
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int i=0;i<n2;i++)
		{
			memset(ndp,0,sizeof(ndp));
			for(int j=0;j<n1;j++)
			{
				if(adj[i+n1][j]==0)continue;
				for(int msk=0;msk<(1<<n1);msk++)
				{
					int nmsk=msk|(1<<j);
					if(msk==nmsk||dp[msk]==0)continue;
					ndp[nmsk]+=dp[msk]*adj[i+n1][j];
					if(ndp[nmsk]>=mxmod)ndp[nmsk]%=mod;
				}
			}
			for(int msk=0;msk<(1<<n1);msk++)dp[msk]=(dp[msk]+ndp[msk])%mod;
		}
		for(int i=0;i<=n1;i++)ans[i]=0;
		for(int i=0;i<(1<<n1);i++)ans[__builtin_popcount(i)]+=dp[i];
		for(int i=0;i<=n1;i++)ans[i]%=mod;
	}
};
namespace solver2
{
	bool vis[55];
	int en,tp[55],tpn,fa[55];
	pair<int,int> e[55];
	vector<pair<int,ull> > son[55];
	void dfs(int x,int pre=-1)
	{
		vis[x]=1;
		for(int y=0;y<n;y++)
		{
			if(adj[x][y]!=0)
			{
				if(!vis[y])dfs(y,x),fa[y]=x;
				else if(y!=pre&&x<y)e[en++]=MP(x,y);
			}
		}
		tp[x]=tpn++;
		for(int y=0;y<n;y++)if(fa[y]==x)son[tp[x]].PB(MP(tp[y],adj[x][y]));
	}
	bool ban[55];
	ull dp0[55][26],dp1[55][26];
	int sz[55];
	void polymul(ull a[],int an,ull b[],int bn,ull c[])
	{
		static ull tc[55];
		an>>=1;bn>>=1;
		for(int i=0;i<=an+bn;i++)tc[i]=0;
		for(int i=0;i<=an;i++)
		{
			if(!a[i])continue;
			for(int j=0;j<=bn;j++)
			{
				tc[i+j]+=a[i]*b[j];
				if(tc[i+j]>=mxmod)tc[i+j]%=mod;
			}
		}
		for(int i=0;i<=an+bn;i++)c[i]=tc[i]%mod;
	}
	void calcdp()
	{
		memset(dp0,0,sizeof(dp0));
		memset(dp1,0,sizeof(dp1));
		ull tmp[26];
		for(int x=0;x<n;x++)
		{
			dp0[x][0]=1;sz[x]=1;
			for(int i=0;i<son[x].size();i++)
			{
				int y=son[x][i].FF,w=son[x][i].SS;
				int nsz=sz[x]+sz[y];
				polymul(dp1[x],sz[x],dp1[y],sz[y],dp1[x]);
				if(!ban[x]&&!ban[y])
				{
					polymul(dp0[x],sz[x],dp0[y],sz[y],tmp);
					for(int j=1;j<=(nsz>>1);j++)(dp1[x][j]+=tmp[j-1]*w)%=mod;
				}
				polymul(dp0[x],sz[x],dp1[y],sz[y],dp0[x]);
				sz[x]=nsz;
			}
			for(int i=0;i<=sz[x];i++)dp0[x][i]%=mod,(dp1[x][i]+=dp0[x][i])%=mod;
		}
	}
	void solve(ll ans[])
	{
//		cerr<<"SOLVE2"<<endl;
		for(int i=0;i<n;i++)son[i].clear();
		memset(vis,0,sizeof(vis));
		memset(fa,-1,sizeof(fa));
		en=0;
		tpn=0;
		dfs(0);
/*		cerr<<"n="<<n<<endl;
		for(int i=0;i<n;i++)cerr<<tp[i]<<" ";
		for(int i=0;i<n;i++)
		{
			cerr<<"son "<<i<<":"<<endl;
			for(int j=0;j<son[i].size();j++)cerr<<son[i][j].FF<<","<<son[i][j].SS<<" ";
			cerr<<endl;
		}*/
//		cerr<<"en="<<en<<endl;
//		for(int i=0;i<en;i++)cerr<<e[i].FF<<","<<e[i].SS<<endl;
		assert(en<=17);
		assert(tpn==n);
		for(int i=0;i<=n;i++)ans[i]=0;
		for(int msk=0;msk<(1<<en);msk++)
		{
			memset(ban,0,sizeof(ban));
			ll coef=1;int cnt=0;
			bool ok=1;
			for(int i=0;i<en&&ok;i++)
			{
				if((msk>>i)&1)
				{
					int x=e[i].FF,y=e[i].SS;
					cnt++;
					coef=coef*adj[x][y]%mod;
					ok&=(!ban[tp[x]])&&(!ban[tp[y]]);
					ban[tp[x]]=ban[tp[y]]=1;
//					cerr<<"ban "<<tp[x]<<" "<<tp[y]<<endl;
				}
			}
			if(ok)
			{
				calcdp();
				for(int i=0;i<=n-cnt;i++)(ans[i+cnt]+=dp1[n-1][i]*coef)%=mod;
			}
		}
	}
};

vector<pair<int,int> > con[200111];
bool vis[200111];
void dfs(int x)
{
	vis[x]=1;v.PB(x);
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i].FF;
		if(!vis[u])dfs(u);
	}
}
ll ansp[55];
ll fac[100111];

int main()
{
	fac[0]=1;
	for(int i=1;i<=100005;i++)fac[i]=fac[i-1]*i%mod;
	int pn;
	cin>>K>>pn;
	for(int i=1;i<=pn;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;y+=K;w--;
		w=(w%mod+mod)%mod;
		con[x].PB(MP(y,w));
		con[y].PB(MP(x,w));
	}
	ansp[0]=1;
	for(int i=1;i<=2*K;i++)
	{
		if(vis[i]||con[i].size()==0)continue;
		v.clear();
		dfs(i);
		sort(v.begin(),v.end());
		n1=n2=m=0;
		for(int j=0;j<v.size();j++)n1+=v[j]<=K,n2+=v[j]>K,m+=con[v[j]].size();
		m/=2;
		n=n1+n2;
//		cerr<<"component:"<<n<<","<<m<<" "<<n1<<" "<<n2<<endl;
//		for(int i=0;i<n;i++)cerr<<v[i]<<" ";cerr<<endl;
		memset(adj,0,sizeof(adj));
		for(int j=0;j<v.size();j++)
		{
			int x=v[j],ix=j;
			for(int k=0;k<con[x].size();k++)
			{
				int y=con[x][k].FF;
				int iy=lower_bound(v.begin(),v.end(),y)-v.begin();
				adj[ix][iy]=con[x][k].SS;
			}
		}
		memset(ans,0,sizeof(ans));
		if(min(n1,n2)<=m-n+1)
		{
			if(n1>n2)
			{
				static ull nadj[55][55];
				for(int x=0;x<n;x++)
				{
					int nx=x<n1?x+n2:x-n1;
					for(int y=0;y<n;y++)
					{
						int ny=y<n1?y+n2:y-n1;
						nadj[nx][ny]=adj[x][y];
					}
				}
				swap(adj,nadj);
				swap(n1,n2);
			}
			solver1::solve(ans);
		}
		else
		{
			solver2::solve(ans);
		}
//		for(int j=0;j<=n;j++)cerr<<ans[j]<<" ";cerr<<endl;
		static ll nansp[55];
		for(int j=0;j<=50;j++)
		{
			nansp[j]=0;
			for(int k=0;k<=j;k++)nansp[j]+=ans[k]*ansp[j-k]%mod;
			nansp[j]%=mod;
		}
		swap(ansp,nansp);
	}
//	for(int i=0;i<=min(K,50);i++)cerr<<ansp[i]<<" ";cerr<<endl;
	ll Ans=0;
	for(int i=0;i<=min(K,50);i++)Ans+=ansp[i]*fac[K-i]%mod;
	Ans=(Ans%mod+mod)%mod;
	cout<<Ans<<endl;
	return 0;
}