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
int n;
ll Ans[200111];
vector<pair<int,int> > con[200111];
bool onc[200111];
int a[400111],an,d[400111];
ll pre_d[400111];
ll sum0[200111],sum1[200111];
bool vis[200111];
int dfs_pa[200111],dfs_pc[200111];
void dfs(int x,int pre=-1)
{
	vis[x]=1;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i].FF;
		if(u==pre)continue;
		if(vis[u])
		{
			if(an>0)continue;
			int p=x;
			while(true)
			{
				onc[p]=1;
				d[an]=dfs_pc[p];
				a[an++]=p;
				if(p==u)break;
				p=dfs_pa[p];
			}
			d[an-1]=con[x][i].SS;
		}
		else dfs_pa[u]=x,dfs_pc[u]=con[x][i].SS,dfs(u,x);
	}
}
int cur_g;
ll dis[200111];
vector<pair<int,ll> > v[200111];
int sz[200111],g[200111];
void dfs2(int x,int pre=-1,ll l=0,ll sum=0)
{
	g[x]=cur_g;
	sum0[cur_g]++;
	sum1[cur_g]+=l;
	dis[x]=l;
	v[cur_g].PB(MP(x,l));
	sz[x]=1;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i].FF;
		if(u==pre||onc[u])continue;
		dfs2(u,x,l+con[x][i].SS);
		sz[x]+=sz[u];
	}
}
void dfs3(int x,int pre=-1,ll sum=0)
{
	Ans[x]=sum0[cur_g]*dis[x]-2*(sum+sz[x]*dis[x]);
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i].FF;
		if(u==pre||onc[u])continue;
		dfs3(u,x,sum+(sz[x]-sz[u])*dis[x]);
	}
}
ll ans0[200111];
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)
	{
		int x,y,w;
		getiii(x,y,w);
		con[x].PB(MP(y,w));
		con[y].PB(MP(x,w));
	}
	dfs(1);
//	cerr<<"an="<<an<<endl;
//	for(int i=0;i<an;i++)cerr<<a[i]<<" ";cerr<<endl;
//	for(int i=0;i<an;i++)cerr<<d[i]<<" ";cerr<<endl;
	
	for(int i=0;i<an;i++)
	{
		cur_g=a[i];
		dfs2(a[i]);
		dfs3(a[i]);
	}
//	for(int i=0;i<an;i++)cerr<<sum0[a[i]]<<" ";cerr<<endl;
	
	int it=0;
	for(int i=an;i<2*an;i++)d[i]=d[i-an],a[i]=a[i-an];
	for(int i=1;i<=2*an;i++)pre_d[i]=pre_d[i-1]+d[i-1];
	while(pre_d[it]*2<pre_d[an])it++;
	ll sum_l0=0,sum_l1=0,sum_r0=0,sum_r1=0;
	for(int i=0;i<it;i++)
	{
		sum_r0+=sum0[a[i]];
		sum_r1+=pre_d[i]*sum0[a[i]];
	}
	for(int i=it;i<an;i++)
	{
		sum_l0+=sum0[a[i]];
		sum_l1+=(pre_d[i]-pre_d[an])*sum0[a[i]];
	}
	for(int i=0;i<an;i++)
	{
		while((pre_d[it]-pre_d[i])*2<pre_d[an])
		{
			sum_l0-=sum0[a[it]];
			sum_l1-=(pre_d[it]-pre_d[an])*sum0[a[it]];
			sum_r0+=sum0[a[it]];
			sum_r1+=pre_d[it]*sum0[a[it]];
			it++;
		}
//		cerr<<i<<","<<it<<" "<<sum_r0<<","<<sum_r1<<" "<<sum_l0<<","<<sum_l1<<endl;
		ans0[a[i]]=sum_r1-sum_r0*pre_d[i]+
		        sum_l0*pre_d[i]-sum_l1;
		sum_r0-=sum0[a[i]];
		sum_r1-=pre_d[i]*sum0[a[i]];
		sum_l0+=sum0[a[i]];
		sum_l1+=pre_d[i]*sum0[a[i]];
	}
//	for(int i=1;i<=n;i++)cerr<<ans0[i]<<" ";cerr<<endl;
	
	ll sum=0;
	for(int i=0;i<an;i++)sum+=sum1[a[i]];
	for(int i=1;i<=n;i++)puti(sum+Ans[i]+dis[i]*(n-sum0[g[i]])+ans0[g[i]]);
	return 0;
}