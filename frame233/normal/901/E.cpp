#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)((x).size()))
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;int mod;
typedef std::vector<int> poly;
namespace mtt{
namespace Math {
	inline int pw(int base, int p, const int mod) {
		static int res;
		for (res = 1; p; p >>= 1, base = static_cast<long long> (base) * base % mod) if (p & 1) res = static_cast<long long> (res) * base % mod;
		return res;
	}
	inline int inv(int x, const int mod) { return pw(x, mod - 2, mod); }
}

const int mod1 = 998244353, mod2 = 1004535809, mod3 = 469762049, G = 3;
const long long mod_1_2 = static_cast<long long> (mod1) * mod2;
const int inv_1 = Math::inv(mod1, mod2), inv_2 = Math::inv(mod_1_2 % mod3, mod3);
struct Int {
	int A, B, C;
	explicit inline Int() { }
	explicit inline Int(int __num) : A(__num), B(__num), C(__num) { }
	explicit inline Int(int __A, int __B, int __C) : A(__A), B(__B), C(__C) { }
	static inline Int reduce(const Int &x) {
		return Int(x.A + (x.A >> 31 & mod1), x.B + (x.B >> 31 & mod2), x.C + (x.C >> 31 & mod3));
	}
	inline friend Int operator + (const Int &lhs, const Int &rhs) {
		return reduce(Int(lhs.A + rhs.A - mod1, lhs.B + rhs.B - mod2, lhs.C + rhs.C - mod3));
	}
	inline friend Int operator - (const Int &lhs, const Int &rhs) {
		return reduce(Int(lhs.A - rhs.A, lhs.B - rhs.B, lhs.C - rhs.C));
	}
	inline friend Int operator * (const Int &lhs, const Int &rhs) {
		return Int(static_cast<long long> (lhs.A) * rhs.A % mod1, static_cast<long long> (lhs.B) * rhs.B % mod2, static_cast<long long> (lhs.C) * rhs.C % mod3);
	}
	inline int get() {
		long long x = static_cast<long long> (B - A + mod2) % mod2 * inv_1 % mod2 * mod1 + A;
		return (static_cast<long long> (C - x % mod3 + mod3) % mod3 * inv_2 % mod3 * (mod_1_2 % mod) % mod + x) % mod;
	}
} ;

#define maxn 131072

namespace Poly {
#define N (maxn << 1)
	int lim, s, rev[N];
	Int Wn[N | 1];
	inline void init(int n) {
		s = -1, lim = 1; while (lim < n) lim <<= 1, ++s;
		for (int i = 1; i < lim; ++i) rev[i] = rev[i >> 1] >> 1 | (i & 1) << s;
		const Int t(Math::pw(G, (mod1 - 1) / lim, mod1), Math::pw(G, (mod2 - 1) / lim, mod2), Math::pw(G, (mod3 - 1) / lim, mod3));
		*Wn = Int(1); for (Int *i = Wn; i != Wn + lim; ++i) *(i + 1) = *i * t;
	}
	inline void NTT(Int *A, const int op = 1) {
		for (int i = 1; i < lim; ++i) if (i < rev[i]) std::swap(A[i], A[rev[i]]);
		for (int mid = 1; mid < lim; mid <<= 1) {
			const int t = lim / mid >> 1;
			for (int i = 0; i < lim; i += mid << 1) {
				for (int j = 0; j < mid; ++j) {
					const Int W = op ? Wn[t * j] : Wn[lim - t * j];
					const Int X = A[i + j], Y = A[i + j + mid] * W;
					A[i + j] = X + Y, A[i + j + mid] = X - Y;
				}
			}
		}
		if (!op) {
			const Int ilim(Math::inv(lim, mod1), Math::inv(lim, mod2), Math::inv(lim, mod3));
			for (Int *i = A; i != A + lim; ++i) *i = (*i) * ilim;
		}
	}
#undef N
}

int n, m;
Int A[maxn << 1], B[maxn << 1];
poly mul(const poly &a,const poly &b,int len=-1){
	n=SZ(a),m=SZ(b);
	for(int i=0;i<n;++i)A[i]=Int(a[i]);
	for(int i=0;i<m;++i)B[i]=Int(b[i]);
	if(len==-1)len=n+m-1;
	Poly::init(len),Poly::NTT(A),Poly::NTT(B);
	for(int i=0;i<Poly::lim;++i)A[i]=A[i]*B[i];
	Poly::NTT(A,0);poly ans(len);
	for(int i=0;i<len;++i)ans[i]=A[i].get();
	for(int i=0;i<Poly::lim;++i)A[i]=B[i]=Int(0);
	return ans;
}
}
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a<b?a+mod-b:a-b;}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
int G,pw[N*2],ipw[N*2];
void print(const poly &a){
	for(auto it:a)fprintf(stderr,"%d ",it);
	fprintf(stderr,"\n");
}
poly operator * (const poly &a,const poly &b){
	poly c=mtt::mul(a,b);int n=SZ(a);for(int i=n;i<SZ(c);++i)add(c[i-n],c[i]);
	c.resize(n);return c;
}
poly DFT(const poly &a){
	int n=SZ(a);poly A(n*2),B(n),ans(n);
	for(int i=0;i<n*2;++i)A[i]=pw[i];
	for(int i=0;i<n;++i)B[n-1-i]=1LL*a[i]*ipw[i]%mod;
	poly C=mtt::mul(A,B,n*2);
	for(int i=0;i<n;++i)ans[i]=1LL*ipw[i]*C[i+n-1]%mod;
	return ans;
}
poly IDFT(const poly &a){
	int n=SZ(a);poly A(n*2),B(n),ans(n);
	for(int i=0;i<n*2;++i)A[i]=ipw[i];
	for(int i=0;i<n;++i)B[n-1-i]=1LL*a[i]*pw[i]%mod;
	poly C=mtt::mul(A,B,n*2);
	for(int i=0;i<n;++i)ans[i]=1LL*pw[i]*C[i+n-1]%mod;
	ll inv=ksm(n);for(int i=0;i<n;++i)ans[i]=inv*ans[i]%mod;
	return ans;
}
bool check(int x){
	for(int i=2;i*i<=x;++i)if(x%i==0)return 0;
	return 1;
}
int getg(int p){
	std::vector<int> vec;int x=p-1;
	for(int i=2;i*i<=x;++i)if(x%i==0){vec.pb(i);while(x%i==0)x/=i;}
	if(x>1)vec.pb(x);
	for(int g=2;;++g){
		bool flag=1;for(auto it:vec)flag&=ksm(g,(p-1)/it)!=1;
		if(flag)return g;
	}
}
int main(){
	int n;read(n);
	for(mod=n*((int)(1e7/n))+1;;mod+=n)if(check(mod))break;
	G=getg(mod),G=ksm(G,(mod-1)/n);
	for(int i=0;i<N*2;++i)pw[i]=ksm(G,1LL*i*(i-1)/2),ipw[i]=ksm(pw[i]);
	poly b(n),c(n);ll s=0;
	for(int i=0;i<n;++i)read(b[i]),s+=b[i]*b[i];
	std::reverse(b.begin()+1,b.begin()+n);
	for(int i=0;i<n;++i)read(c[i]),c[i]=(c[i]+mod-s%mod)%mod;
	for(int i=0;i<n;++i)b[i]=1LL*(mod-2)*b[i]%mod;
	poly db=DFT(b);for(int i=0;i<n;++i)db[i]=ksm(db[i]);
	poly ib=IDFT(db),a=c*ib;
	int ans=0,sb=0;for(int i=0;i<n;++i)add(sb,ib[i]);
	sb=(mod-sb)%mod;std::vector<std::vector<int>> res;
	int s1=0,s2=0;for(int i=0;i<n;++i)add(s1,a[i]),add(s2,1LL*a[i]*a[i]%mod);
	for(int T=0;T<mod;++T){
		if(s2==T){
			bool flag=1;
			for(int i=0;i<n;++i){
				int tmp=(a[i]+1LL*T*sb)%mod;
				if(tmp>10000&&tmp<mod-10000){flag=0;break;}
			}
			if(flag&&++ans<=10){
				std::vector<int> cur;
				for(int i=0;i<n;++i){
					int tmp=(a[i]+1LL*T*sb)%mod;
					cur.pb(tmp<1e4?tmp:tmp-mod);
				}
				res.pb(cur);
			}
		}
		s2=(s2+2LL*sb*s1+1LL*sb*sb%mod*n)%mod,add(s1,1LL*n*sb%mod);
	}
	printf("%d\n",ans);
	if(ans<=10){
		std::sort(res.begin(),res.end());
		for(const auto &vec:res){
			for(auto it:vec)printf("%d ",it);
			printf("\n");
		}
	}
	return 0;
}