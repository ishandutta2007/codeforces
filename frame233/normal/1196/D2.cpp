// luogu-judger-enable-o2
// Author -- Frame
 
#pragma GCC optimize(2)
 
#include<cstdio>
#include<cstring>
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
const ll INF=0x7ffffffffffffff;
const double eps=1e-8;
 
uint seed=19260817;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}
Finline bool _cmp(const double &a,const double &b){return abs(a-b)<=eps;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool ismax(_Tp &a,const _Tp &b){return a>b?1:a=b,0;}
template <typename _Tp>Finline bool ismin(_Tp &a,const _Tp &b){return a<b?1:a=b,0;}
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
	while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}
 
const int N=200005;
char s[N];
int n,k;
char t[N];
int f[N][3];
Finline int id(char ch)
{
	if(ch=='R') return 0;
	else if(ch=='G') return 1;
	return 2;
}
 
void MAIN()
{
	read(n,k);
	read_str(s+1);
	for(int i=1;i<=n;++i)
	{
		f[i][0]=f[i][1]=f[i][2]=1;
		f[i][id(s[i])]=0;
	}
	int sum1=0,sum2=0,sum3=0;
	for(int i=1;i<=k;++i)
	{
		if(i%3==1)
		{
			sum1+=f[i][0];
			sum2+=f[i][1];
			sum3+=f[i][2];
		}
		else if(i%3==2)
		{
			sum1+=f[i][1];
			sum2+=f[i][2];
			sum3+=f[i][0];
		}
		else
		{
			sum1+=f[i][2];
			sum2+=f[i][0];
			sum3+=f[i][1];
		}
	}
	int ans=inf;
	for(int i=1;i<=n-k+1;++i)
	{
		chmin(ans,min(sum1,min(sum2,sum3)));
		sum1-=f[i][0];
		sum2-=f[i][1];
		sum3-=f[i][2];
		int tmp=sum3;
		sum3=sum2;
		sum2=sum1;
		sum1=tmp;
		if(k%3==1)
		{
			sum1+=f[i+k][0];
			sum2+=f[i+k][1];
			sum3+=f[i+k][2];
		}
		else if(k%3==2)
		{
			sum1+=f[i+k][1];
			sum2+=f[i+k][2];
			sum3+=f[i+k][0];
		}
		else
		{
			sum1+=f[i+k][2];
			sum2+=f[i+k][0];
			sum3+=f[i+k][1];
		}
	}
	printf("%d\n",ans);
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}