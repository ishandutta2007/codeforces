// Author -- xyr2005

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

const int N=200005;
const int mod=998244353;
const int inv2=(mod+1)>>1;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
ll fac[N],inv[N],ifac[N],pw[N],INV[N];
void init()
{
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1,pw[0]=1,pw[1]=2,INV[0]=1,INV[1]=inv2;
	for(int i=2;i<N;++i) fac[i]=fac[i-1]*i%mod,inv[i]=inv[mod%i]*(mod-mod/i)%mod,ifac[i]=ifac[i-1]*inv[i]%mod,pw[i]=pw[i-1],add(pw[i],pw[i]),INV[i]=INV[i-1]*inv2%mod;
}
inline ll C(int n,int m)
{
	if(n<m||m<0) return 0;
	return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
struct DS{
	int n,m;
	ll sum;
	DS(){sum=1;}
	void maintain(int _n,int _m)
	{
		chmin(_m,_n);
		while(m>_m) sub(sum,C(n,m--));
		while(n<_n) sum=(sum+sum-C(n++,m)+mod)%mod;
		while(n>_n) sum=(sum+C(--n,m))*inv2%mod;
		while(m<_m) add(sum,C(n,++m));
	}
	inline ll pre()
	{
		return sum;
	}
	inline ll suf()
	{
		return (pw[n]-sum+mod)%mod;
	}
}ds1,ds2;
char s[N];
int A,B,a,b;
inline ll Query()
{
	int T=a+b,X=b-A+B;
	if(T<=5)
	{
		int ans=0;
		for(int i=0;i<=T;++i)if((i-X)%2==0) add(ans,C(T,i)*abs(i-X)%mod);
		return 1LL*ans*INV[T]%mod;
	}
	ds1.maintain(T-1,X);
	ds2.maintain(T-2,X-1);
	ll ans=(1LL*X*ds1.pre()-1LL*T*ds2.pre())+(1LL*T*ds2.suf()-1LL*X*ds1.suf());
	ans=(ans%mod+mod)%mod;
	return ans*INV[T]%mod;
}
int main()
{
	init();
	int n,m;read(n,m);
	read_str(s+1);
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='b') i&1?++A:++B;
		else if(s[i]=='?') i&1?++a:++b;
	}
	printf("%lld\n",Query());
	int x;char ch;
	while(m--)
	{
		read(x);do{ch=getchar();}while(ch!='?'&&ch!='b'&&ch!='w');
		if(s[x]=='b') x&1?--A:--B;
		else if(s[x]=='?') x&1?--a:--b;
		s[x]=ch;
		if(s[x]=='b') x&1?++A:++B;
		else if(s[x]=='?') x&1?++a:++b;
		printf("%lld\n",Query());
	}
	return 0;
}