//2022.9.6 by ljz
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

const int kcz = 998244353;
using Z = ModInt<kcz>;

inline LL qpow(int x, LL y, const LL &ljc) {
	int ret = 1;
	while (y) {
		if (y & 1)ret = (int)((LL)ret * x % ljc);
		x = (int)((LL)x * x % ljc), y >>= 1;
	}
	return ret;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

//2022.9.7 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
const int N=1.2e6+10;
namespace MAIN {
	int n;
	Pair o[N/6];
	int a[N],c[N];
	int mn[N<<2],tag[N<<2];
	void build(int rt,int l,int r){
		if(l==r){mn[rt]=c[l];return;}
		int mid=(l+r)>>1;
		build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
		mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);
	}
	inline void change(const int &rt,const int &v){
		mn[rt]+=v,tag[rt]+=v;
	}
	inline void pushdown(const int &rt){
		if(!tag[rt])return;
		change(rt<<1,tag[rt]),change(rt<<1|1,tag[rt]),tag[rt]=0;
	}
	void modify(int rt,int l,int r,const int &L,const int &R){
		if(L<=l&&r<=R){change(rt,-1);return;}
		int mid=(l+r)>>1;
		pushdown(rt);
		if(L<=mid)modify(rt<<1,l,mid,L,R);
		if(R>mid)modify(rt<<1|1,mid+1,r,L,R);
		mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);
	}
	priority_queue<int> Q;
	void solve(int rt,int l,int r){
		if(mn[rt]>0)return;
		if(l==r){Q.push(l),mn[rt]=inf;return;}
		int mid=(l+r)>>1;
		pushdown(rt);
		solve(rt<<1,l,mid),solve(rt<<1|1,mid+1,r);
		mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);
	}
	int end;
	int tr[N];
	inline void modify(const int &x,const int &y){
		for(int i=x;i<=2*n;i+=lowbit(i))tr[i]+=y;
	}
	inline int query(const int &x){
		int ret=0;
		for(int i=x;i;i-=lowbit(i))ret+=tr[i];
		return ret;
	}
	inline void MAIN(const int &Case) {
		n=read();
		for(int i=1;i<=n;i++)o[i].fi=read();
		for(int i=1;i<=n;i++)a[o[i].fi<<1|(o[i].se=read())]++,modify(o[i].fi,1);
		sort(o+1,o+n+1);
		{
			int fl=0;
			for(int i=1;i<=n;i++)if(o[i].fi!=o[1].fi){fl=1;break;}
			if(!fl){
				Z ans=1;
				for(int i=1;i<=n;i++)ans*=i;
				printf("%d\n",ans);
				return;
			}
		}
		int C=0;
		for(int i=1;i<=n;i++){
			if(o[i].fi!=o[1].fi)break;
			if(!o[i].se){puts("0");return;}
			C++;
		}
		end=o[1].fi+n-C;
		for(int i=1;i<=2*end+1;i++)c[i]=inf;
		for(int i=1;i<=n;){
			int j=i;
			while(j<=n&&o[j].fi==o[i].fi)j++;
			int p=0;
			for(int k=i;k<j;k++){
				if(o[k].se==1){p=k;break;}
			}
			if(p!=i){
				int t=o[i].fi<<1|o[i].se;
				if(o[i].fi+i-1<end){puts("0");return;}
				c[t]=o[i].fi+i-1-end;
			}
			if(p){
				int t=o[p].fi<<1|o[p].se;
				if(o[p].fi+n-j+1>end){puts("0");return;}
				c[t]=end-(o[p].fi+n-j+1);
			}
			i=j;
		}
//		printf("%d\n",end);
//		for(int i=2;i<=2*end+1;i++)if(c[i]<inf)printf("%d %d %d\n",i,c[i],a[i]);
		build(1,2,2*end);
		solve(1,2,2*end);
		Z ans=1;
		while(!Q.empty()){
			int p=Q.top();
			if(p&1){
				int tmp=query(2*n)-query(p>>1);
				if((p>>1)+tmp>end){puts("0");return;}
			}
			ans*=a[p];
			modify(p>>1,-1);
			a[p]--;
			modify(end,1);
			if(!a[p])Q.pop();
			int q=p+1;
			if(q<=2*end)modify(1,2,2*end,q,2*end);
			solve(1,2,2*end);
		}
		for(int i=2;i<=4*n+1;i++)if(a[i]&&i!=2*end+1){puts("0");return;}
		int x=a[2*end+1];
		for(int i=1;i<=n;i++)ans*=i;
		for(int i=1;i<=n-x;i++)ans/=i;
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