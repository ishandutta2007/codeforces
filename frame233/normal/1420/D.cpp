// Author -- xyr2005

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

Finline uint rnd(){static uint seed=416;return seed+=0x71dad4bfu,seed^=seed>>5,seed+=0xc6f74d88u,seed^=seed<<17,seed+=0x25e6561u,seed^=seed>>13;}
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

const int N=300005;
const int mod=998244353;
template<typename _Tp1,typename _Tp2>Finline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>Finline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
ll fac[N],inv[N],ifac[N];
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
	if(n<m||m<0) return 0;
	return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int l[N],r[N];
int t[N<<1],pos;
int a[N<<1];
Finline int f(int x)
{
	return x>>1;
}
int main()
{
	init();
	int n,k;read(n,k);
	for(int i=1;i<=n;++i)
	{
		read(l[i],r[i]);
		l[i]<<=1,r[i]<<=1;
		t[++pos]=l[i],t[++pos]=r[i]+1;
	}
	std::sort(t+1,t+pos+1);pos=std::unique(t+1,t+pos+1)-t-1;
	for(int i=1;i<=n;++i)
	{
		++a[std::lower_bound(t+1,t+pos+1,l[i])-t];
		--a[std::lower_bound(t+1,t+pos+1,r[i]+1)-t];
	}
	for(int i=1;i<=pos;++i) a[i]+=a[i-1];
	int ans=0;
	for(int i=1;i<=pos;++i)
	{
		int tmp=f(t[i+1]-1)-f(t[i]-1);
		tmp=tmp+tmp-(t[i+1]-t[i]);
		add(tmp,mod);
		add(ans,1ll*tmp*C(a[i],k)%mod);
	}
	printf("%d\n",ans);
	return 0;
}