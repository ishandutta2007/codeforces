// Author -- xyr2005

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

Finline uint rnd(){static uint seed=416;return seed+=0x71dad4bfu,seed^=seed>>5,seed+=0xc6f74d88u,seed^=seed<<17,seed+=0x25e6561u,seed^=seed>>13;}
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

const int N=200005;
namespace flow
{
	struct edge{
		int v,nxt;
		int w;
	}c[N<<3];
	int front[N],edge_cnt;
	int cur[N],dep[N],S,T;
	int _q[N],_l,_r;
	int node_cnt;
	Finline void addedge(int u,int v,int w)
	{
		c[++edge_cnt]=(edge){v,front[u],w},front[u]=edge_cnt;
		c[++edge_cnt]=(edge){u,front[v],0},front[v]=edge_cnt;
	}
	Finline void init(){memset(front,255,sizeof(front)),edge_cnt=-1;}
	bool bfs()
	{
		memset(dep,255,(node_cnt+3)<<2);
		memcpy(cur,front,(node_cnt+3)<<2);
		dep[S]=0;
		_q[_l=_r=1]=S;
		while(_l!=_r+1)
		{
			int x=_q[_l++];
			for(int i=front[x];~i;i=c[i].nxt)
			{
				if(c[i].w&&!~dep[c[i].v])
				{
					dep[c[i].v]=dep[x]+1;
					_q[++_r]=c[i].v;
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
}
using namespace flow;
int tx[N],ty[N],p1,p2;
int X[N],Y[N];
int C[N],D[N];
int qwq[N];
std::map<pi,int> mp;
int main()
{
	init();
	int n,m;read(n,m);
	int r,b;read(r,b);
	int x,y,type;
	for(int i=1;i<=n;++i)
	{
		read(x,y),X[i]=x,Y[i]=y;
		tx[i]=x,ty[i]=y;
	}
	std::sort(tx+1,tx+n+1),std::sort(ty+1,ty+n+1),p1=std::unique(tx+1,tx+n+1)-tx-1,p2=std::unique(ty+1,ty+n+1)-ty-1;
	for(int i=1;i<=n;++i)
	{
		++C[X[i]=std::lower_bound(tx+1,tx+p1+1,X[i])-tx];
		++C[Y[i]=(std::lower_bound(ty+1,ty+p2+1,Y[i])-ty+p1)];
	}
	for(int i=1;i<=p1+p2;++i) D[i]=C[i];
	for(int i=1;i<=m;++i)
	{
		read(type,x,y);
		if(type==1)
		{
			int pos=std::lower_bound(tx+1,tx+p1+1,x)-tx;
			if(tx[pos]==x) chmin(D[pos],y);
		}
		else
		{
			int pos=std::lower_bound(ty+1,ty+p2+1,x)-ty;
			if(ty[pos]==x) chmin(D[pos+p1],y);
		}
	}
	int s=p1+p2+1,t=s+1;
	S=t+1,T=S+1,node_cnt=T;
	for(int i=1;i<=n;++i) addedge(X[i],Y[i],1);
	for(int i=1;i<=p1;++i)
	{
		int L=(C[i]-D[i]+1)>>1,R=(C[i]+D[i])>>1;
		if(L>R) return puts("-1"),0;
		qwq[s]-=L,qwq[i]+=L;
		addedge(s,i,R-L);
	}
	for(int i=p1+1;i<=p1+p2;++i)
	{
		int L=(C[i]-D[i]+1)>>1,R=(C[i]+D[i])>>1;
		if(L>R) return puts("-1"),0;
		qwq[i]-=L,qwq[t]+=L;
		addedge(i,t,R-L);
	}
	int pos=edge_cnt,sum=0;
	addedge(t,s,inf);
	for(int i=1;i<=p1+p2+2;++i)
	{
		if(qwq[i]>0) addedge(S,i,qwq[i]),sum+=qwq[i];
		else if(qwq[i]<0) addedge(i,T,-qwq[i]);
	}
	if(dinic()!=sum) return puts("-1"),0;
	int ans=c[pos+2].w;
	while(edge_cnt>pos) c[edge_cnt--].w=0;
	S=s,T=t;
	ans+=dinic();
	printf("%lld\n",1ll*ans*min(r,b)+1ll*(n-ans)*max(r,b));
	for(int i=1;i<=p1;++i)
	{
		for(int _=front[i];~_;_=c[_].nxt)
		{
			int v=c[_].v;
			if(v>p1&&v<=p1+p2&&!c[_].w) ++mp[mkpr(i,v)];
		}
	}
	for(int i=1;i<=n;++i)
	{
		pi tmp=mkpr(X[i],Y[i]);
		if(mp[tmp])
		{
			--mp[tmp];
			putchar(r<b?'r':'b');
		}
		else putchar(r<b?'b':'r');
	}
	putchar('\n');
	return 0;
}