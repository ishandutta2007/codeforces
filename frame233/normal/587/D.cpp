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
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

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

const int N=100005;
struct node{
	int x,y,val,id;
};
int t[N];
int E[N][4];
std::vector<node> v[N];
std::vector<node> V[N];
int pos,n,m;
struct edge{
	int v,nxt;
}c[N<<5];
int front[N<<5],cnt;
Finline void add(int u,int v)
{
	c[++cnt]=(edge){v,front[u]},front[u]=cnt;
}
int dfn[N<<5],low[N<<5],id;
int st[N<<5],top;
int bel[N<<5],col;
void tarjan(int x)
{
	dfn[x]=low[x]=++id;
	st[++top]=x;
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(!dfn[c[i].v])
		{
			tarjan(c[i].v);
			chmin(low[x],low[c[i].v]);
		}
		else if(!bel[c[i].v])
		{
			chmin(low[x],dfn[c[i].v]);
		}
	}
	if(dfn[x]==low[x])
	{
		bel[x]=++col;
		while(st[top]!=x)
		{
			bel[st[top]]=col;
			--top;
		}
		--top;
	}
}
bool used[N];
int node_cnt;
bool check(int x)
{
	cnt=0;
	memset(front,0,(node_cnt+3)<<2);
	id=col=top=0;
	memset(bel,0,(node_cnt+3)<<2);
	memset(dfn,0,(node_cnt+3)<<2);
	node_cnt=m<<1;
	for(int i=1;i<=pos;++i)
	{
		int pos=0;
		for(auto it:v[i])
		{
			V[it.x].push_back(it);
			V[it.y].push_back(it);
			if(!used[it.x])
			{
				used[it.x]=1;
				t[++pos]=it.x;
			}
			if(!used[it.y])
			{
				used[it.y]=1;
				t[++pos]=it.y;
			}
		}
		for(auto it:v[i])
		{
			used[it.x]=0;
			used[it.y]=0;
		}
		for(int *i=t+1,*end=t+pos+1;i!=end;++i)
		{
			bool first=true;
			for(auto it:V[*i])
			{
				if(!first) add(it.id,node_cnt);
				++node_cnt;
				if(!first) add(node_cnt,node_cnt-1);
				add(node_cnt,it.id+m);
				first=false;
			}
			std::reverse(V[*i].begin(),V[*i].end());
			first=true;
			for(auto it:V[*i])
			{
				if(!first) add(it.id,node_cnt);
				++node_cnt;
				if(!first) add(node_cnt,node_cnt-1);
				add(node_cnt,it.id+m);
				first=false;
			}
			V[*i].clear();
		}
	}
	for(int i=1;i<=m;++i)
	{
		if(E[i][3]<=x)
		{
			V[E[i][0]].push_back((node){E[i][0],E[i][1],E[i][3],i});
			V[E[i][1]].push_back((node){E[i][0],E[i][1],E[i][3],i});
		}
		else
		{
			add(i+m,i);
		}
	}
	for(int i=1;i<=n;++i)
	{
		bool first=true;
		for(auto it:V[i])
		{
			if(!first) add(it.id+m,node_cnt);
			++node_cnt;
			if(!first) add(node_cnt,node_cnt-1);
			add(node_cnt,it.id);
			first=false;
		}
		std::reverse(V[i].begin(),V[i].end());
		first=true;
		for(auto it:V[i])
		{
			if(!first) add(it.id+m,node_cnt);
			++node_cnt;
			if(!first) add(node_cnt,node_cnt-1);
			add(node_cnt,it.id);
			first=false;
		}
		V[i].clear();
	}
	for(int i=1;i<=node_cnt;++i)
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
			return false;
		}
	}
	return true;
}
int main()
{
	read(n,m);
	for(int i=1;i<=m;++i)
	{
		read(E[i][0],E[i][1],E[i][2],E[i][3]);
		t[++pos]=E[i][2];
	}
	std::sort(t+1,t+pos+1);
	pos=std::unique(t+1,t+pos+1)-t-1;
	for(int i=1;i<=m;++i)
	{
		v[std::lower_bound(t+1,t+pos+1,E[i][2])-t].push_back((node){E[i][0],E[i][1],E[i][3],i});
	}
	int l=0,r=1000000000;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	if(check(l))
	{
		printf("Yes\n");
		std::vector<int> qwq;
		for(int i=1;i<=m;++i)
		{
			if(bel[i]>bel[i+m])
			{
				qwq.push_back(i);
			}
		}
		printf("%d %d\n",l,(int)qwq.size());
		for(auto it:qwq) printf("%d ",it);
		printf("\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}