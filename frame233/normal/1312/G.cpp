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

const int N=1000005;
int ch[N][26];
bool mark[N];
int low[N],dfn[N];
int id;
void dfs1(int x)
{
	low[x]=id;
	if(mark[x]) dfn[x]=++id;
	for(int i=0;i<26;++i)
	{
		if(ch[x][i])
		{
			dfs1(ch[x][i]);
		}
	}
}
int dp[N];
void dfs2(int x,int val)
{
	if(mark[x]) chmin(dp[x],val+dfn[x]);
	chmin(val,dp[x]-low[x]);
	for(int i=0;i<26;++i)
	{
		if(ch[x][i])
		{
			dp[ch[x][i]]=dp[x]+1;
			dfs2(ch[x][i],val);
		}
	}
}
int a[N];
int main()
{
	int n;
	read(n);
	int x;
	char c;
	for(int i=1;i<=n;++i)
	{
		read(x);
		c=getchar();
		while(c<97||c>122) c=getchar();
		ch[x][c-97]=i;
	}
	int k;
	read(k);
	for(int i=1;i<=k;++i)
	{
		read(a[i]);
		mark[a[i]]=true;
	}
	dfs1(0);
	dfs2(0,0);
	for(int i=1;i<=k;++i)
	{
		printf("%d ",dp[a[i]]);
	}
	printf("\n");
	return 0;
}