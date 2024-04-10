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
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int max_len=1<<16,N=max_len+5,mod=998244353;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
template<typename _Tp>inline _Tp _sub(_Tp a,const _Tp &b){(a+=mod-b)>=mod&&(a-=mod);return a;}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
typedef std::vector<int> poly;
void print(const poly &a)
{
	for(auto it:a) printf("%d ",it);
	printf("\n");
}
poly operator << (const poly &a,uint b)
{
	poly o(a.size()+b);
	for(uint i=0;i<b;++i) o[i]=0;
	for(uint i=0;i<a.size();++i) o[i+b]=a[i];
	return o;
}
inline poly operator <<= (poly &a,uint b){return a=a<<b;}
inline poly operator >> (const poly &a,uint b){return b>=a.size()?poly():poly{a.begin()+b,a.end()};}
inline poly operator >>= (poly &a,uint b){return a=b>=a.size()?poly():poly{a.begin()+b,a.end()};}
poly operator += (poly &a,const poly &b)
{
	if(SZ(b)>SZ(a)) a.resize(SZ(b));
	for(uint i=0;i<b.size();++i) add(a[i],b[i]);
	return a;
}
inline poly operator + (const poly &a,const poly &b){poly tmp(a);tmp+=b;return tmp;}
poly operator -= (poly &a,const poly &b)
{
	if(SZ(b)>SZ(a)) a.resize(SZ(b));
	for(uint i=0;i<b.size();++i) sub(a[i],b[i]);
	return a;
}
inline poly operator - (const poly &a,const poly &b){poly tmp(a);tmp-=b;return tmp;}
ull Omgs[N];
int r[N];
const ull Omg=ksm(3,(mod-1)/max_len);
int getlen(int len)
{
	int limit=1;while(limit<len)limit<<=1;
	for(int i=0;i<limit;++i)r[i]=(r[i>>1]>>1)|(i&1?limit>>1:0);
	return limit;
}
void setup()
{
	Omgs[max_len>>1]=1;
	for(int i=(max_len>>1)+1;i<max_len;++i) Omgs[i]=Omgs[i-1]*Omg%mod;
	for(int i=(max_len>>1)-1;i>0;--i) Omgs[i]=Omgs[i<<1];
}
void dft(ull *A,int limit)
{
	for(int i=0;i<limit;++i)if(i<r[i])std::swap(A[i],A[r[i]]);
	for(int len=1;len<limit;len<<=1)
	{
		if(len==262144)for(int i=0;i<limit;++i)A[i]%=mod;
		for(int i=0;i<limit;i+=len<<1)
		{
			ull *p=A+i,*q=A+i+len,*w=Omgs+len;
			for(int _=0;_<len;++_,++p,++q,++w){ull tmp=*q**w%mod;*q=*p+mod-tmp,*p+=tmp;}
		}
	}
	for(int i=0;i<limit;++i)A[i]%=mod;
}
void idft(ull *A,int limit)
{
	std::reverse(A+1,A+limit),dft(A,limit);
	ull inv=mod-(mod-1)/limit;for(int i=0;i<limit;++i) A[i]=inv*A[i]%mod;
}
ull _f[N],_g[N];
poly operator * (const poly &a,const poly &b)
{
	uint len=a.size()+b.size()-1;
	if(a.size()<=64u||b.size()<=64u)
	{
		poly c(len);
		for(uint i=0;i<a.size();++i) for(uint j=0;j<b.size();++j) add(c[i+j],1ull*a[i]*b[j]%mod);
		return c;
	}
	int limit=getlen(len);
	memset(_f,0,limit<<3);for(uint i=0;i<a.size();++i)_f[i]=a[i];
	memset(_g,0,limit<<3);for(uint i=0;i<b.size();++i)_g[i]=b[i];
	dft(_f,limit),dft(_g,limit);
	for(int i=0;i<limit;++i)_f[i]=1ULL*_f[i]*_g[i]%mod;
	idft(_f,limit);
	poly ans(len);for(uint i=0;i<len;++i)ans[i]=_f[i];
	return ans;
}
poly mul(const poly &a,const poly &b,uint len,bool need=true)
{
	if(a.size()<=64u||b.size()<=64u)
	{
		poly c(SZ(a)+SZ(b)-1);
		for(uint i=0;i<a.size();++i) for(uint j=0;j<b.size();++j) add(c[i+j],1ull*a[i]*b[j]%mod);
		return c.resize(len),c;
	}
	int limit=getlen(len);
	memset(_f,0,limit<<3);for(uint i=0;i<a.size();++i)_f[i]=a[i];
	dft(_f,limit);
	if(need)
	{
		memset(_g,0,limit<<3);for(uint i=0;i<b.size();++i)_g[i]=b[i];
		dft(_g,limit);
	}
	for(int i=0;i<limit;++i)_f[i]=1ULL*_f[i]*_g[i]%mod;
	idft(_f,limit);
	poly ans(len);for(uint i=0;i<len;++i)ans[i]=_f[i];
	return ans;
}
inline poly operator *= (poly &a,const poly &b){return a=a*b;}
template<typename _Tp>inline poly operator *= (poly &a,const _Tp &b)
{
	for(auto &&it:a) it=1ll*it*b%mod;
	return a;
}
template<typename _Tp>inline poly operator * (poly a,const _Tp &b){return a*=b;}
template<typename _Tp>inline poly operator * (const _Tp &b,poly a){return a*=b;}
template<typename _Tp>inline poly operator /= (poly &a,const _Tp &b)
{
	ull inv=ksm(b);for(auto &&it:a) it=1ll*it*inv%mod;
	return a;
}
template<typename _Tp>inline poly operator / (poly a,const _Tp &b){return a/=b;}
template<typename _Tp>inline poly operator / (const _Tp &b,poly a){return a/=b;}

