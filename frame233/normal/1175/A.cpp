// Author -- Frame

#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<iostream>
#include<vector>
#include<bitset>
#include<queue>
#include<set>
#include<map>

#define pb push_back
#define Finline __inline__ __attribute__ ((always_inline))
#define err(x) cerr<<"% "<<x<<endl
#define DEBUG cerr<<"Running on Line "<<__LINE__<<" in Function "<<__FUNCTION__<<endl

using std::vector;
using std::bitset;
using std::set;
using std::map;
using std::priority_queue;
using std::pair;
using std::sort;
using std::unique;
using std::lower_bound;
using std::upper_bound;
using std::cerr;
using std::string;
using std::endl;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7ffffffffffffff;

void file()
{
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp& t,Args&... args)
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

const int N=100005;

int main()
{
	int _;
	read(_);
	while(_--)
	{
		ll n,k;
		read(n,k);
		ll ans=0;
		while(n>=k)
		{
			ans+=n%k+1;
			n=(n-n%k)/k;
		}
		printf("%lld\n",ans+n);
	}
	return 0;
}