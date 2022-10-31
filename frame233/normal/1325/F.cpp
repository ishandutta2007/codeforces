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

uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}

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
	bool used;
}c[N<<1];
int front[N],cnt=-1;
Finline void add(int u,int v)
{
	c[++cnt]=(edge){v,front[u],0},front[u]=cnt;
}
int dg[N];
bool used[N];
void del(int x)
{
	if(used[x]) return;
	used[x]=true;
	for(int i=front[x];~i;i=c[i].nxt) --dg[c[i].v];
}
int t[N],id;
int nxt[N];
int qwq=1;
void dfs(int x)
{
	t[x]=++id;
	for(int i=front[x];~i;i=c[i].nxt)
	{
		if(!used[c[i].v]&&!t[c[i].v])
		{
			nxt[x]=c[i].v;
			dfs(c[i].v);
			return;
		}
	}
	for(int i=front[x];~i;i=c[i].nxt)
	{
		if(!used[c[i].v]&&t[x]-t[c[i].v]+1>=qwq)
		{
			int cur=c[i].v;
			printf("2\n%d\n",t[x]-t[c[i].v]+1);
			while(cur)
			{
				printf("%d ",cur);
				cur=nxt[cur];
			}
			printf("\n");
			exit(0);
		}
	}
}
int main()
{
	memset(front,255,sizeof(front));
	int n,m;
	read(n,m);
	int x,y;
	for(int i=1;i<=m;++i)
	{
		read(x,y);
		add(x,y),add(y,x);
		++dg[x],++dg[y];
	}
	while(qwq*qwq<n) ++qwq;
	std::vector<int> ans;
	for(int i=1;i<=qwq;++i)
	{
		int nd=0;
		for(int j=1;j<=n;++j)
		{
			if(!used[j]&&dg[j]<qwq-1)
			{
				nd=j;
				break;
			}
		}
		if(!nd)
		{
			break;
		}
		del(nd);
		for(int j=front[nd];~j;j=c[j].nxt)
		{
			del(c[j].v);
		}
		ans.push_back(nd);
		if(i==qwq)
		{
			printf("1\n");
			for(auto it:ans) printf("%d ",it);
			printf("\n");
			return 0;
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(!used[i])
		{
			dfs(i);
			exit(233);
		}
	}
	return 0;
}