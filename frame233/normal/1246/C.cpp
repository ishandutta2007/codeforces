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

const int N=2005;
const int mod=1000000007;
char s[N][N];
int dp[N][N];
int cnt1[N][N],cnt2[N][N];
Finline void _add(int &A,const int &B){(A+=B)>=mod&&(A-=mod);}
Finline void _sub(int &A,const int &B){(A-=B)<0&&(A+=mod);}
struct BIT{
	int c[N];
	Finline void add(int x,const int &C)
	{
		for(;x<=2000;x+=lowbit(x))
		{
			_add(c[x],C);
		}
	}
	Finline void sub(int x,const int &C)
	{
		for(;x<=2000;x+=lowbit(x))
		{
			_sub(c[x],C);
		}
	}
	Finline int sum(int x)
	{
		int ans=0;
		for(;x;x-=lowbit(x))
		{
			_add(ans,c[x]);
		}
		return ans;
	}
}tr1[N],tr2[N];
Finline void Upd1(int x,int l,int r,const int &C)
{
	tr1[x].add(l,C);
	tr1[x].sub(r+1,C);
}
Finline void Upd2(int x,int l,int r,const int &C)
{
	tr2[x].add(l,C);
	tr2[x].sub(r+1,C);
}
int main()
{
	int n,m;
	read(n,m);
	if(n==1&&m==1)
	{
		printf("1\n");
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		read_str(s[i]+1);
		int cnt=0;
		for(int j=1;j<=m;++j)
		{
			cnt+=s[i][j]=='R';
			cnt1[i][j]=cnt;
		}
	}
	for(int i=1;i<=m;++i)
	{
		int cnt=0;
		for(int j=2;j<=n;++j)
		{
			cnt+=s[j][i]=='R';
			cnt2[j][i]=cnt;
		}
	}
	Upd1(1,1,1,1);
	Upd2(1,1,1,1);
	int a=0,b=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			a=tr1[i].sum(j);
			b=tr2[j].sum(i);
			int sum=cnt2[n][j]-cnt2[i][j];
			Upd2(j,i+1,n-sum,a);
			sum=cnt1[i][m]-cnt1[i][j];
			Upd1(i,j+1,m-sum,b);
		}
	}
	_add(a,b);
	printf("%d\n",a);
    return 0;
}