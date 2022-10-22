#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<functional>
#include<chrono>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<iomanip>
#include<random>
#include<ctime>
#include<complex>
#include<type_traits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long LL;
typedef double D;
#define all(v) (v).begin(), (v).end()
mt19937 gene(chrono::system_clock::now().time_since_epoch().count());
typedef complex<double> Complex;
#define fi first
#define se second
#define ins insert
#define pb push_back
inline char GET_CHAR(){
    const int maxn = 131072;
    static char buf[maxn],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,maxn,stdin),p1==p2)?EOF:*p1++;
}
inline int getInt() {
    int res(0);
    char c = getchar();
    while(c < '0') c = getchar();
    while(c >= '0') {
        res = res * 10 + (c - '0');
        c = getchar();
    }
    return res;
}
inline LL fastpo(LL x, LL n, LL mod) {
    LL res(1);
    while(n) {
        if(n & 1) {
            res = res * (LL)x % mod;
        }
        x = x * (LL) x % mod;
        n /= 2;
    }
    return res;
}
template<LL mod> struct Num {
	LL a;
	Num operator + (const Num & b) { return Num{(a + b.a) % mod}; }
	Num operator - (const Num & b) { return Num{(a - b.a + mod) % mod}; }
	Num operator * (const Num & b) { return Num{a * b.a % mod}; }
	Num operator / (const Num & b) { return Num{a * fastpo(b.a, mod - 2, mod) % mod}; }
	void operator += (const Num & b) {if((a += b.a) >= mod) a -= mod;}
	void operator -= (const Num & b) {if((a -= b.a) < 0) a += mod;}
	void operator *= (const Num & b) { a = a * b.a % mod; }
	void operator /= (const Num & b) { a = a * fastpo(b.a, mod - 2, mod) % mod; }
	void operator = (const Num & b) { a = b.a; }
	void operator = (const LL & b) { a = b; }
};
template<LL mod> ostream & operator << (ostream & os, const Num<mod> & a) {
	os << a.a;
	return os;
}
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

inline string itoa(LL x, int width = 0) {
	string res;
	if(x == 0) res.push_back('0');
	while(x) {
		res.push_back('0' + x % 10);
		x /= 10;
	}
	while((int)res.size() < width) res.push_back('0');
	reverse(res.begin(), res.end());
	return res;
}
const int _B = 131072;
char buf[_B];
int _bl = 0;
inline void flush() {
	fwrite(buf, 1, _bl, stdout);
	_bl = 0;
}
__inline void _putchar(char c) {
	if(_bl == _B) flush();
	buf[_bl++] = c;
}
inline void print(LL x, char c) {
	static char tmp[20];
	int l = 0;
	if(!x) tmp[l++] = '0';
	else {
		while(x) {
			tmp[l++] = x % 10 + '0';
			x /= 10;
		}
	}
	for(int i = l - 1; i >= 0; i--) _putchar(tmp[i]);
	_putchar(c);
}
typedef double C;
struct P {
	C x, y;
	void scan() {
		double _x, _y;
		scanf("%lf%lf", &_x, &_y);
		x = _x; y = _y;
	}
	void print() {
		cout << '(' << x << ' ' << y << ')' << endl;
	}
	P operator + (const P & b) const { return P{x + b.x, y + b.y}; }
	P operator - (const P & b) const { return P{x - b.x, y - b.y}; }
	C operator * (const P & b) const { return x * b.y - y * b.x; }
	C operator % (const P & b) const { return x * b.x + y * b.y; }
};
P operator * (const C & x, const P & b) { return P{x * b.x, x * b.y}; }
const int N = 300033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int rela[N];
int getr(int x) {
    int p = x;
    while(rela[p] != p) p = rela[p];
    int p1 = p; p = x;
    while(rela[p] != p) {
        int p2 = rela[p];
        rela[p] = p1;
        p = p2;
    }
    return p1;
}
vector<int> pos[N];
struct Rec {
	int delta[3];
	int go[3];
	Rec() {
		memset(delta, 0, sizeof(delta));
		memset(go, 0, sizeof(go));
	}
} sgt[N * 4];
Rec merge(const Rec & a, const Rec & b) {
	Rec res;
	for(int d = 0; d < 3; d++) {
		res.go[d] = a.go[b.go[d]];
		res.delta[d] = b.delta[d] + a.delta[b.go[d]];
	}
	return res;
}
void build(int k, int le, int ri) {
	if(le == ri) {
		if(pos[le].empty()) {
			for(int d = 0; d < 3; d++) {
				sgt[k].delta[d] = 0;
				sgt[k].go[d] = d;
			}
		}else {
			sgt[k].delta[1] = sgt[k].delta[0] = 0;
			sgt[k].delta[2] = 1;
			sgt[k].go[1] = sgt[k].go[0] = 1;
			sgt[k].go[2] = 0;
		}
	}else {
		int mid = (le +ri) / 2;
		build(k * 2, le, mid);
		build(k * 2 + 1, mid + 1, ri);
		sgt[k] = merge(sgt[k * 2], sgt[k * 2 + 1]);
	}
}
Rec getsum(int k, int le, int ri, int qr) {
	if(qr == 0) {
		return Rec();
	}
	if(ri <= qr) {
		return sgt[k];
	}else {
		int mid = (le + ri) / 2;
		Rec res = getsum(k * 2, le, mid, qr);
		if(qr >= mid + 1) {
			res = merge(res, getsum(k * 2 + 1, mid + 1, ri, qr));
		}
		return res;
	}
}
void modify(int k, int le, int ri, int pos, int x) {
	if(le == ri) {
		if(x == 0) {
			for(int d = 0; d < 3; d++) {
				sgt[k].delta[d] = 1;
				sgt[k].go[d] = 0;
			}
		}else {
			assert(x == 2);
			sgt[k].delta[1] = 1;
			sgt[k].delta[2] = sgt[k].delta[0] = 0;
			sgt[k].go[1] = 0;
			sgt[k].go[2] = sgt[k].go[0] = 2;
		}
	}else {
		int mid = (le + ri) / 2;
		if(pos <= mid) modify(k * 2, le, mid, pos, x);
		else modify(k * 2 + 1, mid + 1, ri, pos, x);
		sgt[k] = merge(sgt[k * 2], sgt[k * 2 + 1]);
		
	}
	/*for(int d = 0; d < 3; d++) {
		printf("[%d %d] %d %d\n", le, ri, sgt[k].delta[d], sgt[k].go[d]);
	}*/
}
int a[N];
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if(a[i] > 0) pos[a[i]].pb(i);
	}
	build(1, 1, n);
	LL ans = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] == 0) continue;
		Rec r = getsum(1, 1, n, a[i] - 1);
		ans += r.delta[0] + 1;
		//cout << i << ' ' << r.delta[0] + 1 << endl;
		if(i == pos[a[i]].front()) modify(1, 1, n, a[i], 0);
		if(i == pos[a[i]].back()) modify(1, 1, n, a[i], 2);
	}
	cout << ans << endl;
}