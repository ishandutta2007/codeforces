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
const int maxn=500111;
const int inf=2e9;
int n,m,q;
bool vis[maxn];
vector<int> con[maxn];
int rt[maxn],p[21][maxn],mn[21][maxn],lv[maxn];
void dfs(int x,int pre,int g)
{
	rt[x]=g;p[0][x]=pre;
	for(int i=1;i<=20;i++)p[i][x]=p[i-1][p[i-1][x]];
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre)continue;
		lv[u]=lv[x]+1;
		dfs(u,x,g);
	}
}
int lg2[maxn];
int get_lca(int x,int y)
{
	if(lv[x]<lv[y])swap(x,y);
	for(int i=20;i>=0;i--)if(lv[x]-lv[y]>=(1<<i))x=p[i][x];
	if(x==y)return x;
	for(int i=20;i>=0;i--)if(p[i][x]!=p[i][y])
	{
		x=p[i][x];
		y=p[i][y];
	}
	return p[0][x];
}
void upd(int &x,int v){x=min(x,v);}
int getfa(int x,int l)
{
	for(int i=20;i>=0;i--)if(lv[x]-l>=(1<<i))x=p[i][x];
	return x;
}
void mini(int x,int p,int w)
{
	if(x==p)return;
	int t=lg2[lv[x]-lv[p]];
	upd(mn[t][x],w);
	upd(mn[t][getfa(x,lv[p]+(1<<t))],w);
}
void pushdown()
{
	for(int i=20;i>=1;i--)
	{
		for(int j=1;j<=n;j++)
		{
			upd(mn[i-1][j],mn[i][j]);
			upd(mn[i-1][p[i-1][j]],mn[i][j]);
		}
	}
}
int qx[maxn],qy[maxn],qw[maxn];
int f[maxn];
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
int main()
{
	for(int i=2;i<maxn;i++)lg2[i]=lg2[i>>1]+1;
	getiii(n,m,q);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		getii(x,y);
		con[x].PB(y);
		con[y].PB(x);
		f[gf(x)]=gf(y);
	}
	for(int i=0;i<=20;i++)for(int j=0;j<=n;j++)mn[i][j]=inf;
	ll sum=0;
	for(int i=1;i<=q;i++)
	{
		getiii(qx[i],qy[i],qw[i]);
		int x=qx[i],y=qy[i],w=qw[i];
		if(gf(x)!=gf(y))
		{
//			cerr<<x<<"->"<<y<<endl;
			sum-=w;
			con[x].PB(y);
			con[y].PB(x);
			f[gf(x)]=gf(y);
		}
	}
	dfs(1,0,1);
	for(int i=1;i<=q;i++)
	{
		int x=qx[i],y=qy[i],w=qw[i];
		int fa=get_lca(x,y);
//		cerr<<x<<","<<y<<" "<<fa<<endl;
		mini(x,fa,w);
		mini(y,fa,w);
	}
//	cerr<<sum<<endl;
	pushdown();
//	for(int i=2;i<=n;i++)cerr<<mn[0][i]<<" ";cerr<<endl;
	for(int i=2;i<=n;i++)
	{
		if(mn[0][i]==inf)
		{
			puts("-1");
			return 0;
		}
		sum+=mn[0][i];
	}
	cout<<sum<<endl;
	return 0;
}