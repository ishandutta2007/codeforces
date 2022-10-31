// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;

Finline uint rnd()
{
	static uint seed=0x05ad13b4;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());
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
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=100005;
ll get()
{
	static char s[105];
	int n=read_str(s);
	ll x=0;
	for(int i=0;i<n;++i) x=(x<<1)+(s[i]-48);
	return x;
}
void MAIN()
{
	int n,m;
	read(n,m);
	ll k=(1LL<<m)-n;
	ll tar=(k+1)>>1;
	std::vector<ll> v;
	for(int i=0;i<n;++i) v.pb(get());
	std::sort(v.begin(),v.end());
	ll l=0,r=(1LL<<m)-1;
	auto count=[&](ll mid)->ll{return (mid+1-(std::upper_bound(v.begin(),v.end(),mid)-v.begin()));};
	while(l<r)
	{
		ll mid=(l+r+1)>>1;
		if(count(mid)<tar) l=mid;
		else r=mid-1;
	}
	if(count(l)<tar) ++l;
	for(int i=m-1;i>=0;--i) printf("%lld",(l>>i)&1);
	printf("\n");
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}