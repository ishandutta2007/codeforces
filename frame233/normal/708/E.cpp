// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
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
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd(){static uint seed=416;return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp,typename... Args>Finline _Tp min(const _Tp &a,const _Tp &b,const Args &...args){return a<b?min(a,args...):min(b,args...);}
template <typename _Tp,typename... Args>Finline _Tp max(const _Tp &a,const _Tp &b,const Args &...args){return a<b?max(b,args...):max(a,args...);}
Finline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=1505;
const int mod=1000000007;
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
const int MAXN=100005;
ll fac[MAXN],inv[MAXN],ifac[MAXN];
ll _p[N],p[N][N],sum[N][N],pre[N][N];
ll pwp[MAXN],pwq[MAXN];
Finline ll Binom(int n,int m)
{
	if(n<m) return 0;
	return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
ll f[N][N],A[N],B[N],C[N];
int main()
{
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;
	for(int i=2;i<MAXN;++i) fac[i]=fac[i-1]*i%mod,inv[i]=inv[mod%i]*(mod-mod/i)%mod,ifac[i]=ifac[i-1]*inv[i]%mod;
	int n,m,_a,_b,k;read(n,m,_a,_b,k);
	ll P=1ll*_a*ksm(_b)%mod,Q=(1-P+mod)%mod;
	pwp[0]=pwq[0]=1;for(int i=1;i<MAXN;++i) pwp[i]=pwp[i-1]*P%mod,pwq[i]=pwq[i-1]*Q%mod;
	for(int i=0;i<=m&&i<=k;++i) _p[i]=Binom(k,i)*pwp[i]%mod*pwq[k-i]%mod;
	for(int l=1;l<=m;++l) for(int r=l;r<=m;++r) sum[l][r]=p[l][r]=_p[l-1]*_p[m-r]%mod,add(sum[l][r],sum[l][r-1]);
	for(int l=1;l<=m;++l) for(int r=l;r<=m;++r) add(sum[l][r],sum[l-1][r]),pre[l][r]=p[l][r],add(pre[l][r],pre[l-1][r]);
	f[0][m+1]=1;
	for(int j=1;j<=m+1;++j)
	{
		A[j]=A[j-1],add(A[j],_p[m-j+1]*C[j]%mod);
		B[j]=B[j-1],add(B[j],f[0][m-j+2]*pre[j-1][j-1]%mod);
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m+1;++j)
		{
			f[i][j]=sum[j-1][j-1]*f[i-1][m+1]%mod;
			sub(f[i][j],A[j]),sub(f[i][j],B[j]);
			C[j]=C[j-1];
			if(j>1) add(C[j],f[i][j-1]*_p[j-2]%mod);
		}
		for(int j=1;j<=m+1;++j)
		{
			A[j]=A[j-1],add(A[j],_p[m-j+1]*C[j]%mod);
			B[j]=B[j-1],add(B[j],f[i][m-j+2]*pre[j-1][j-1]%mod);
		}
	}
	printf("%lld\n",f[n][m+1]);
	return 0;
}