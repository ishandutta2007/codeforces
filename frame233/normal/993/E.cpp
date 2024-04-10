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
	static uint seed=416;
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

const int N=(1<<19)+5;

namespace poly
{
const ll mod=206158430209LL;
const int G=22;

template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
Finline ll mul(ll a,ll b)
{
	return (__int128)a*(__int128)b%mod;
}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1) res=mul(res,a);a=mul(a,a),b>>=1;}return res;}

const int BIT_SIZ=11;
const int MAX_NUM=(1<<BIT_SIZ)-1;
int Log2[1<<BIT_SIZ];

Finline int count(int x){return (x>>BIT_SIZ)?Log2[x>>BIT_SIZ]+BIT_SIZ:Log2[x&MAX_NUM];}
 // return floor(log2[x])
 
Finline int _count(int x){int tmp=count(x);return (1<<tmp==x)?tmp:tmp+1;}
 // return ceil(log2[x])

ll Omgs[N];
int poly_rev[N];
int _lim,_len;

void setup(int max_len) // should be called only once
{
	for(int i=2;i<1<<BIT_SIZ;++i) Log2[i]=Log2[i>>1]+1;
	int limit=1<<_count(max_len);
	_lim=limit;
	_len=count(limit);
	for(int i=1;i<limit;++i) poly_rev[i]=(poly_rev[i>>1]>>1)|((i&1)<<(_len-1));
	ll omg=ksm(G,(mod-1)>>_len);
	Omgs[limit>>1]=1;
	for(int i=(limit>>1)|1;i<limit;++i) Omgs[i]=mul(Omgs[i-1],omg);
	for(int i=(limit>>1)-1;i;--i) Omgs[i]=Omgs[i<<1];
}

Finline ll _sub(ll a,ll b)
{
	((a-=b)<0)&&(a+=mod);
	return a;
}
void ntt_core(ll *a,int limit)
{
	static ll A[N];
	int sft=_len-count(limit);
	for(int i=0;i<limit;++i) A[poly_rev[i]>>sft]=a[i];
	for(int len=2,cur=1;len<=limit;len<<=1,cur<<=1)
	{
		for(int i=0;i<limit;i+=len)
		{
			ll *w=Omgs+cur;
			for(register int k(0);k<cur;++k,++w)
			{
				ll tmp=mul(*w,A[cur|i|k]);
				A[cur|i|k]=_sub(A[i|k],tmp);
				add(A[i|k],tmp);
			}
		}
	}
	for(int i=0;i<limit;++i) a[i]=A[i]%mod;
}

Finline void dft(ll *a,int limit){ntt_core(a,limit);}
Finline void idft(ll *a,int limit)
{
	std::reverse(a+1,a+limit);
	ntt_core(a,limit);
	ll inv=mod-(mod-1)/limit;
	for(int i=0;i<limit;++i) a[i]=mul(inv,a[i]);
}

void mul(ll *a,ll *b,ll *c,int n,int m) // calc a*b and restore at c
{
	static ll f[N],g[N];
	int limit=1<<_count(n+m);
	memcpy(f,a,n<<3);
	memcpy(g,b,m<<3);
	memset(f+n,0,(limit-n)<<3);
	memset(g+m,0,(limit-m)<<3);
	dft(f,limit),dft(g,limit);
	for(int i=0;i<limit;++i) f[i]=mul(f[i],g[i]);
	idft(f,limit);
	memcpy(c,f,(n+m-1)<<3);
}
}
int p[N];
ll a[N],b[N],c[N];
int main()
{
	poly::setup(1<<19);
	int n,x;
	read(n,x);
	int y;
	int len=0;
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		read(y);
		p[i]=y<x;
		if(y>=x) ans+=++len;
		else len=0;
		p[i]+=p[i-1];
		++a[-p[i]+200000];
		++b[p[i]];
	}
	++a[200000];
	poly::mul(a,b,c,200001,200001);
	printf("%lld ",ans);
	for(int i=1;i<=n;++i) printf("%lld ",c[i+200000]);
	printf("\n");
	return 0;
}