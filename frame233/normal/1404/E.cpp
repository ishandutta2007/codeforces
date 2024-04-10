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
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd(){static uint seed=416;return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
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

const int N=90005;
struct edge{
	int v,nxt,w;
}c[N<<4];
int front[N],edge_cnt=-1;
Finline void addedge(int u,int v,int w)
{
	c[++edge_cnt]=(edge){v,front[u],w};
	front[u]=edge_cnt;
	
	c[++edge_cnt]=(edge){u,front[v],0};
	front[v]=edge_cnt;
}
int dep[N],cur[N],S,T,node_cnt;
int _q[N],_l,_r;
bool bfs()
{
	memset(dep,255,(node_cnt+3)<<2);
	memcpy(cur,front,(node_cnt+3)<<2);
	_q[_l=_r=1]=S,dep[S]=0;
	while(_l!=_r+1)
	{
		int x=_q[_l++];
		for(int i=front[x];~i;i=c[i].nxt)
		{
			int v=c[i].v;
			if(c[i].w&&dep[v]==-1)
			{
				dep[v]=dep[x]+1;
				_q[++_r]=v;
			}
		}
	}
	return ~dep[T];
}
int dfs(int x,int flow)
{
	if(x==T||!flow) return flow;
	int f=0,rf;
	for(int &i=cur[x];~i;i=c[i].nxt)
	{
		if(dep[c[i].v]==dep[x]+1&&(rf=dfs(c[i].v,min(flow,c[i].w))))
		{
			flow-=rf,f+=rf;
			c[i].w-=rf,c[i^1].w+=rf;
			if(!flow) return f;
		}
	}
	return f;
}
int dinic()
{
	int ans=0;
	while(bfs()) ans+=dfs(S,inf);
	return ans;
}
char s[205][205];
int n,m;
Finline int getid(int x,int y,int type)
{
	if(!type) return (x-1)*(m+1)+y+1;
	else return x*m+y+n*(m+1);
}
int main()
{
	memset(front,255,sizeof(front));
	read(n,m);
	for(int i=1;i<=n;++i) read_str(s[i]+1);
	S=n*(m+1)+(n+1)*m+1,T=S+1,node_cnt=T;
	int cnt=0,rest=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(s[i][j]!='#') continue;
			++rest;
			if(s[i][j+1]=='#') addedge(S,getid(i,j,0),1),++cnt;
			if(s[i+1][j]=='#') addedge(getid(i,j,1),T,1),++cnt;
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			addedge(getid(i,j,0),getid(i,j,1),inf);
			addedge(getid(i,j,0),getid(i-1,j,1),inf);
			addedge(getid(i,j-1,0),getid(i,j,1),inf);
			addedge(getid(i,j-1,0),getid(i-1,j,1),inf);
		}
	}
	printf("%d\n",rest-cnt+dinic());
	return 0;
}