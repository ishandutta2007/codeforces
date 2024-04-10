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
template <typename _Tp>Finline bool _cmp(const double &a,const double &b){return abs(a-b)<=eps;}
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
char s[N][N];
bool l[N][N],r[N][N];
bool u[N][N],d[N][N];
int a[N][N],b[N][N];
bool used1[N],used2[N];
int main()
{
	
	int n,k;
	read(n,k);
	if(n==k)
	{
		printf("%d",n<<1);
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		read_str(s[i]+1);
		l[i][0]=1;
		for(int j=1;j<=n;++j)
		{
			if(s[i][j]=='W')
			{
				l[i][j]=l[i][j-1];
			}
		}
		r[i][n+1]=1;
		for(int j=n;j>=1;--j)
		{
			if(s[i][j]=='W')
			{
				r[i][j]=r[i][j+1];
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		u[0][i]=1;
		for(int j=1;j<=n;++j)
		{
			if(s[j][i]=='W')
			{
				u[j][i]=u[j-1][i];
			}
		}
		d[n+1][i]=1;
		for(int j=n;j>=1;--j)
		{
			if(s[j][i]=='W')
			{
				d[j][i]=d[j+1][i];
			}
		}
	}
	
	int cnt=0;
	for(int i=1;i<=n;++i)
	{
		bool flag=1;
		for(int j=1;j<=n;++j)
		{
			flag&=s[i][j]=='W';
		}
		if(flag)
		{
			++cnt;
			used1[i]=1;
		}
	}
	for(int i=1;i<=n;++i)
	{
		bool flag=1;
		for(int j=1;j<=n;++j)
		{
			flag&=s[j][i]=='W';
		}
		if(flag)
		{
			++cnt;
			used2[i]=1;
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(used1[i]) continue;
		for(int j=1;j<=n-k+1;++j)
		{
			if(l[i][j-1]&&r[i][j+k])
			{
				++a[max(1,i-k+1)][j];
				--a[i+1][j];
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(used2[i]) continue;
		for(int j=1;j<=n-k+1;++j)
		{
			if(u[j-1][i]&&d[j+k][i])
			{
				++b[j][max(1,i-k+1)];
				--b[j][i+1];
			}
		}
	}
	
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			a[i][j]+=a[i-1][j];
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			b[i][j]+=b[i][j-1];
		}
	}
	int ans=0;
	for(int i=1;i<=n-k+1;++i)
	{
		for(int j=1;j<=n-k+1;++j)
		{
			chmax(ans,a[i][j]+b[i][j]);
		}
	}
	printf("%d\n",ans+cnt);
    return 0;
}