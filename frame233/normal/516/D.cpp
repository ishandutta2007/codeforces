// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp &x)
{
	register char ch(getchar());
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
	register char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=100005;
struct edge{
	int v,nxt,w;
}c[N<<1];
int front[N],cnt_;
Finline void add(int u,int v,int w)
{
	c[++cnt_]=(edge){v,front[u],w},front[u]=cnt_;
}
ll dp1[N],dp2[N],f[N];
void dfs1(int x,int fa)
{	
	dp1[x]=0;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa)
		{
			dfs1(c[i].v,x);
			if(dp1[c[i].v]+c[i].w>dp1[x])
			{
				dp2[x]=dp1[x];
				dp1[x]=dp1[c[i].v]+c[i].w;
			}
			else if(dp1[c[i].v]+c[i].w>dp2[x])
			{
				dp2[x]=dp1[c[i].v]+c[i].w;
			}
		}
	}
}
void dfs2(int x,int fa,int val)
{
	if(fa)
	{
		ll tmp;
		if(dp1[fa]==dp1[x]+val)
		{
			tmp=dp2[fa];
		}
		else
		{
			tmp=dp1[fa];
		}
		tmp+=val;
		if(tmp>dp1[x])
		{
			dp2[x]=dp1[x];
			dp1[x]=tmp;
		}
		else if(tmp>dp2[x])
		{
			dp2[x]=tmp;
		}
	}
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa)
		{
			dfs2(c[i].v,x,c[i].w);
		}
	}
}
int a[N];
int fa[N],siz[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int maxx;
int cnt[N];
void merge(int a,int b)
{
	a=find(a);
	b=find(b);
	--cnt[siz[b]];
	--cnt[siz[a]];
	if(siz[a]>siz[b])
	{
		fa[b]=a;
		siz[a]+=siz[b];
		++cnt[siz[a]];
		chmax(maxx,siz[a]);
	}
	else
	{
		fa[a]=b;
		siz[b]+=siz[a];
		++cnt[siz[b]];
		chmax(maxx,siz[b]);
	}
}
void dec(int x)
{
	x=find(x);
	--cnt[siz[x]];
	--siz[x];
	++cnt[siz[x]];
	if(!cnt[maxx]) --maxx;
}
bool used[N];
int main()
{
	int n;
	read(n);
	int x,y,z;
	for(int i=1;i<n;++i)
	{
		read(x,y,z);
		add(x,y,z),add(y,x,z);
	}
	dfs1(1,0);
	dfs2(1,0,0);
	for(int i=1;i<=n;++i) f[i]=dp1[i],a[i]=i;
	std::sort(a+1,a+n+1,[](const int &a,const int &b)->bool{return f[a]>f[b];});
	int _;
	read(_);
	ll L;
	while(_--)
	{
		read(L);
		for(int i=1;i<=n;++i)
		{
			fa[i]=i;
			siz[i]=1;
			used[i]=false;
			cnt[i]=0;
		}
		cnt[1]=n;
		maxx=1;
		int pos=1;
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			for(int _=front[a[i]];_;_=c[_].nxt)
			{
				if(used[c[_].v])
				{
					merge(a[i],c[_].v);
				}
			}
			used[a[i]]=true;
			while(pos<=n&&f[a[pos]]-f[a[i]]>L)
			{
				dec(a[pos]);
				++pos;
			}
			chmax(ans,maxx);
		}
		printf("%d\n",ans);
	}
	return 0;
}