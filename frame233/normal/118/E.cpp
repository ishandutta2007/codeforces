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
const ll INF=0x3f3f3f3f3f3f3f3f;

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

const int N=300005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt=-1;
Finline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int u[N],v[N];
int dfn[N],low[N],id;
bool vis[N];
bool dir[N];
void dfs(int x,int fa)
{
	dfn[x]=low[x]=++id;
	vis[x]=true;
	for(int i=front[x];~i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v!=fa)
		{
			if(!vis[v])
			{
				dfs(v,x);
				dir[i>>1]=i&1;
				chmin(low[x],low[v]);
				if(low[v]>dfn[x])
				{
					printf("0\n");
					exit(0);
				}
			}
			else
			{
				dir[i>>1]=!(i&1);
				chmin(low[x],dfn[v]);
			}
		}
	}
}
int main()
{
	memset(front,255,sizeof(front));
	int n,m;
	read(n,m);
	int x,y;
	for(int i=0;i<m;++i)
	{
		read(x,y);
		addedge(x,y),addedge(y,x);
		u[i]=x,v[i]=y;
	}
	dfs(1,0);
	for(int i=0;i<m;++i)
	{
		if(dir[i]) printf("%d %d\n",v[i],u[i]);
		else printf("%d %d\n",u[i],v[i]);
	}
	return 0;
}