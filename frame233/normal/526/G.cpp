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
struct node{
	int val,id;
	Finline bool operator < (const node &o)const
	{
		return val>o.val;
	}
};
struct Tree{
	int root;
	int len[N],son[N],Fa[N],top[N];
	int dis[N];
	int f[N][19],w[N][19];
	void dfs1(int x,int fa)
	{
		Fa[x]=fa;
		for(int i=front[x];i;i=c[i].nxt)
		{
			if(c[i].v!=fa)
			{
				dis[c[i].v]=dis[x]+c[i].w;
				dfs1(c[i].v,x);
				if(len[c[i].v]+c[i].w>len[x])
				{
					len[x]=len[c[i].v]+c[i].w;
					son[x]=c[i].v;
				}
			}
		}
	}
	node a[N];
	int pos;
	void dfs2(int x,int topf)
	{
		top[x]=topf;
		if(!son[x])
		{
			a[++pos]=(node){dis[x]-dis[Fa[topf]],x};
			return;
		}
		dfs2(son[x],topf);
		for(int i=front[x];i;i=c[i].nxt)
		{
			if(!top[c[i].v])
			{
				dfs2(c[i].v,c[i].v);
			}
		}
	}
	int tim[N];
	void dfs3(int x,int fa)
	{
		f[x][0]=fa;
		for(int i=1;i<=18;++i)
		{
			f[x][i]=f[f[x][i-1]][i-1];
		}
		for(int i=front[x];i;i=c[i].nxt)
		{
			if(c[i].v!=fa)
			{
				dfs3(c[i].v,x);
				chmin(tim[x],tim[c[i].v]);
			}
		}
	}
	int ans[N];
	void init(int _root)
	{
		memset(tim,63,sizeof(tim));
		root=_root;
		dfs1(root,0);
		dfs2(root,root);
		std::sort(a+1,a+pos+1);
		for(int i=1;i<=pos;++i)
		{
			tim[a[i].id]=i;
			ans[i]=ans[i-1]+a[i].val;
		}
		dfs3(root,0);
	}
	int getans(int x,int k)
	{
		if(tim[x]<=k)
		{
			return ans[k];
		}
		int cur=x;
		for(int i=18;i>=0;--i)
		{
			if(f[cur][i]&&tim[f[cur][i]]>k)
			{
				cur=f[cur][i];
			}
		}
		cur=Fa[cur];
		int res=ans[k]+len[x]+dis[x]-dis[cur]-len[cur];
		cur=x;
		for(int i=18;i>=0;--i)
		{
			if(f[cur][i]&&tim[f[cur][i]]>=k)
			{
				cur=f[cur][i];
			}
		}
		cur=Fa[cur];
		return max(res,ans[k-1]+len[x]+dis[x]-dis[cur]);
	}
}tr1,tr2;
int maxx=0,p;
void dfs(int x,int fa,int len)
{
	if(len>maxx)
	{
		maxx=len,p=x;
	}
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa)
		{
			dfs(c[i].v,x,len+c[i].w);
		}
	}
}
int dg[N];
int main()
{
	int n,q;
	read(n,q);
	int x,y,z;
	int sum=0;
	for(int i=1;i<n;++i)
	{
		read(x,y,z);
		add(x,y,z),add(y,x,z);
		sum+=z;
		++dg[x],++dg[y];
	}
	dfs(1,0,0);
	int root1=p;
	maxx=p=0;
	dfs(root1,0,0);
	int root2=p;
	tr1.init(root1);
	tr2.init(root2);
//	fprintf(stderr,"@ %d %d\n",root1,root2);
	int lastans=0;
	int cnt=0;
	for(int i=1;i<=n;++i)
	{
		cnt+=dg[i]==1;
	}
	while(q--)
	{
		read(x,y);
		x=(x+lastans-1)%n+1;
		y=(y+lastans-1)%n+1;
		if(y*2>=cnt)
		{
			printf("%d\n",lastans=sum);
			continue;
		}
		y=y*2-1;
		printf("%d\n",lastans=max(tr1.getans(x,y),tr2.getans(x,y)));
	}
	return 0;
}