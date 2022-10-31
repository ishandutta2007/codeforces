// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
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

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>inline void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=55;
struct edge{
	int v,nxt,w,cost;
}c[N*N<<2];
int front[N],edge_cnt=-1;
inline void addedge(int u,int v,int w,int cost)
{
	c[++edge_cnt]=(edge){v,front[u],w,cost},front[u]=edge_cnt;
	c[++edge_cnt]=(edge){u,front[v],0,-cost},front[v]=edge_cnt;
}
int dep[N],cur[N],S,T,_q[N*N],_l,_r,pre[N];
bool inq[N];
bool bfs()
{
	memset(dep,63,sizeof(dep));
	dep[S]=0,_q[_l=_r=1]=S;
	while(_l!=_r+1)
	{
		int x=_q[_l++];inq[x]=false;
		for(int i=front[x];~i;i=c[i].nxt)
		{
			int v=c[i].v;
			if(c[i].w&&dep[v]>dep[x]+c[i].cost)
			{
				dep[v]=dep[x]+c[i].cost,pre[v]=i;
				if(!inq[v]) _q[++_r]=v,inq[v]=true;
			}
		}
	}
	return dep[T]<inf;
}
int C[N],pos;
void MCMF()
{
	int ans=0;
	while(bfs())
	{
		int cur=T;
		while(cur!=S)
		{
			int id=pre[cur];
			--c[id].w,++c[id^1].w;
			ans+=c[id].cost;
			cur=c[id^1].v;
		}
		C[++pos]=ans;
	}
}
int main()
{
	memset(front,255,sizeof(front));
	int n,m;read(n,m);
	int x,y,z;S=1,T=n;
	for(int i=1;i<=m;++i) read(x,y,z),addedge(x,y,1,z);
	MCMF();
	int _;read(_);
	while(_--)
	{
		read(x);
		double ans=1e18;
		for(int i=1;i<=pos;++i) chmin(ans,(double)(x+C[i])/i);
		printf("%.8lf\n",ans);
	}
	return 0;
}