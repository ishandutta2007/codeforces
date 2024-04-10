// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>

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

const int N=405;
struct edge{
	int v,nxt;
}c[N*N<<2];
int front[N],edge_cnt;
Finline void add(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]},front[u]=edge_cnt;
}
char s[N],t[N];
char ans[N];
int E[N*N][2];
char C[N*N][2];
int n,m,l;
int _id[26];
bool tag1,tag2;
namespace twosat
{
int dfn[N],low[N],id;
int st[N],top;
int bel[N],col;
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
bool check(int pos)
{
	edge_cnt=0;
	id=col=top=0;
	memset(front,0,(n+2)<<3);
	memset(dfn,0,(n+2)<<3);
	memset(bel,0,(n+2)<<3);
	if(!tag1)
	{
		for(int i=1;i<=n;++i)
		{
			add(i,i+n);
		}
	}
	if(!tag2)
	{
		for(int i=1;i<=n;++i)
		{
			add(i+n,i);
		}
	}
	char ch1,ch2;
	int x,y;
	for(int i=1;i<=pos;++i)
	{
		if(_id[t[i]-97]==0)
		{
			add(i+n,i);
		}
		else
		{
			add(i,i+n);
		}
	}
	++pos;
	if(pos<=n)
	{
		bool flag1=false,flag2=false;
		for(int i=t[pos]-97+1;i<l;++i)
		{
			if(_id[i]==0) flag1=true;
			if(_id[i]==1) flag2=true;
		}
		if(!flag1&&!flag2) return false;
		if(!flag1) add(pos,pos+n);
		else if(!flag2) add(pos+n,pos);
	}
	for(int i=1;i<=m;++i)
	{
		x=E[i][0],y=E[i][1];
		ch1=C[i][0],ch2=C[i][1];
		if(ch1=='V'&&ch2=='V')
		{
			add(x,y);
			add(y+n,x+n);
		}
		else if(ch1=='V'&&ch2=='C')
		{
			add(x,y+n);
			add(y,x+n);
		}
		else if(ch1=='C'&&ch2=='V')
		{
			add(x+n,y);
			add(y+n,x);
		}
		else
		{
			add(x+n,y+n);
			add(y,x);
		}
	}
	for(int i=1;i<=n<<1;++i)
	{
		if(!dfn[i])
		{
			tarjan(i);
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(bel[i]==bel[i+n])
		{
			return false;
		}
	}
	return true;
}
}
bool vis[N];
Finline int ops(int x)
{
	return x>n?x-n:x+n;
}
std::vector<int> v;
bool dfs(int x)
{
	if(vis[x]) return true;
	if(vis[ops(x)]) return false;
	vis[x]=true;
	v.push_back(x);
	for(int i=front[x];i;i=c[i].nxt)
	{
		if(dfs(c[i].v)==false)
		{
			return false;
		}
	}
	return true;
}
void mark(int x)
{
	if(vis[x]) return;
	vis[x]=true;
	for(int i=front[x];i;i=c[i].nxt)
	{
		mark(c[i].v);
	}
}
void print(int pos)
{
	memcpy(ans,t,pos+1);
	for(int i=1;i<=pos;++i)
	{
		mark(i+_id[t[i]-97]*n);
	}
	for(int i=pos+1;i<=n;++i)
	{
		v.clear();
		bool flag1=dfs(i);
		for(auto it:v) vis[it]=false;
		v.clear();
		bool flag2=dfs(i+n);
		for(auto it:v) vis[it]=false;
		assert(flag1||flag2);
		for(int j=i==pos+1?(t[i]-97+1):0;j<l;++j)
		{
			if((s[j]=='V'&&flag1)||(s[j]=='C'&&flag2))
			{
				ans[i]=j+97;
				mark(i+_id[j]*n);
				break;
			}
		}
	}
	printf("%s\n",ans+1);
}
int main()
{
	l=read_str(s);
	for(int i=0;i<l;++i)
	{
		_id[i]=s[i]=='V'?0:1;
		if(_id[i]==0) tag1=true;
		else tag2=true;
	}
	std::vector<int> v1,v2;
	for(int i=0;i<l;++i)
	{
		if(s[i]=='V')
		{
			v1.push_back(i);
		}
		else
		{
			v2.push_back(i);
		}
	}
	read(n,m);
	char ch1,ch2;
	int x,y;
	for(int i=1;i<=m;++i)
	{
		read(x);
		ch1=getchar();
		while(ch1!='V'&&ch1!='C') ch1=getchar();
		read(y);
		ch2=getchar();
		while(ch2!='V'&&ch2!='C') ch2=getchar();
		E[i][0]=x,E[i][1]=y;
		C[i][0]=ch1,C[i][1]=ch2;
	}
	read_str(t+1);
	for(int i=n;i>=0;--i)
	{
		if(twosat::check(i))
		{
			print(i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}