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
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp,typename... Args>Finline _Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>Finline _Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
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
ll t[N],f[N],g[N],h[N];
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
Finline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int in[N],out[N],a[N];
bool vis[N];
ll ans;
void dfs(int x,int fa)
{
	vis[x]=true;
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v==fa) continue;
		dfs(v,x);
	}
	int pos=0;ll sum=0;
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v==fa) continue;
		a[++pos]=g[v]-f[v],sum+=f[v];
	}
	std::sort(a+1,a+pos+1);
	if(fa)
	{
		f[x]=g[x]=1e18;
		chmin(f[x],1ll*max(in[x]+1,pos+out[x])*t[x]+sum);
		chmin(g[x],1ll*max(in[x],pos+1+out[x])*t[x]+sum);
		for(int i=1;i<=pos;++i)
		{
			sum+=a[i];
			chmin(f[x],1ll*max(i+in[x]+1,pos-i+out[x])*t[x]+sum);
			chmin(g[x],1ll*max(i+in[x],pos-i+1+out[x])*t[x]+sum);
		}
	}
	else
	{
		ll tmp=1ll*max(in[x],pos+out[x])*t[x]+sum;
		for(int i=1;i<=pos;++i) sum+=a[i],chmin(tmp,1ll*max(in[x]+i,pos-i+out[x])*t[x]+sum);
		ans+=tmp;
	}
}
int main()
{
	int n;read(n);
	for(int i=1;i<=n;++i) read(t[i]);
	for(int i=1;i<=n;++i) read(h[i]);
	int x,y;
	for(int i=1;i<n;++i)
	{
		read(x,y);
		if(h[x]==h[y]) addedge(x,y),addedge(y,x);
		else
		{
			if(h[x]<h[y]) ++out[x],++in[y];
			else ++out[y],++in[x];
		}
	}
	for(int i=1;i<=n;++i) if(!vis[i]) dfs(i,0);
	printf("%lld\n",ans);
	return 0;
}