// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;

Finline uint rnd()
{
	static uint seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());
	bool f(false);
	while(ch<48||ch>57) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
	read(t);read(args...);
}
Finline int read_str(char *s)
{
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=200005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
Finline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int tag;
int bel[N],siz[N];
int t[N],pos,fir[N];
int dep[N];
std::vector<int> nd[N],V[N];
int val[N];
int u[N],v[N],len[N];
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	t[++pos]=x;
	fir[x]=pos;
	bel[x]=tag;
	nd[tag].pb(x);
	++siz[tag];
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v!=fa)
		{
			dfs(v,x);
			t[++pos]=x;
		}
	}
}
int maxx,rt;
void dfs1(int x,int fa,int dis)
{
	++dis;
	if(dis>maxx)
	{
		maxx=dis;
		rt=x;
	}
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa)
		{
			dfs1(c[i].v,x,dis);
		}
	}
}
int f[N][21],Log2[N];
void init()
{
	for(int i=2;i<N;++i) Log2[i]=Log2[i>>1]+1;
	for(int i=pos;i>=1;--i)
	{
		f[i][0]=t[i];
		for(int j=1;j<=20&&i+(1<<(j-1))<=pos;++j)
		{
			f[i][j]=dep[f[i][j-1]]<dep[f[i+(1<<(j-1))][j-1]]?f[i][j-1]:f[i+(1<<(j-1))][j-1];
		}
	}
}
Finline int lca(int x,int y)
{
	int l=fir[x],r=fir[y];
	if(l>r) std::swap(l,r);
	int k=Log2[r-l+1];
	return dep[f[l][k]]<dep[f[r-(1<<k)+1][k]]?f[l][k]:f[r-(1<<k)+1][k];
}
Finline int getdis(int x,int y)
{
	return dep[x]+dep[y]-(dep[lca(x,y)]<<1);
}
std::vector<ll> suf[N];
std::map<pi,double> mp;
double solve(int x,int y)
{
	pi qwq=mkpr(x,y);
	if(mp.find(qwq)!=mp.end()) return mp[qwq];
	int tmp=max(len[x],len[y]);
	ll ans=0;
	for(auto it:nd[x])
	{
		int pos=std::lower_bound(V[y].begin(),V[y].end(),tmp-val[it]-1)-V[y].begin();
		ans+=suf[y][pos]+1ll*(val[it]+1)*(siz[y]-pos);
		ans+=1ll*pos*tmp;
	}
	return mp[qwq]=(double)ans/(double)(1ll*siz[x]*siz[y]);
}
int main()
{
	int n,m,q;
	read(n,m,q);
	int x,y;
	for(int i=1;i<=m;++i)
	{
		read(x,y);
		addedge(x,y),addedge(y,x);
	}
	for(int i=1;i<=n;++i)
	{
		if(!bel[i])
		{
			++tag;
			dfs(i,0);
			rt=0,maxx=-1;
			dfs1(i,0,-1);
			int tmp=rt;
			rt=0,maxx=-1;
			dfs1(tmp,0,-1);
			u[tag]=tmp;
			v[tag]=rt;
			len[tag]=maxx;
		}
	}
	init();
	for(int i=1;i<=tag;++i)
	{
		for(auto it:nd[i])
		{
			val[it]=max(getdis(it,u[i]),getdis(it,v[i]));
		}
		std::sort(nd[i].begin(),nd[i].end(),[&](int A,int B)->bool{return val[A]<val[B];});
		V[i].resize(SZ(nd[i]));
		suf[i].resize(SZ(nd[i])+1);
		for(int j=SZ(nd[i])-1;j>=0;--j)
		{
			V[i][j]=val[nd[i][j]];
			suf[i][j]=suf[i][j+1]+V[i][j];
		}
	}
	while(q--)
	{
		read(x,y);
		x=bel[x],y=bel[y];
		if(x==y)
		{
			printf("-1\n");
			continue;
		}
		if(siz[x]>siz[y]) std::swap(x,y);
		printf("%.12lf\n",solve(x,y));
	}
	return 0;
}