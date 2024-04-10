//2022.10.5 by ljz
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
#define eb emplace_back
#define ull unsigned LL
#define uint unsigned int
#define lowbit(x) ((x)&-(x))
//#define gc getchar
#define ld long db

inline int gc() {
  static char buf[100000], *p1, *p2;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}

char sr[1 << 21], z[20];
int C = -1, Z = 0;
inline void Ot() { fwrite(sr, 1, C + 1, stdout), C = -1; }

inline void print(LL x) {
    if (C > 1 << 20)Ot();
    if (x < 0)sr[++C] = '-', x = -x;
    while (z[++Z] = x % 10 + 48, x /= 10);
    while (sr[++C] = z[Z], --Z);
}

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
	inline bool operator<(const ModInt &A) const {
		return x < A.x;
	}
#undef T
};

const int kcz = 1000000007;
//using Z = ModInt<kcz>;

inline LL qpow(LL x, LL y, const LL &ljc) {
	LL ret = 1;
	while (y) {
		if (y & 1)ret = ((LL)ret * x % ljc);
		x = ((LL)x * x % ljc), y >>= 1;
	}
	return ret;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

//2022.10.5 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=4e5+10;
namespace MAIN {
	int n,q,B;
	int fa[N];
	int lastans;
	int Fa[N],tag[N],pl[N],pr[N],part[N],sum[N];
	inline void modify(const int &x){
		if(sum[part[x]]<=B)Fa[x]=(part[fa[x]]!=part[x])?fa[x]:Fa[fa[x]];
	}
	inline void MAIN(const int &Case) {
		n=read(),q=read(),fa[1]=Fa[1]=1,B=(int)sqrt(n);
		for(int i=2;i<=n;i++)fa[i]=read();
		for(int i=1,j=1;i<=n;i+=B,j++){
			pl[j]=i,pr[j]=min(i+B-1,n);
			for(int k=i;k<i+B&&k<=n;k++)part[k]=j;
		}
		for(int i=2;i<=n;i++)modify(i);
		while(q--){
			int opt=read();
			if(opt==1){
				int l=read()^lastans,r=read()^lastans,x=read()^lastans;
				if(part[l]==part[r]){
					for(int i=l;i<=r;i++)fa[i]=max(fa[i]-x,1);
					for(int i=l;i<=pr[part[l]];i++)modify(i);
				}
				else {
					int L=part[l],R=part[r];
					for(int i=l;i<=pr[L];i++)fa[i]=max(fa[i]-x,1),modify(i);
					for(int i=L+1;i<R;i++){
						if(sum[i]>B)tag[i]=min(tag[i]+x,n);
						else {
							sum[i]++;
							for(int j=pl[i];j<=pr[i];j++)fa[j]=max(fa[j]-x,1),modify(j);
						}
					}
					for(int i=pl[R];i<=r;i++)fa[i]=max(fa[i]-x,1);
					for(int i=pl[R];i<=pr[R];i++)modify(i);
				}
			}
			else {
				int u=read()^lastans,v=read()^lastans;
				auto out=[&](const int &x){
					int p=part[x];
					return sum[p]>B?max(fa[x]-tag[p],1):Fa[x];
				};
				auto in=[&](const int &x){
					return max(1,fa[x]-tag[part[x]]);
				};
				while(u!=v){
					int fu=out(u),fv=out(v);
					if(part[fu]!=part[fv]){
						if(part[fu]<part[fv])v=fv;
						else u=fu;
					}
					else if(fu!=fv){
						if(fu<fv)v=fv;
						else u=fu;
					}
					else {
						if(u<v)v=in(v);
						else u=in(u);
					}
				}
				print(u),sr[++C]='\n';
			}
		}
	}
}

int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//	std::cout.tie(nullptr);

//    srand(time(0));
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	int Case = 1;
	for (int T = 1; T <= Case; T++)MAIN::MAIN(T);
    Ot();
	return 0;
}