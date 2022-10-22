#include<bits/stdc++.h>
using namespace std;
#define res int
#define LL long long
#define gc getchar
#define Pair pair<int,int>
#define fi first
#define eb emplace_back
#define se second
#define mp make_pair
#define pb push_back
#define INF 1000000000000000ll
inline int read(){
	res s=0,w=1,ch=gc();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=gc();
	}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
	return s*w;
}
template<int kcz>
struct ModInt {
#define T (*this)
	int x;
	ModInt() : x(0) {}
	ModInt(int y) : x(y >= 0 ? y : y + kcz) {}
	ModInt(LL y) : x(y >= 0 ? y % kcz : (kcz - (-y) % kcz) % kcz) {}
	inline int inc(const int &v) {
		return v >= kcz ? v - kcz : v;
	}
	inline int dec(const int &v) {
		return v < 0 ? v + kcz : v;
	}
	inline ModInt &operator+=(const ModInt &p) {
		x = inc(x + p.x);
		return T;
	}
	inline ModInt &operator-=(const ModInt &p) {
		x = dec(x - p.x);
		return T;
	}
	inline ModInt &operator*=(const ModInt &p) {
		x = (int)((LL)x * p.x % kcz);
		return T;
	}
	inline ModInt inverse() const {
		int a = x, b = kcz, u = 1, v = 0, t;
		while (b > 0)t = a / b, swap(a -= t * b, b), swap(u -= t * v, v);
		return u;
	}
	inline ModInt &operator/=(const ModInt &p) {
		T *= p.inverse();
		return T;
	}
	inline ModInt operator-() const {
		return -x;
	}
	inline friend ModInt operator+(const ModInt &lhs, const ModInt &rhs) {
		return ModInt(lhs) += rhs;
	}
	inline friend ModInt operator-(const ModInt &lhs, const ModInt &rhs) {
		return ModInt(lhs) -= rhs;
	}
	inline friend ModInt operator*(const ModInt &lhs, const ModInt &rhs) {
		return ModInt(lhs) *= rhs;
	}
	inline friend ModInt operator/(const ModInt &lhs, const ModInt &rhs) {
		return ModInt(lhs) /= rhs;
	}
	inline bool operator==(const ModInt &p) const {
		return x == p.x;
	}
	inline bool operator!=(const ModInt &p) const {
		return x != p.x;
	}
	ModInt qpow(LL n) const {
		ModInt ret(1), mul(x);
		while (n > 0) {
			if (n & 1)ret *= mul;
			mul *= mul, n >>= 1;
		}
		return ret;
	}
	inline friend ostream &operator<<(ostream &os, const ModInt &p) {
		return os << p.x;
	}
	inline friend istream &operator>>(istream &is, ModInt &a) {
		LL t;
		is >> t, a = ModInt<kcz>(t);
		return is;
	}
	static int get_mod() {
		return kcz;
	}
#undef T
};

const int kcz=998244353;
using Z=ModInt<kcz>;
const int N=2e5+10;
int fa[N],sz[N];
Z ans=1;
int n;
struct E{
	int u,v;
}edge[N];
inline void solve(){
	n=read();
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		edge[i]={u,v};
	}
	for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
	auto find=[&](int x){
		while(x!=fa[x])x=fa[x]=fa[fa[x]];
		return x;
	};
	for(int i=1;i<n;i++){
		Z ret=2*i-1;
		auto [u,v]=edge[i];
		int fu=find(u),fv=find(v);
		ret*=sz[fu],ret*=sz[fv];
		ret*=sz[fu],ret*=sz[fv];
		fa[fu]=fv,sz[fv]+=sz[fu];
		ans*=ret;
	}
	printf("%d\n",ans);
}
int main(){
	int T=1;
	while(T--)solve();
}