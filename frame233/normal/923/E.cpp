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
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int max_len=1<<18,N=max_len+5,mod=998244353;
int _inv_[N];
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
int calc(int len)
{
	int limit=1;while(limit<len)limit<<=1;
	for(int i=0;i<limit;++i)r[i]=(r[i>>1]>>1)|(i&1?limit>>1:0);
	return limit;
}
void setup()
{
	_inv_[0]=_inv_[1]=1;for(int i=2;i<N;++i) _inv_[i]=1ULL*_inv_[mod%i]*(mod-mod/i)%mod;
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
	if(a.size()<=40u||b.size()<=40u)
	{
		poly c(len);
		for(uint i=0;i<a.size();++i) for(uint j=0;j<b.size();++j) add(c[i+j],1ull*a[i]*b[j]%mod);
		return c;
	}
	int limit=calc(len);
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
	if(a.size()<=40u||b.size()<=40u)
	{
		poly c(SZ(a)+SZ(b)-1);
		for(uint i=0;i<a.size();++i) for(uint j=0;j<b.size();++j) add(c[i+j],1ull*a[i]*b[j]%mod);
		return c.resize(len),c;
	}
	int limit=calc(len);
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
poly Inv(const poly &F)
{
	if(F.size()==1u) return {(int)ksm(F[0])};
	uint len=F.size(),l=(len+1)>>1;
	poly H(Inv({F.begin(),F.begin()+l})),tmp(mul(F,H,len)),ans(H);
	memset(tmp.data(),0,l<<2),tmp=mul(tmp,H,len,false),ans.resize(len);
	for(uint i=l;i<len;++i)tmp[i]&&(ans[i]=mod-tmp[i]);
	return ans;
}
std::pair<poly,poly> divide(const poly &f,const poly &g)
{
	int n=SZ(f),m=SZ(g);
	poly F(f),G(g);
	std::reverse(F.begin(),F.end()),F.resize(n-m+1);
	std::reverse(G.begin(),G.end()),G.resize(n-m+1);
	poly Q(F*Inv(G));
	Q.resize(n-m+1),std::reverse(Q.begin(),Q.end());
	poly R(f-Q*g);
	return R.resize(m-1),mkpr(Q,R);
}
inline poly Mod(const poly &f,const poly &g){return divide(f,g).second;}
poly Sqrt(const poly &F) // F[0]=1
{
	if(F.size()==1u) return {1};
	uint len=SZ(F),l=(len+1)>>1;
	poly H(Sqrt({F.begin(),F.begin()+l}));H.resize(len);
	poly ans(H+F*Inv(H));
	return ans.resize(len),ans/2;
}
poly deri(poly a)
{
	for(uint i=0;i+1<a.size();++i) a[i]=1LL*(i+1)*a[i+1]%mod;
	return a.pop_back(),a;
}
poly inte(poly a)
{
	a.resize(SZ(a)+1);
	for(int i=SZ(a)-1;i>=1;--i) a[i]=1LL*a[i-1]*_inv_[i]%mod;
	return a[0]=0,a;
}
poly Ln(poly F)
{
	poly ans(inte(deri(F)*Inv(F)));
	return ans.resize(SZ(F)),ans;
}
poly Exp(const poly &F) // F[0]=0;
{
	if(F.size()==1u) return {1};
	uint len=F.size(),l=(len+1)>>1;
	poly H(Exp({F.begin(),F.begin()+l}));H.resize(len);
	poly tp(F-Ln(H)),ans(H);
	H.resize(l),tp=mul(tp,H,len);
	for(uint i=l;i<len;++i)ans[i]=tp[i];
	return ans;
}
poly ksm(poly a,int b)
{
	a=Ln(a);
	for(auto &&it:a) it=1ll*it*b%mod;
	return Exp(a);
}

ll fac[N],inv[N],ifac[N];
int main()
{
	setup();
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;for(int i=2;i<N;++i)fac[i]=fac[i-1]*i%mod,inv[i]=inv[mod%i]*(mod-mod/i)%mod,ifac[i]=ifac[i-1]*inv[i]%mod;
	int n;ll m;read(n,m);
	poly p(n+1);
	for(int i=0;i<=n;++i)read(p[i]),p[i]=fac[i]*p[i]%mod;
	poly coef(n+1);
	for(int i=0;i<=n;++i)coef[i]=ifac[n-i];
	p*=coef;
	poly a(n+1);
	for(int i=0;i<=n;++i)a[i]=1LL*(i&1?mod-p[n+i]:p[n+i])*ksm(inv[i+1],m)%mod;
	a*=coef;
	for(int i=0;i<=n;++i) printf("%lld%c",(i&1?mod-ifac[i]:ifac[i])*a[i+n]%mod," \n"[i==n]);
	return 0;
}