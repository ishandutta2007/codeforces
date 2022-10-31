// luogu-judger-enable-o2
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
 
const int N=105;
struct node{
	int a,b;
	Finline bool operator < (const node &o)const
	{
		return a<o.a;
	}
}a[N],b[N];
int f[N][N];
Finline bool cmp(const node &a,const node &b)
{
	return a.a+a.b>b.a+b.b;
}
int main()
{
	int n,r;
	read(n,r);
	int tmp=n;
	for(int i=1;i<=n;++i)
	{
		read(a[i].a,a[i].b);
	}
	int ans=0;
	while(1)
	{
		int pos=0;
		std::sort(a+1,a+n+1);
		int Pos=std::upper_bound(a+1,a+n+1,(node){r,0})-a-1;
		bool flag=0;
		for(int i=1;i<=Pos;++i)
		{
			if(a[i].b>=0)
			{
				r+=a[i].b;
				++ans;
				flag=1;
			}
			else
			{
				b[++pos]=a[i];
			}
		}
		if(!flag) break;
		for(int i=Pos+1;i<=n;++i)
		{
			b[++pos]=a[i];
		}
		n=pos;
		for(int i=1;i<=n;++i)
		{
			a[i]=b[i];
		}
	}
	int pos=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i].a<=r)
		{
			b[++pos]=a[i];
		}
	}
	n=pos;
	for(int i=1;i<=n;++i)
	{
		a[i]=b[i];
	}
	std::sort(a+1,a+n+1,cmp);
	memset(f,-63,sizeof(f));
	f[0][0]=r;
	for(int i=1;i<=n;++i)
	{
		f[i][0]=r;
		for(int j=1;j<=n;++j)
		{
			f[i][j]=f[i-1][j];
			if(f[i-1][j-1]>=a[i].a&&f[i-1][j-1]+a[i].b>=0)
			{
				chmax(f[i][j],f[i-1][j-1]+a[i].b);
			}
		}
	}
	int res=0;
	for(int i=n;i>=1;--i)
	{
		if(f[n][i]>=0)
		{
			chmax(res,i);
		}
	}
	if(ans+res==tmp)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
    return 0;
}