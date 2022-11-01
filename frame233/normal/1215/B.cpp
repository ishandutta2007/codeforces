#pragma GCC optimize(2)
 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>
#include<functional>
#include<bitset>
 
#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
 
using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::queue;
using std::bitset;
using std::sort;
using std::unique;
using std::endl;
using std::cerr;
using std::priority_queue;
using std::random_shuffle;
	
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
 
const int N=200005;
int a[N],sum[N];
void solve()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		if(a[i]<0) a[i]=1;
		else a[i]=0;
		sum[i]=sum[i-1]+a[i];
	}
	ll ans1=0,ans2=0;
	int cnt1=0,cnt2=1;
	for(int i=1;i<=n;++i)
	{
		if(sum[i]&1)
		{
			ans1+=cnt2;
			ans2+=cnt1;
			++cnt1;
		}
		else
		{
			ans1+=cnt1;
			ans2+=cnt2;
			++cnt2;
		}
	}
	printf("%lld %lld\n",ans1,ans2);
}
int main()
{
	solve();
    return 0;
}