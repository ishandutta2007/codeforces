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

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;

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

const int N=400005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
Finline void add(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int dis[3][N];
int _q[N],_l,_r;
void bfs(int s,int *dis)
{
	dis[s]=0;
	_q[_l=_r=1]=s;
	while(_l!=_r+1)
	{
		int x=_q[_l++];
		for(int i=front[x];i;i=c[i].nxt)
		{
			if(!~dis[c[i].v])
			{
				dis[c[i].v]=dis[x]+1;
				_q[++_r]=c[i].v;
			}
		}
	}
}
int p[N];
int minn[N];
ll sum[N];
void MAIN()
{
	edge_cnt=0;
	int n,m,a,b,c;
	read(n,m,a,b,c);
	memset(front,0,(m+3)<<2);
	for(int i=0;i<3;++i) memset(dis[i],255,(n+3)<<2);
	memset(minn,63,(m+m+3)<<2);
	memset(p,0,(m+m+3)<<2);
	for(int i=1;i<=m;++i) read(p[i]);
	int x,y;
	for(int i=1;i<=m;++i)
	{
		read(x,y);
		add(x,y),add(y,x);
	}
	bfs(b,dis[0]);
	bfs(a,dis[1]);
	bfs(c,dis[2]);
	for(int i=1;i<=n;++i)
	{
		chmin(minn[dis[0][i]],dis[1][i]+dis[2][i]);
	}
	std::sort(p+1,p+m+1);
	for(int i=1;i<=m+m;++i) sum[i]=sum[i-1]+p[i];
	ll ans=1e18;
	for(int i=0;i<=m;++i)
	{
		if(minn[i]+i<=m)
		{
			chmin(ans,sum[i]+sum[minn[i]+i]);
		}
	}
	printf("%lld\n",ans);
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}