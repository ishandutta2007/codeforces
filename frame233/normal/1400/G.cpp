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

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

Finline uint rnd(){static uint seed=416;return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
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

const int N=300005;
const int mod=998244353;
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
int l[N],r[N],a[N],sum[45][N];
ll fac[N],inv[N],ifac[N];
int A[25],B[25],cnt[1<<20];
void init()
{
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;
	for(int i=2;i<N;++i)
	{
		fac[i]=fac[i-1]*i%mod;
		inv[i]=inv[mod%i]*(mod-mod/i)%mod;
		ifac[i]=ifac[i-1]*inv[i]%mod;
	}
}
Finline ll C(int n,int m)
{
	if(n<m||m<0||n<0) return 0;
	return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int main()
{
	init();
	int n,m;read(n,m);
	for(int i=1;i<=n;++i) read(l[i],r[i]),++a[l[i]],--a[r[i]+1];
	for(int i=1;i<=n;++i) a[i]+=a[i-1];
	for(int i=0;i<m;++i) read(A[i],B[i]);
	for(int st=0;st<1<<m;++st)
	{
		cnt[st]=cnt[st>>1]+(st&1);
		std::vector<int> v;
		for(int i=0;i<m;++i) if((st>>i)&1) v.pb(A[i]),v.pb(B[i]);
		std::sort(v.begin(),v.end()),v.erase(std::unique(v.begin(),v.end()),v.end());
		int L=1,R=n;for(auto it:v) chmax(L,l[it]),chmin(R,r[it]);
		if(L<=R)
		{
			if(cnt[st]&1) sub(sum[SZ(v)][L],1),add(sum[SZ(v)][R+1],1);
			else add(sum[SZ(v)][L],1),sub(sum[SZ(v)][R+1],1);
		}
	}
	int ans=0;
	for(int i=0;i<=m<<1;++i)
	{
		for(int j=1;j<=n;++j)
		{
			add(sum[i][j],sum[i][j-1]);
			add(ans,1ll*sum[i][j]*C(a[j]-i,j-i)%mod);
		}
	}
	printf("%d\n",ans);
	return 0;
}