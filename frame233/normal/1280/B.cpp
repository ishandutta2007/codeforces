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
 
const int N=65;
char s[N][N];
void MAIN()
{
	int n,m;
	read(n,m);
	char ch;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			ch=getchar();
			while(ch!='A'&&ch!='P') ch=getchar();
			s[i][j]=ch;
		}
	}
	bool flag=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(s[i][j]=='A')
			{
				flag=1;
			}
		}
	}
	if(!flag)
	{
		printf("MORTAL\n");
		return;
	}
	flag=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			flag&=s[i][j]=='A';
		}
	}
	if(flag)
	{
		printf("0\n");
		return;
	}
	flag=1;
	for(int i=1;i<=m;++i)
	{
		flag&=s[1][i];
	}
	if(flag)
	{
		printf("1\n");
		return;
	}
	flag=1;
	for(int i=1;i<=m;++i)
	{
		flag&=s[n][i];
	}
	if(flag)
	{
		printf("1\n");
		return;
	}
	flag=1;
	for(int i=1;i<=n;++i)
	{
		flag&=s[i][1];
	}
	if(flag)
	{
		printf("1\n");
		return;
	}
	flag=1;
	for(int i=1;i<=n;++i)
	{
		flag&=s[i][m];
	}
	if(flag)
	{
		printf("1\n");
		return;
	}
	if(s[1][1]=='A'||s[n][m]=='A'||s[1][m]=='A'||s[n][1]=='A')
	{
		printf("2\n");
		return;
	}
	for(int i=1;i<=n;++i)
	{
		flag=1;
		for(int j=1;j<=m;++j)
		{
			flag&=s[i][j]=='A';
		}
		if(flag)
		{
			printf("2\n");
			return;
		}
	}
	for(int i=1;i<=m;++i)
	{
		flag=1;
		for(int j=1;j<=n;++j)
		{
			flag&=s[j][i]=='A';
		}
		if(flag)
		{
			printf("2\n");
			return;
		}
	}
	flag=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i][1]=='A'||s[i][m]=='A')
		{
			flag=1;
		}
	}
	for(int i=1;i<=m;++i)
	{
		if(s[1][i]=='A'||s[n][i]=='A')
		{
			flag=1;
		}
	}
	if(flag)
	{
		printf("3\n");
		return;
	}
	printf("4\n");
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
    return 0;
}
//