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
const int N=1e5+10;
Pair a[N];
int ans[N];
inline void solve(){
	int n=read();
	for(int i=1;i<=n;i++){
		int l=read(),r=read();
		a[i]={l,r};
	}
	for(int j=0;j<=30;j++){
		int ret=0;
		vector<Pair> A;
		for(int i=1;i<=n;i++){
			auto [l,r]=a[i];
			int len=r-l+1;
			if(len>=1<<j)ret++;
			else {
				int L=l%(1<<j);
				int R=L+len-1;
				if(R<(1<<j)){
					A.eb(L,1),A.eb(R+1,-1);
				}
				else {
					A.eb(L,1),A.eb((1<<j),-1);
					A.eb(0,1),A.eb((R%(1<<j))+1,-1);
				}
			}
		}
		sort(A.begin(),A.end());
		int mx=0,now=0;
		for(int i=0,sz=(int)A.size();i<sz;){
			int k=i;
			while(A[k].fi==A[i].fi&&k<sz)k++;
			for(int l=i;l<k;l++)now+=A[l].se;
			mx=max(mx,now);
			i=k;
		}
		ans[j]=mx+ret;
	}
	int q=read();
	while(q--){
		int w=read();
		for(int j=0;j<=30;j++)if(w>>j&1){
			printf("%d\n",ans[j]);break;
		}
	}
}
int main(){
	int T=1;
	while(T--)solve();
}