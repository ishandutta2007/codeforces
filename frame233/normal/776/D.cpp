// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>

#define Finline __inline__ __attribute__ ((always_inline))

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7ffffffffffffff;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp& t, Args&... args)
{
    read(t);read(args...);
}
Finline int read_str(char *s)
{
    register char ch(getchar());
    while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}

const int N=200005;
struct edge{
	int v,nxt;
}c[N<<2];
int a[N>>1];
int b[N>>1][2];
int front[N],cnt;
int dfn[N],low[N],id,bel[N],col;
int st[N],top;
bool vis[N];
Finline void add(const int &u,const int &v){c[++cnt]=(edge){v,front[u]},front[u]=cnt;}
void tarjan(int x)
{
	dfn[x]=low[x]=++id;
	st[++top]=x,vis[x]=1;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(!dfn[c[i].v])
		{
			tarjan(c[i].v);
			chmin(low[x],low[c[i].v]);
		}
		else if(vis[c[i].v])
		{
			chmin(low[x],dfn[c[i].v]);
		}
	}
	if(dfn[x]==low[x])
	{
		bel[x]=++col;
		vis[x]=0;
		while(st[top]!=x)
		{
			bel[st[top]]=col;
			vis[st[top--]]=0;
		}
		--top;
	}
}
int main()
{
	int n,m,tot,x;
	read(n,m);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
	}
	for(int i=1;i<=m;++i)
	{
		read(tot);
		while(tot--)
		{
			read(x);
			if(b[x][0]) b[x][1]=i;
			else b[x][0]=i;
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(!a[i])
		{
			add(b[i][0]+m,b[i][1]);
			add(b[i][0],b[i][1]+m);
			add(b[i][1]+m,b[i][0]);
			add(b[i][1],b[i][0]+m);
		}
		else
		{
			add(b[i][0],b[i][1]);
			add(b[i][0]+m,b[i][1]+m);
			add(b[i][1],b[i][0]);
			add(b[i][1]+m,b[i][0]+m);
		}
	}
	for(int i=1;i<=(m<<1);++i)
	{
		if(!dfn[i])
		{
			tarjan(i);
		}
	}
	for(int i=1;i<=m;++i)
	{
		if(bel[i]==bel[i+m])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
    return 0;
}
//Dpair_cxe