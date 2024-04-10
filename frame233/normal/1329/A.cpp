// Author -- Frame

#include<cstdio>
#include<cstring>
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

const int N=100005;
int a[N];
ll suf[N];
int ans[N];
int main()
{
	int n,m;
	read(n,m);
	int cur=0;
	for(int i=1;i<=m;++i) read(a[i]);
	for(int i=m;i>=1;--i) suf[i]=suf[i+1]+a[i];
	int maxx=1;
	for(int i=1;i<=m;++i)
	{
		if(suf[i]>=n-cur)
		{
			++cur;
			ans[i]=cur;
			if(cur>n-a[i]+1)
			{
				printf("-1\n");
				return 0;
			}
		}
		else
		{
			cur+=n-cur-suf[i]+1;
			if(cur>maxx)
			{
				printf("-1\n");
				return 0;
			}
			if(cur>n-a[i]+1)
			{
				printf("-1\n");
				return 0;
			}
			ans[i]=cur;
		}
		chmax(maxx,cur+a[i]);
	}
	if(cur+a[m]-1!=n)
	{
		printf("-1\n");
	}
	else
	{
		for(int i=1;i<=m;++i)
		{
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
	return 0;
}