ll fac[10000005],ifac[N],inv[N];
poly getcoef(poly h,ll m,int c)
{
	static int I[N],P[N];
	int d=SZ(h)-1;
	for(int i=0;i<=d;++i)h[i]=1LL*h[i]*ifac[d-i]%mod*((d-i)&1?mod-ifac[i]:ifac[i])%mod;
	for(int i=0;i<c+d;++i)I[i]=m-d+i;
	P[0]=I[0];for(int i=1;i<c+d;++i)P[i]=1LL*I[i]*P[i-1]%mod;
	ll tp=ksm(P[c+d-1]);
	for(int i=c+d-1;i>=0;--i)P[i]=1LL*tp*(i?P[i-1]:1)%mod,tp=tp*I[i]%mod;
	poly a=mul(poly{P,P+c+d},h,c+d);
	ll cur=1;for(int i=1;i<=d;++i)cur=cur*(m-i)%mod;
	poly ans(c);
	for(int k=0;k<c;++k) cur=cur*(m+k)%mod,ans[k]=cur*a[d+k]%mod,cur=cur*P[k]%mod;
	return ans;
}
int f[N],S;
void init(int n)
{
	S=(int)sqrt(n);
	int cur=0;
	while(1LL*S*S<n)++S;
	while(1LL*S*S>n)--S;
	memset(f,0,(S+1)<<2),f[0]=1;
	for(int i=16;i>=0;--i)
	{
		if(cur)
		{
			poly h={f,f+cur+1},a=getcoef(h,cur+1,cur);
			h.resize(SZ(a)+SZ(h));for(int i=0;i<cur;++i)h[i+cur+1]=a[i];
			poly b=getcoef(h,1LL*cur*ksm(S)%mod,cur+cur+1);
			cur<<=1;for(int i=0;i<=cur;++i)f[i]=1LL*h[i]*b[i]%mod;
		}
		if((S>>i)&1)
		{
			f[++cur]=1;
			for(int j=0;j<cur;++j)f[j]=1LL*f[j]*(j*S+cur)%mod;
			for(int i=1;i<=cur;++i)f[cur]=1LL*f[cur]*(cur*S+i)%mod;
		}
	}
}
ll getfac(int n)
{
	if(n<10000005)return fac[n];
	int i,ans=1;
	for(i=0;(i+1)*S<=n;++i)ans=1LL*ans*f[i]%mod;
	for(int j=i*S+1;j<=n;++j)ans=1LL*ans*j%mod;
	return ans;
}
int a[1005],s;
inline ll getF(int a){return (getfac(s+s-1)*ksm(getfac(s+s-a-1))%mod*ksm(getfac(s))%mod*getfac(s-a)+mod-1)%mod;}
int main()
{
	setup();
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;for(int i=2;i<N;++i)inv[i]=inv[mod%i]*(mod-mod/i)%mod,ifac[i]=ifac[i-1]*inv[i]%mod;
	for(int i=2;i<10000005;++i)fac[i]=fac[i-1]*i%mod;
	int n;read(n);
	for(int i=1;i<=n;++i)read(a[i]),s+=a[i];
	init(s+s);
	int ans=mod-getF(s);
	for(int i=1;i<=n;++i)add(ans,getF(a[i]));
	ans=1LL*(mod-2)*s%mod*ksm(s-1)%mod*ans%mod;
	printf("%d\n",ans);
	return 0;
}