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
typedef std::pair<int,int> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;

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

const int N=200005;
const int mod=998244353;
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
ll ksm(ll a,ll b=mod-2)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}
ll fac[N],inv[N];
void init()
{
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(int i=2;i<N;++i)
	{
		fac[i]=fac[i-1]*i%mod;
		inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	}
	for(int i=2;i<N;++i)
	{
		inv[i]=inv[i-1]*inv[i]%mod;
	}
}
Finline ll C(int n,int m)
{
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
ll S(int n,int m)
{
	ll ans=0;
	for(int i=0;i<=m;++i)
	{
		if((m-i)&1) sub(ans,C(m,i)*ksm(i,n)%mod);
		else add(ans,C(m,i)*ksm(i,n)%mod);
	}
	ans=ans*inv[m]%mod;
	return ans;
}
int main()
{
	init();
	int n;
	ll k;
	read(n,k);
	if(k==0) printf("%lld\n",fac[n]);
	else if(k>=n) printf("%lld\n",0ll);
	else printf("%lld\n",2ll*C(n,n-k)*fac[n-k]%mod*S(n,n-k)%mod);
	return 0;
}