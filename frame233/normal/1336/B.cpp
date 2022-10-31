// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())

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
void MAIN()
{
	int na,nb,nc;
	read(na,nb,nc);
	std::vector<int> a,b,c;
	a.resize(na);
	b.resize(nb);
	c.resize(nc);
	for(int i=0;i<na;++i) read(a[i]);
	for(int i=0;i<nb;++i) read(b[i]);
	for(int i=0;i<nc;++i) read(c[i]);
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
	std::sort(c.begin(), c.end());
	ll ans=5e18;
	std::function<ll(ll)> f=[](ll a)->ll{return a*a;};
	auto solve=[&](const std::vector<int> &a,const std::vector<int> &b,const std::vector<int> &c)
	{
		for(auto it:a)
		{
			auto x=std::upper_bound(b.begin(), b.end(),it);
			if(x!=b.begin()) --x;
			auto y=std::lower_bound(c.begin(), c.end(),it);
			if(y==c.end()) --y;
			chmin(ans,f(*x-*y)+f(*x-it)+f(*y-it));
		}
	};
	solve(a,b,c);
	solve(a,c,b);
	solve(b,a,c);
	solve(b,c,a);
	solve(c,a,b);
	solve(c,b,a);
	printf("%lld\n",ans);
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}