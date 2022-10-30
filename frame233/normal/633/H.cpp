// Author -- xyr2005
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>inline void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=30005;
int a[N],t[N],ans[N],L[N],R[N],b[N],f[N],l[N],mod;
struct FastMod{
	typedef __uint128_t LLL;
	ull b,m;
	void init(ull b){this->b=b,m=ull((LLL(1)<<64)/b);}
	inline ull operator()(ull a){
		ull r=a-(ull)((LLL(m)*a)>>64)*b;
		return r>=b?r-b:r;
	}
}M;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
int main()
{
	int n,m;read(n,mod),M.init(mod);
	for(int i=1;i<=n;++i)read(a[i]),t[i]=i;
	read(m),std::sort(t+1,t+n+1,[&](int A,int B)->bool{return a[A]<a[B];});
	for(int i=1;i<=m;++i) read(L[i],R[i]);
	f[0]=f[1]=1;for(int i=2;i<N;++i) f[i]=f[i-1],add(f[i],f[i-2]);
	for(int _=1,i=t[_];_<=n;i=t[++_]) for(int j=1;j<=m;++j)if(L[j]<=i&&i<=R[j]&&l[j]!=a[i]) l[j]=a[i],add(ans[j],M(1LL*f[b[j]++]*a[i]));
	for(int i=1;i<=m;++i) printf("%d\n",ans[i]);
	return 0;
}