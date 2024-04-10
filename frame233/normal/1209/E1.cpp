// Author -- Frame
 
#pragma GCC optimize(2)
 
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
const double eps=1e-8;
 
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
 
const int N=1005;
int a[N][N];
struct node{
	int val,x,y;
	Finline bool operator < (const node &o)const
	{
		return val>o.val;
	}
}b[N<<10];
int pos,n,m;
bool used[N];
int ans;
void dfs(int dep,int id)
{
	if(dep==n+1)
	{
		int res=0;
		for(int i=1;i<=n;++i)
		{
			int maxx=0;
			for(int j=1;j<=m;++j)
			{
				chmax(maxx,a[i][j]);
			}
			res+=maxx;
		}
		chmax(ans,res);
		return;
	}
	int cur=id;
	while(cur<m&&used[b[cur].y]) ++cur;
	if(cur==m+1)
	{
		dfs(n+1,0);
		return;
	}
	used[b[cur].y]=1;
	for(int i=1;i<=n;++i)
	{
		dfs(dep+1,cur+1);
		int tmp=a[n][b[cur].y];
		for(int j=n;j>=2;--j)
		{
			a[j][b[cur].y]=a[j-1][b[cur].y];
		}
		a[1][b[cur].y]=tmp;
	}
	used[b[cur].y]=0;
}
void MAIN()
{
	memset(used,0,sizeof(used));
	pos=0,ans=0;
	read(n,m);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			read(a[i][j]);
			b[++pos]=(node){a[i][j],i,j};
		}
	}
	std::sort(b+1,b+pos+1);
	dfs(1,1);
	printf("%d\n",ans);
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
    return 0;
}