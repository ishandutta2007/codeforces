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
int to[100111],ty[100111];
vector<int> con[100111];
vector<int> g[100111];
int f[100111];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
vector<pair<int,int> >ansv;
int ans;
bool vis[100111],onc[100111],inst[100111];
vector<int>cyc;
void findcycle(int x)
{
	vis[x]=1;
	inst[x]=1;
	if(inst[to[x]])
	{
		int p=to[x];
		while(true)
		{
			cyc.PB(p);
			onc[p]=1;
			p=to[p];
			if(p==to[x])break;
		}
	}
	else if(!vis[to[x]])findcycle(to[x]);
	inst[x]=0;
}
pair<int,int> dp[100111][2];
int mt[100111];
void dfs(int x)
{
	vis[x]=1;
	dp[x][1]=dp[x][0]=MP(0,0);
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(onc[u])continue;
		if(!vis[u])dfs(u);
		dp[x][0].FF+=dp[u][0].FF;
		dp[x][0].SS+=dp[u][0].SS;
		pair<int,int> tmp=MP(dp[x][1].FF+dp[u][1].FF+1,dp[x][1].SS+dp[u][1].SS+(ty[x]!=ty[u]));
//		dp[x][0]=max(dp[x][0],MP(dp[x][1].FF+dp[u][1].FF+1,dp[x][1].SS+dp[u][1].SS+(ty[x]!=ty[u])));
		if(tmp>dp[x][0])mt[x]=u,dp[x][0]=tmp;
		dp[x][1].FF+=dp[u][0].FF;
		dp[x][1].SS+=dp[u][0].SS;
	}
}
pair<int,int> dp2[100111];
int from[100111],mt2[100111];
pair<int,int> solve2(vector<int> v)
{
//	cerr<<"solve2:"<<endl;
//	for(int i=0;i<v.size();i++)cerr<<v[i]<<" ";cerr<<endl;
	dp2[v[0]]=dp[v[0]][0];from[0]=-1;
	for(int i=1;i<v.size();i++)
	{
		pair<int,int> tmp2=MP((i>=2?dp2[v[i-2]].FF:0)+1,(i>=2?dp2[v[i-2]].SS:0)+(ty[v[i]]!=ty[v[i-1]]));
		tmp2.FF+=dp[v[i]][1].FF+dp[v[i-1]][1].FF;
		tmp2.SS+=dp[v[i]][1].SS+dp[v[i-1]][1].SS;
		pair<int,int> tmp1=dp2[v[i-1]];
		tmp1.FF+=dp[v[i]][0].FF;
		tmp1.SS+=dp[v[i]][0].SS;
		if(tmp2>=tmp1)dp2[v[i]]=tmp2,from[i]=i-2;
		else dp2[v[i]]=tmp1,from[i]=i-1;
//		cerr<<dp2[v[i]].FF<<","<<dp2[v[i]].SS<endl;
	}
	int p=int(v.size())-1;
	assert(p>=0);
	while(p>=0)
	{
		if(from[p]==p-2)mt2[v[p]]=v[p-1],mt2[v[p-1]]=-v[p];
		else mt2[v[p]]=0;
		p=from[p];
	}
	return dp2[v[int(v.size())-1]];
}
void calcans(int x)
{
	if(mt[x])
	{
		ansv.PB(MP(x,mt[x]));
	}
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(onc[u])continue;
		if(u==mt[x])
		{
			for(int j=0;j<con[u].size();j++)calcans(con[u][j]);
		}
		else calcans(u);
	}
}
void solve(vector<int> v)
{
	if(!v.size())return;
//	cerr<<"solve:"<<endl;
//	for(int i=0;i<v.size();i++)cerr<<v[i]<<" ";cerr<<endl;
	cyc.clear();
	for(int i=0;i<v.size();i++)
	{
		if(!vis[v[i]])
		{
			findcycle(v[i]);
		}
	}
	for(int i=0;i<v.size();i++)vis[v[i]]=0;
	for(int i=0;i<v.size();i++)
	{
		if(!vis[v[i]]&&onc[v[i]])
		{
			dfs(v[i]);
//			cerr<<v[i]<<":"<<dp[v[i]][0].FF<<","<<dp[v[i]][0].SS<<endl;
//			cerr<<v[i]<<":"<<dp[v[i]][1].FF<<","<<dp[v[i]][1].SS<<endl;
		}
	}
//	cerr<<"cycle:"<<endl;
//	for(int i=0;i<cyc.size();i++)cerr<<cyc[i]<<" ";cerr<<endl;
	vector<int> ncyc;
	for(int i=1;i<cyc.size();i++)ncyc.PB(cyc[i]);
	ncyc.PB(cyc[0]);
	pair<int,int> cans1=solve2(cyc);
	pair<int,int> cans2=solve2(ncyc);
	if(cans1>=cans2)solve2(cyc);
	for(int i=0;i<cyc.size();i++)
	{
		int x=cyc[i];
		if(mt2[x]>0)
		{
//			cerr<<"add1:"<<x<<","<<mt2[x]<<endl;
			ansv.PB(MP(x,mt2[x]));
		}
		if(mt2[x]==0)calcans(x);
		else
		{
			for(int j=0;j<con[x].size();j++)
			{
				if(!onc[con[x][j]])
				{
					calcans(con[x][j]);
				}
			}
		}
	}
//	cerr<<max(cans1,cans2).FF<<endl;
	ans+=max(cans1,cans2).FF;
}
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)
	{
		getii(to[i],ty[i]);
		f[i]=i;
		con[to[i]].PB(i);
	}
	for(int i=1;i<=n;i++)f[gf(i)]=gf(to[i]);
	for(int i=1;i<=n;i++)g[gf(i)].PB(i);
	for(int i=1;i<=n;i++)solve(g[i]);
	int cnt=0;
	for(int i=0;i<ansv.size();i++)cnt+=ty[ansv[i].FF]!=ty[ansv[i].SS];
	assert(ans==ansv.size());
	putsii(ansv.size(),cnt);
	for(int i=0;i<ansv.size();i++)putsii(ansv[i].FF,ansv[i].SS);
	return 0;
}