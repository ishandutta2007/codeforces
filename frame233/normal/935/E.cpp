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
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp& x)
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

const int N=10005;
char s[N];
int node_cnt;
int st[N];
int ls[N],rs[N];
int a[N];
int build()
{
	int n=read_str(s+1);
	int top=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='(')
		{
			st[++top]=-1;
		}
		else if(s[i]=='?')
		{
			continue;
		}
		else if(s[i]==')')
		{
			int t1=st[top],t2=st[top-1];
			top-=3;
			int cur=++node_cnt;
			ls[cur]=t2,rs[cur]=t1;
			st[++top]=cur;
		}
		else
		{
			st[++top]=++node_cnt;
			a[node_cnt]=s[i]-48;
		}
	}
	if(top!=1) exit(233);
	return st[top];
}
int A,B;
int f[N][105],g[N][105];
int dfs1(int x)
{
	if(!ls[x])
	{
		f[x][0]=a[x];
		g[x][0]=a[x];
		return 0;
	}
	int siz=1;
	int siz1,siz2;
	siz+=siz1=dfs1(ls[x]);
	siz+=siz2=dfs1(rs[x]);
	for(int i=0;i<=A&&i<=siz;++i)
	{
		for(int j=0;j<=i&&j<=siz1;++j)
		{
			if(i-j<=siz2)
			{
				chmax(f[x][i],f[ls[x]][j]-g[rs[x]][i-j]);
				chmin(g[x][i],g[ls[x]][j]-f[rs[x]][i-j]);
			}
		}
		for(int j=0;j<i&&j<=siz1;++j)
		{
			if(i-j-1<=siz2)
			{
				chmax(f[x][i],f[ls[x]][j]+f[rs[x]][i-j-1]);
				chmin(g[x][i],g[ls[x]][j]+g[rs[x]][i-j-1]);
			}
		}
	}
	return siz;
}
int dfs2(int x)
{
	if(!ls[x])
	{
		f[x][0]=a[x];
		g[x][0]=a[x];
		return 0;
	}
	int siz=1;
	int siz1,siz2;
	siz+=siz1=dfs2(ls[x]);
	siz+=siz2=dfs2(rs[x]);
	for(int i=0;i<=B;++i)
	{
		for(int j=0;j<=i&&j<=siz1;++j)
		{
			if(i-j<=siz2)
			{
				chmax(f[x][i],f[ls[x]][j]+f[rs[x]][i-j]);
				chmin(g[x][i],g[ls[x]][j]+g[rs[x]][i-j]);
			}
		}
		for(int j=0;j<i&&j<=siz1;++j)
		{
			if(i-j-1<=siz2)
			{
				chmax(f[x][i],f[ls[x]][j]-g[rs[x]][i-j-1]);
				chmin(g[x][i],g[ls[x]][j]-f[rs[x]][i-j-1]);
			}
		}
	}
	return siz;
}
int main()
{
	memset(g,63,sizeof(g));
	memset(f,-63,sizeof(f));
	int root=build();
	read(A,B);
	if(A<=100)
	{
		dfs1(root);
		printf("%d\n",f[root][A]);
	}
	else
	{
		dfs2(root);
		printf("%d\n",f[root][B]);
	}
    return 0;
}
/*
((4?3)?(((2?(4?((4?((2?(3?(7?3)))?(((((3?(6?2))?3)?(((((6?6)?(1?5))?((8?8)?1))?(5?((7?((6?((((3?8)?8)?(8?5))?7))?8))?((8?(2?8))?3))))?6))?(8?(7?5)))?8)))?((((7?(4?3))?4)?5)?((1?(((2?2)?((((4?((7?6)?(1?4)))?(8?(1?(((1?3)?(((2?2)?(3?(8?(9?((2?(4?6))?(7?8))))))?(9?(7?9))))?(7?3)))))?((2?((2?((8?6)?1))?(3?1)))?(7?1)))?5))?((((6?(9?(((5?4)?7)?((5?8)?8))))?5)?7)?(2?2))))?4)))))?2)?(7?(4?((6?6)?6)))))
50 49
*/