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
 
const int N=100005;
ll f[33][2][2];
int a[33],b[33],len1,len2;
ll dfs(int pos,bool limit1,bool limit2)
{
	if(!pos) return 1;
	if(~f[pos][limit1][limit2]) return f[pos][limit1][limit2];
	ll &x=f[pos][limit1][limit2];
	x=0;
	int maxx1=limit1?a[pos]:1;
	int maxx2=limit2?b[pos]:1;
	for(int i=0;i<=maxx1;++i)
	{
		for(int j=0;j<=maxx2;++j)
		{
			if(i!=1||j!=1)
			{
				x+=dfs(pos-1,limit1&&i==maxx1,limit2&&j==maxx2);
			}
		}
	}
	return x;
}
ll solve(int x,int y)
{
	if(x<0||y<0) return 0;
	memset(f,255,sizeof(f));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	len1=0,len2=0;
	while(x)
	{
		a[++len1]=x&1;
		x>>=1;
	}
	while(y)
	{
		b[++len2]=y&1;
		y>>=1;
	}
	return dfs(max(len1,len2),1,1);
}
void MAIN()
{
	int l,r;
	read(l,r);
	printf("%lld\n",solve(r,r)-solve(l-1,r)-solve(r,l-1)+solve(l-1,l-1));
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
    return 0;
}