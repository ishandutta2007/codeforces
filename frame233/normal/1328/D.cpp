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

const int N=200005;
int a[N];
int n;
bool dp[N][5];
int opt[N][5];
bool check(int x)
{
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<5;++j)
		{
			dp[i][j]=0;
		}
	}
	dp[1][0]=true;
	for(int i=2;i<=n;++i)
	{
		for(int j=0;j<x;++j)
		{
			for(int k=0;k<x;++k)
			{
				if(a[i]!=a[i-1]&&j==k) continue;
				if(dp[i-1][k])
				{
					opt[i][j]=k;
					dp[i][j]|=dp[i-1][k];
				}
			}
		}
	}
	for(int i=0;i<x;++i)
	{
		if(a[1]!=a[n]&&i==0) continue;
		if(dp[n][i]) return true;
	}
	return false;
}
void print(int n,int x)
{	
	if(!n) return;
	print(n-1,opt[n][x]);
	printf("%d ",x+1);
}
void MAIN()
{
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	for(int ans=1;;++ans)
	{
		if(check(ans))
		{
			printf("%d\n",ans);
			int pos=0;
			for(int i=0;i<ans;++i)
			{
				if(a[1]!=a[n]&&i==0) continue;
				if(dp[n][i]) pos=i;
			}
			print(n,pos);
			printf("\n");
			return;
		}
	}
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}