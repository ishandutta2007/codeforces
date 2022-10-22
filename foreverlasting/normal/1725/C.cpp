#include<bits/stdc++.h>
using namespace std;
#define res int
#define LL long long
#define gc getchar
#define Pair pair<int,int>
#define fi first
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
const int N=3e5+10;
Z fac[N],inv[N];
inline Z C(const int &x,const int &y){
	if(x<y)return 0;
	return fac[x]*inv[y]*inv[x-y];
}
int n,m;
LL a[N],s;
inline void solve(){
	n=read(),m=read();
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(int i=2;i<=N-10;i++)fac[i]=fac[i-1]*i,inv[i]=inv[kcz%i]*(kcz-kcz/i);
	for(int i=2;i<=N-10;i++)inv[i]*=inv[i-1];
	for(int i=1;i<=n;i++)a[i]=a[i-1]+read();
	int t=0;
	if(~a[n]&1){
		for(int i=2;i<=n;i++){
			int l=i,r=n,ret=0;
			while(l<=r){
				int mid=(l+r)>>1;
				if(a[mid]-a[i-1]<=a[n]/2)l=mid+1,ret=mid;
				else r=mid-1;
			}
			if(ret>0&&a[ret]-a[i-1]==a[n]/2)t++;
		}
	}
//	cout<<t<<endl;
	Z ans=0;
	for(int i=0;i<=t&&m-i>=0;i++){
		Z ret=C(t,i)*inv[m-i]*(Z{m-i}.qpow(n-t-i))*(Z{m-i-1}.qpow(t-i));
		if(m-i-1<0&&t-i!=0);
		else ans+=ret;
	}
	ans*=fac[m];
	printf("%d\n",ans);
}
int main(){
	int T=1;
	while(T--)solve();
}