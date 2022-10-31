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

const int N=1000005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
Finline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int dis[N],_q[N],_l,_r;
int col[N];
bool vis[N];
int main()
{
	int n,m;read(n,m);
	int x,y,t;
	for(int i=1;i<=m;++i)
	{
		read(x,y,t);
		addedge(y,x+t*n);
		addedge(y+n,x+t*n);
	}
	memset(dis,255,sizeof(dis));
	dis[n]=dis[n+n]=0;
	_q[_l=_r=1]=n;_q[++_r]=n+n;
	while(_l!=_r+1)
	{
		int x=_q[_l++];
		if(!vis[x>n?x-n:x])
		{
			vis[x>n?x-n:x]=true;
			col[x>n?x-n:x]=x<=n;
			dis[x]=0;
			continue;
		}
		for(int i=front[x];i;i=c[i].nxt)
		{
			int v=c[i].v;
			if(dis[v]==-1)
			{
				dis[v]=dis[x]+1;
				_q[++_r]=v;
			}
		}
	}
	if(dis[1]==-1) dis[1]=inf;
	if(dis[n+1]==-1) dis[n+1]=inf;
	int ans=max(dis[1],dis[n+1]);
	if(ans==inf) printf("-1\n");
	else printf("%d\n",ans);
	for(int i=1;i<=n;++i) printf("%d",col[i]);
	printf("\n");
	return 0;
}