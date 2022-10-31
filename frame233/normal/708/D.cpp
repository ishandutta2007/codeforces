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

const int N=105;
struct edge{
	int v,nxt,w,cost;
}c[N<<5];
int front[N],edge_cnt=-1;
Finline void addedge(int u,int v,int w,int cost)
{
	c[++edge_cnt]=(edge){v,front[u],w,cost};
	front[u]=edge_cnt;
	
	c[++edge_cnt]=(edge){u,front[v],0,-cost};
	front[v]=edge_cnt;
}
int cur[N],dep[N],S,T;
int _q[N*N<<5],_l,_r;
bool inq[N];
bool bfs()
{
	memset(dep,63,sizeof(dep));
	memcpy(cur,front,sizeof(front));
	memset(inq,0,sizeof(inq));
	dep[S]=0,_q[_l=_r=1]=S;
	while(_l!=_r+1)
	{
		int x=_q[_l++];
		inq[x]=false;
		for(int i=front[x];~i;i=c[i].nxt)
		{
			int v=c[i].v;
			if(c[i].w&&dep[v]>dep[x]+c[i].cost)
			{
				dep[v]=dep[x]+c[i].cost;
				if(!inq[v]) _q[++_r]=v,inq[v]=true;
			}
		}
	}
	return dep[T]<inf;
}
int dfs(int x,int flow)
{
	if(x==T||!flow) return flow;
	inq[x]=true;
	int f=0,rf;
	for(int &i=cur[x];~i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(!inq[v]&&dep[v]==dep[x]+c[i].cost&&(rf=dfs(v,min(flow,c[i].w))))
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
	while(bfs()) ans+=dfs(S,inf)*dep[T];
	return ans;
}
int in[N],out[N];
int main()
{
	memset(front,255,sizeof(front));
	int n,m;read(n,m);
	int u,v,c,f;
	int ans=0;
	for(int i=1;i<=m;++i)
	{
		read(u,v,c,f);
		in[v]+=f,out[u]+=f;
		if(f<=c)
		{
			addedge(v,u,f,1);
			addedge(u,v,c-f,1);
			addedge(u,v,inf,2);
		}
		else
		{
			ans+=f-c;
			addedge(v,u,c,1);
			addedge(v,u,f-c,0);
			addedge(u,v,inf,2);
		}
	}
	addedge(n,1,inf,0);
	S=n+1,T=n+2;
	for(int i=1;i<=n;++i)
	{
		if(in[i]>out[i]) addedge(S,i,in[i]-out[i],0);
		else if(in[i]<out[i]) addedge(i,T,out[i]-in[i],0);
	}
	printf("%d\n",dinic()+ans);
	return 0;
}