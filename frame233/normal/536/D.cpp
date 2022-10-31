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
	static uint seed=0x05ad13b4;
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

const int N=2005;
struct edge{
	int v,nxt,w;
}c[N*100];
int front[N],edge_cnt;
Finline void addedge(int u,int v,int w)
{
	c[++edge_cnt]=(edge){v,front[u],w};
	front[u]=edge_cnt;
}
struct node{
	int u;
	ll d;
	Finline bool operator < (const node &o)const
	{
		return d>o.d;
	}
};
std::priority_queue<node> q;
ll dis[N];
std::vector<int> t1[N],t2[N];
ll t[N];
int n;
int dij(int s,std::vector<int> *T)
{
	memset(dis,63,sizeof(dis));
	dis[s]=0;
	q.push((node){s,0});
	while(!q.empty())
	{
		node x=q.top();
		q.pop();
		if(dis[x.u]!=x.d) continue;
		for(int i=front[x.u];i;i=c[i].nxt)
		{
			if(dis[c[i].v]>dis[x.u]+c[i].w)
			{
				dis[c[i].v]=dis[x.u]+c[i].w;
				q.push((node){c[i].v,dis[c[i].v]});
			}
		}
	}
	for(int i=1;i<=n;++i) t[i]=dis[i];
	std::sort(t+1,t+n+1);
	int pos=std::unique(t+1,t+n+1)-t-1;
	for(int i=1;i<=n;++i) T[std::lower_bound(t+1,t+pos+1,dis[i])-t].pb(i);
	return pos;
}
int p[N];
ll f[N][N],g[N][N];
int nxt1[N][N],nxt2[N][N];
bool used[N];
bool st1[N][N],st2[N][N];
int main()
{
	int m;
	read(n,m);
	int s,t;
	read(s,t);
	for(int i=1;i<=n;++i) read(p[i]);
	int x,y,z;
	for(int i=1;i<=m;++i)
	{
		read(x,y,z);
		addedge(x,y,z),addedge(y,x,z);
	}
	int r=dij(s,t1);
	int c=dij(t,t2);
	std::reverse(t1+1,t1+r+1);
	std::reverse(t2+1,t2+c+1);
	for(int i=0;i<=r;++i)
	{
		for(auto it:t1[i]) used[it]=true;
		int last=c+1;
		for(int j=c;j>=0;--j)
		{
			nxt1[i][j]=last;
			for(auto it:t2[j]) if(used[it]) last=j;
		}
		memcpy(st1[i],used,sizeof(used));
	}
	memset(used,0,sizeof(used));
	for(int i=0;i<=c;++i)
	{
		for(auto it:t2[i]) used[it]=true;
		int last=r+1;
		for(int j=r;j>=0;--j)
		{
			nxt2[i][j]=last;
			for(auto it:t1[j]) if(used[it]) last=j;
		}
		memcpy(st2[i],used,sizeof(used));
	}
	memset(f,-63,sizeof(f));
	memset(g,63,sizeof(g));
	f[0][0]=g[0][0]=0;
	for(int i=0;i<=r;++i)
	{
		for(int j=0;j<=c;++j)
		{
			if(f[i][j]>-1e18)
			{
				ll tmp=0;
				for(auto it:t1[i+1]) if(st2[j][it]) tmp+=p[it];
				chmax(f[i+1][j],f[i][j]+tmp);
				
				int pos=nxt1[i][j];
				tmp=0;
				for(auto it:t2[pos]) if(st1[i][it]) tmp+=p[it];
				chmin(g[i][pos],f[i][j]-tmp);
			}
			
			if(g[i][j]<1e18)
			{
				ll tmp=0;
				for(auto it:t2[j+1]) if(st1[i][it]) tmp+=p[it];
				chmin(g[i][j+1],g[i][j]-tmp);
				
				int pos=nxt2[j][i];
				tmp=0;
				for(auto it:t1[pos]) if(st2[j][it]) tmp+=p[it];
				chmax(f[pos][j],g[i][j]+tmp);
			}
		}
	}
	fprintf(stderr,"@ %lld\n",f[r][c]);
	if(f[r][c]>0) puts("Break a heart");
	else if(f[r][c]<0) puts("Cry");
	else puts("Flowers");
	return 0;
}