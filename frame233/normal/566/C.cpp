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
typedef std::pair<int,int> pl;

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
	int v,nxt,w;
}c[N<<1];
int front[N],edge_cnt;
Finline void addedge(int u,int v,int w)
{
	c[++edge_cnt]=(edge){v,front[u],w};
	front[u]=edge_cnt;
}
int root,S,_max;
int a[N];
bool vis[N];
int siz[N];
void getrt(int x,int fa)
{
	siz[x]=1;
	int maxx=0;
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v!=fa&&!vis[v])
		{
			getrt(v,x);
			siz[x]+=siz[v];
			chmax(maxx,siz[v]);
		}
	}
	chmax(maxx,S-siz[x]);
	if(maxx<_max)
	{
		root=x;
		_max=maxx;
	}
}
int rt;
double ans=1e30;
int cur;
double tmp;
double d[N];
void getans(int x,int fa,int dis)
{
	tmp+=sqrt(dis)*dis*a[x];
	d[cur]+=1.5*a[x]*sqrt(dis);
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v!=fa)
		{
			getans(v,x,dis+c[i].w);
		}
	}
}
void dfs(int x)
{
	if(vis[x]) return;
	vis[x]=true;
	int pos=0;
	tmp=0.0;
	for(int i=front[x];i;i=c[i].nxt)
	{
		cur=c[i].v;
		d[cur]=0;
		getans(c[i].v,x,c[i].w);
		if(d[cur]>d[pos]) pos=cur;
	}
	if(tmp<ans)
	{
		rt=x;
		ans=tmp;
	}
	S=siz[pos],_max=inf,root=0;
	getrt(pos,x);
	dfs(root);
}
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	int x,y,z;
	for(int i=1;i<n;++i)
	{
		read(x,y,z);
		addedge(x,y,z),addedge(y,x,z);
	}
	root=0,_max=inf,S=n;
	getrt(1,0);
	dfs(root);
	printf("%d %.12lf\n",rt,ans);
	return 0;
}