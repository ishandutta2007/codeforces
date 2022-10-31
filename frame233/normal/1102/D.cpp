// luogu-judger-enable-o2
// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>

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

const int N=300005;
char s[N];
int main()
{
	int n;
	read(n);
	read_str(s+1);
	int cnt=n/3;
	int cnt0=0,cnt1=0,cnt2=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='0') ++cnt0;
		else if(s[i]=='1') ++cnt1;
		else ++cnt2;
	}
	if(cnt0<cnt)
	{
		for(int i=1;i<=n&&cnt0<cnt;++i)
		{
			if(s[i]=='2'&&cnt2>cnt)
			{
				++cnt0,--cnt2;
				s[i]='0';
			}
		}
		for(int i=1;i<=n&&cnt0<cnt;++i)
		{
			if(s[i]=='1'&&cnt1>cnt)
			{
				++cnt0,--cnt1;
				s[i]='0';
			}
		}
	}
	else if(cnt0>cnt)
	{
		for(int i=n;i>=1&&cnt0>cnt;--i)
		{
			if(s[i]=='0'&&cnt2<cnt)
			{
				++cnt2,--cnt0;
				s[i]='2';
			}
			else if(s[i]=='0'&&cnt1<cnt)
			{
				++cnt1,--cnt0;
				s[i]='1';
			}
		}
	}
	if(cnt1<cnt)
	{
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='2'&&cnt2>cnt)
			{
				++cnt1,--cnt2;
				s[i]='1';
			}
		}
	}
	else if(cnt1>cnt)
	{
		for(int i=n;i>=1;--i)
		{
			if(s[i]=='1'&&cnt2<cnt)
			{
				++cnt2,--cnt1;
				s[i]='2';
			}
		}
	}
	printf("%s\n",s+1);
    return 0;
}