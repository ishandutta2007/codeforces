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
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return !b?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
template <typename _Tp>inline void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s){
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=205,mod=1000000007;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
typedef std::vector<int> poly;
ll fac[N],inv[N],ifac[N];
poly operator * (const poly &a,const poly &b){
	if(a.empty()||b.empty())return {};
	poly c(a.size()+b.size()-1);
	for(uint i=0;i<a.size();++i)for(uint j=0;j<b.size();++j)c[i+j]=(c[i+j]+1ULL*a[i]*b[j])%mod;
	return c;
}
poly Inv(const poly &a){ // a[0] = 1
	poly b(a.size());b[0]=1;
	for(int i=1;i<SZ(a);++i){
		int o=0;
		for(int j=0;j<i;++j)sub(o,1ULL*b[j]*a[i-j]%mod);
		b[i]=o;
	}
	return b;
}
poly Exp(const poly &a){ // a[0] = 0
	static int df[N];
	for(int i=0;i+1<SZ(a);++i)df[i]=1LL*a[i+1]*(i+1)%mod;
	poly b(SZ(a));b[0]=1;
	for(int i=0;i+1<SZ(a);++i)
	{
		int o=0;
		for(int j=0;j<=i;++j)add(o,1LL*b[j]*df[i-j]%mod);
		b[i+1]=1ULL*o*inv[i+1]%mod;
	}
	return b;
}
void init(){fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;for(int i=2;i<N;++i)fac[i]=fac[i-1]*i%mod,inv[i]=inv[mod%i]*(mod-mod/i)%mod,ifac[i]=ifac[i-1]*inv[i]%mod;}
int main(){
	init();
	int n,k;read(n,k);
	poly a(k+1),b(k+1);
	for(int i=1;i<=k+1;++i)a[i-1]=ifac[i]*ksm(n,i)%mod,b[i-1]=ifac[i];
	a=a*Inv(b);
	for(int i=0;i<=k;++i)a[i]=fac[i]*a[i]%mod;
	poly c(k+1);
	for(int i=1;i<=k;++i){
		c[i]=1LL*a[i]*inv[i]%mod;
		if(i%2==0)c[i]=(mod-c[i])%mod;
	}
	c=Exp(c);
	for(int i=2;i<=k;++i)add(c[i],c[i-2]);
	for(int i=1;i<=k;++i)printf("%d%c",c[i]," \n"[i==k]);
	return 0;
}