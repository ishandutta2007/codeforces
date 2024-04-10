// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
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
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd(){static uint seed=416;return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp,typename... Args>Finline _Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>Finline _Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
Finline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=100005;
struct edge{
	int v,nxt,w;
}c[N<<1];
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
std::priority_queue<node> Q;
ll dis[N];
void dij(int s)
{
	memset(dis,63,sizeof(dis));
	dis[s]=0,Q.push((node){s,0});
	while(!Q.empty())
	{
		node x=Q.top();Q.pop();
		if(x.d!=dis[x.u]) continue;
		for(int i=front[x.u];i;i=c[i].nxt)
		{
			int v=c[i].v;
			if(dis[x.u]+c[i].w<dis[v])
			{
				dis[v]=dis[x.u]+c[i].w;
				Q.push((node){v,dis[v]});
			}
		}
	}
}
int add[N];
std::vector<int> q[N];
int main()
{
	int n,m,_;read(n,m,_);
	int opt,x,y,z;
	for(int i=1;i<=m;++i)
	{
		read(x,y,z);
		addedge(x,y,z);
	}
	dij(1);
	while(_--)
	{
		read(opt,x);
		if(opt==1)
		{
			if(dis[x]<1e18) printf("%lld\n",dis[x]);
			else printf("-1\n");
		}
		else
		{
			for(int i=1;i<=x;++i) read(y),++c[y].w;
			memset(add,63,sizeof(add));
			add[1]=0;for(int i=0;i<=n;++i) q[i].clear();
			q[0].pb(1);
			for(int i=0;i<=x&&i<=n;++i)
			{
				while(!q[i].empty())
				{
					int it=q[i].back();q[i].pop_back();
					if(add[it]!=i) continue;
					for(int _=front[it];_;_=c[_].nxt)
					{
						int v=c[_].v,tmp=dis[it]+add[it]+c[_].w-dis[v];
						if(add[v]>tmp&&tmp<=x&&tmp<=n) add[v]=tmp,q[tmp].pb(v);
					}
				}
			}
			for(int i=1;i<=n;++i) if(add[i]<inf) dis[i]+=add[i];
		}
	}
	return 0;
}