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

const int N=200005;
char s[N];
int main()
{
	int n;
	read(n);
	read_str(s+1);
	int hf=n>>1;
	int cnt1=0,cnt2=0;
	int sum1=0,sum2=0;
	for(int i=1;i<=hf;++i)
	{
		if(s[i]!='?')
		{
			sum1+=s[i]-48;
		}
		else
		{
			++cnt1;
		}
		if(s[i+hf]!='?')
		{
			sum2+=s[i+hf]-48;
		}
		else
		{
			++cnt2;
		}
	}
	if(sum1==sum2)
	{
		if(cnt1==cnt2) printf("Bicarp\n");
		else printf("Monocarp\n");
		exit(0);
	}
	if(sum1>=sum2)
	{
		if(cnt1>=cnt2)
		{
			printf("Monocarp\n");
			exit(0);
		}
		else
		{
			if((cnt2-cnt1)/2*9==sum1-sum2)
			{
				printf("Bicarp\n");
				exit(0);
			}
		}
	}
	else
	{
		if(cnt1>=cnt2)
		{
			if((cnt1-cnt2)/2*9==sum2-sum1)
			{
				printf("Bicarp\n");
				exit(0);
			}
		}
		else
		{
			printf("Monocarp\n");
			exit(0);
		}
	}
	printf("Monocarp\n");
    return 0;
}