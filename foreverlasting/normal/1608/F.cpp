//2022.9.1 by ljz
//email 573902690@qq.com  
//if you find any bug in my code
//please tell me  
#include <bits/stdc++.h>
#include <random>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
//template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define LL long long
#define inf 0x3f3f3f3f
#define INF 1000000000000000000
#define unl __int128
#define db double
#define pc(x) __builtin_popcount(x)
#define ctz(x) __builtin_ctz(x)
#define Pair pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define pi acosl(-1.0)
#define pb push_back
#define ull unsigned LL
#define uint unsigned int
#define lowbit(x) ((x)&-(x))
#define gc getchar
#define ld long db

//inline int gc() {
//  static char buf[100000], *p1, *p2;
//  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
//}

//char sr[1 << 21], z[20];
//int C = -1, Z = 0;
//inline void Ot() { fwrite(sr, 1, C + 1, stdout), C = -1; }
//
//inline void print(LL x) {
//    if (C > 1 << 20)Ot();
//    if (x < 0)sr[++C] = '-', x = -x;
//    while (z[++Z] = x % 10 + 48, x /= 10);
//    while (sr[++C] = z[Z], --Z);
//}

template<typename T>
inline void Read(T &x) {
	int c = gc();
	bool f = false;
	for (x = 0; !isdigit(c); c = gc())if (c == '-')f = true;
	for (; isdigit(c); c = gc())x = x * 10 + c - '0';
	if (f)x = -x;
}

inline int read() {
	int s = 0, ch = gc(), w = 1;
	while (ch < '0' || ch > '9') {
		if (ch == '-') w = -1;
		else if (ch == EOF) break;
		ch = gc();
	}
	while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = gc();
	return s * w;
}

inline LL Read() {
	LL s = 0;
	int ch = gc(), w = 1;
	while (ch < '0' || ch > '9') {
		if (ch == '-') w = -1;
		else if (ch == EOF) break;
		ch = gc();
	}
	while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = gc();
	return s * w;
}

void write(unl x) {
	if (x > 9)write(x / 10);
	putchar(int(x % 10) + '0');
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
	inline ModInt qpow(LL n) const {
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
using Z = ModInt<998244353>;

inline LL qpow(int x, LL y, const LL &ljc) {
	int ret = 1;
	while (y) {
		if (y & 1)ret = (int)((LL)ret * x % ljc);
		x = (int)((LL)x * x % ljc), y >>= 1;
	}
	return ret;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//2022.9.1 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=2e3+10;
namespace MAIN {
	Z f[2][N][N],fac[N],inv[N],g[2][N][N];
	int cur,n,K,b[N];
	inline void MAIN(const int &Case) {
		n=read(),K=read(),fac[0]=inv[0]=1;
		for(int i=1;i<=n;i++)b[i]=read(),fac[i]=fac[i-1]*i,inv[i]=fac[i].inverse();
		f[0][0][0]=g[0][0][0]=1;
		for(int i=1;i<=n;i++){
			int L=max(b[i]-K,0),R=min(b[i]+K,i);
			int l=max(b[i-1]-K,0),r=min(b[i-1]+K,i-1);
			for(int j=L;j<=i;j++)for(int k=L;k<=j&&k<=R;k++){
				if(k>=l){
					f[cur^1][j][k]=(k?g[cur][j-1][min(k-1,r)]*inv[j-k]:0);
					f[cur^1][j][k]+=j*f[cur][j][k]+(j?f[cur][j-1][k]:0);
					g[cur^1][j][k]=(k?g[cur^1][j][k-1]:0)+f[cur^1][j][k]*fac[j-k];
				}
			}
			for(int k=l;k<=r;k++)for(int j=k;j<i;j++)f[cur][j][k]=g[cur][j][k]=0;
			cur^=1;
		}
		Z ans=0;
		int L=max(b[n]-K,0),R=min(b[n]+K,n);
		for(int k=L;k<=R;k++){
			for(int j=k;j<=n;j++){
				ans+=f[cur][j][k]*fac[n-k]*inv[n-j];
			}
		}
		printf("%d\n",ans);
	}
}

int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);

//    srand(time(0));
//    freopen("points.in", "r", stdin);
//    freopen("points.out", "w", stdout);
	int Case = 1;
	for (int T = 1; T <= Case; T++)MAIN::MAIN(T);
//    Ot();
	return 0;
}