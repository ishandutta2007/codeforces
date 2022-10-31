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

const int N=200005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
Finline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int a[N],b[N],C[N];
int r1[N],r2[N];
ll ans;
void dfs(int x,int fa,int val)
{
	chmin(val,a[x]);
	if(b[x]!=C[x])
	{
		if(b[x]==0) ++r1[x];
		else ++r2[x];
	}
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v!=fa)
		{
			dfs(v,x,val);
			r1[x]+=r1[v];
			r2[x]+=r2[v];
		}
	}
	int tmp=min(r1[x],r2[x]);
	r1[x]-=tmp,r2[x]-=tmp;
	ans+=1ll*tmp*val;
}
int main()
{
	int n;
	read(n);
	int x,y;
	for(int i=1;i<=n;++i)
	{
		read(a[i],b[i],C[i]);
	}
	for(int i=1;i<n;++i)
	{
		read(x,y);
		addedge(x,y),addedge(y,x);
	}
	dfs(1,0,inf);
	if(r1[1]||r2[1]) printf("-1\n");
	else printf("%lld\n",ans<<1);
	return 0;
}