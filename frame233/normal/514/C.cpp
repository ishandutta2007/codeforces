// luogu-judger-enable-o2
// Author -- Frame
 
#pragma GCC optimize(2)
 
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<unordered_set>
 
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
 
const int N=300005;
const int mod1=1000000007,mod2=1000000009;
const int base=233333;
std::unordered_set<ll> S[N<<1];
char s[N<<1];
ll hash(char *s,int len)
{
	ll ans1=0,ans2=0;
	for(int i=1;i<=len;++i)
	{
		ans1=(ans1*base+s[i])%mod1;
		ans2=(ans2*base+s[i])%mod2;
	}
	return (ans1<<32ll)+ans2;
}
int main()
{
	int n,m;
	read(n,m);
	for(int i=1;i<=n;++i)
	{
		int len=read_str(s+1);
		S[len].insert(hash(s,len));
	}
	while(m--)
	{
		int len=read_str(s+1);
		ll tmp=hash(s,len);
		ll val1=tmp>>32ll;
		ll val2=tmp&0xffffffff;
		ll mul1=1,mul2=1;
		bool flag=0;
		for(int i=len;i>=1&&!flag;--i)
		{
			for(int j=97;j<=99;++j)
			{
				if(j!=s[i])
				{
					if(S[len].find((((((j-s[i])*mul1+val1)%mod1+mod1)%mod1)<<32ll)+((((j-s[i])*mul2+val2)%mod2+mod2)%mod2))!=S[len].end())
					{
						flag=1;
						break;
					}
				}
			}
			mul1=mul1*base%mod1;
			mul2=mul2*base%mod2;
		}
		if(flag)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}