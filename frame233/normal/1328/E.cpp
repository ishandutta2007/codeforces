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
 
const int N=200005;
struct edge{
	int v,nxt;
}c[N<<1];
int front[N],edge_cnt;
Finline void add(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]},front[u]=edge_cnt;
}
int siz[N],dfn[N],id,Fa[N];
void dfs(int x,int fa)
{
	siz[x]=1;
	dfn[x]=++id;
	Fa[x]=fa;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(c[i].v!=fa)
		{
			dfs(c[i].v,x);
			siz[x]+=siz[c[i].v];
		}
	}
}
int t[N];
int main()
{
	int n,m;
	read(n,m);
	int x,y;
	for(int i=1;i<n;++i)
	{
		read(x,y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	Fa[1]=1;
	while(m--)
	{
		int k;
		read(k);
		for(int i=1;i<=k;++i)
		{
			read(t[i]);
			t[i]=Fa[t[i]];
		}
		t[++k]=1;
		std::sort(t+1,t+k+1,[](const int &a,const int &b)->bool{return dfn[a]<dfn[b];});
		bool flag=true;
		for(int i=1;i<k;++i)
		{
			if(!(dfn[t[i+1]]>=dfn[t[i]]&&dfn[t[i+1]]<dfn[t[i]]+siz[t[i]]))
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}