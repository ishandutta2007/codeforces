// Codeforces Round #472 (rated, Div. 2, based on VK Cup 2018 Round 2)
// Problem E
#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
using std::swap; using std::sort;
#include <utility>
using std::pair; using std::make_pair;
typedef long long LL;
#define pass printf("Passing Line.%d in function'%s'%c", __LINE__, __FUNCTION__, 10);
namespace BasicUnit {
		inline int readint() {
		int a = 0, po = 1; char ch = getchar();
		while(isspace(ch)) ch = getchar();
		if(ch == '-') po = -1, ch = getchar();
		while(isdigit(ch)) a = a*10 + ch - '0', ch = getchar();
		return a * po;
	}
	inline LL readLL() {
		LL a = 0, po = 1; char ch = getchar();
		while(isspace(ch)) ch = getchar();
		if(ch == '-') po = -1, ch = getchar();
		while(isdigit(ch)) a = a*10 + ch - '0', ch = getchar();
		return a * po;
	}
	template<typename T>
	inline T min(T a, T b) { return a < b ? a : b; }
	template<typename T>
	inline T max(T a, T b) { return a > b ? a : b; }
}
using namespace BasicUnit;
struct Fraction {
private:
	LL num, den;//numerator & denominator
	static LL gcd(LL a, LL b) {
		return !b ? a : gcd(b, a%b);
	}
	friend Fraction inv(const Fraction x);
public:
	Fraction(LL x = 1) : num(x), den(1) {}
	Fraction(LL num, LL den) {
		LL g = gcd(num, den);
		this->num = num / g; this->den = den / g;
		if(this->den < 0) this->num = -this->num, this->den = -this->den;
	}
	#define a (*this)
	Fraction operator + (Fraction b) const {
		LL nd = a.den / gcd(a.den, b.den) * b.den;
		LL nn = a.num * (nd / a.den) + b.num * (nd / b.den);
		LL g = gcd(nd, nn);
		return Fraction(nn / g, nd / g);
	}
	Fraction operator * (Fraction b) const {
		LL gx = gcd(a.num, b.den);
		LL gy = gcd(a.den, b.num);
		return Fraction(a.num / gx * (b.num / gy), a.den / gy * (b.den / gx));
	}
	Fraction operator / (Fraction b) const {
		return a * inv(b);
	}
	bool operator < (Fraction b) const {
//		LL g = gcd(a.den, b.den);
//		return a.num * (b.den / g) < b.num * (a.den / g);
		return a.num * b.den < b.num * a.den;
	}
	bool operator == (Fraction b) const {
		return !(a < b) && !(b < a);
	}
	bool operator > (Fraction b) const {
		return b < a;
	}
	#undef a
	void print() const {
		printf("(%lld / %lld = %.5lf)", num, den, (double)num / den);
	}
	void println() const {
		print(); printf("\n");
	}
};
Fraction inv(const Fraction x) {
	return x.den < 0 ? Fraction(-x.den, -x.num) : Fraction(x.den, x.num);
}
template<int maxN>
struct FenwickTree {
	int n, C[maxN];
	void Init(int n) {
		this->n = n;
	}
	int Sum(int x) {
		int ret = 0;
		for(int i = x; i > 0; i -= (i & -i)) ret += C[i];
		return ret;
	}
	void Modify(int x, int d) {
		for(int i = x; i <= n; i += (i & -i)) C[i] += d;
	}
};
const int maxN = 100000 + 233;
int n;
LL w, x[maxN], v[maxN];
Fraction p[maxN], q[maxN];
Fraction seq[maxN<<1]; int len = 0;
typedef pair<int, int> pii;
pii a[maxN];
FenwickTree<maxN << 1> fwt;
int t[maxN], tl;

/*3 2   -1 2   1 -2   2 -2*/

int main() {
	
	n = readint(); w = readLL();
	for(int i = 1; i <= n; i++) {
		x[i] = readLL(); v[i] = readLL();
		p[i] = Fraction(-x[i], v[i] + w);
		q[i] = Fraction(-x[i], v[i] - w);
//		printf("i-th plane got:\n\t");
//		p[i].print(); q[i].print();
//		printf("\n");
		seq[++len] = p[i]; seq[++len] = q[i];
	}
	std::sort(seq+1, seq+len+1);
	len = std::unique(seq+1, seq+len+1) - seq - 1;
//	for(int i = 1; i <= len; i++) seq[i].println();
	for(int i = 1; i <= n; i++) {
		int x = std::lower_bound(seq+1, seq+len+1, p[i]) - seq;
		int y = std::lower_bound(seq+1, seq+len+1, q[i]) - seq;
		a[i] = make_pair(x, y);
//		printf("i-th plane got (%d, %d)\n", x, y);
	}
#define GOOD
#ifdef GOOD
	std::sort(a+1, a+1+n);
	fwt.Init(n*2);
	tl = 0;
	int pre = -233;
	LL cnt = 0, smc = 0;//sth. with one same element counter
	for(int i = n; i > 0; i--) {
		if(a[i].first != pre) {
			for(int j = 0; j < tl; j++) fwt.Modify(t[j], 1);
			tl = 0;
			cnt += smc * (smc - 1) / 2;//initially 0*-1 = 0
			smc = 0;
			pre = a[i].first;
		}
		++smc;
		cnt += fwt.Sum(a[i].second);
		t[tl++] = a[i].second;
	}
	cnt += smc * (smc - 1) / 2;
#else
	LL cnt = 0;
	for(int i = 1; i <= n; i++) 
		for(int j = i+1; j <= n; j++)
			if((a[i].first - a[j].first) * (a[i].second - a[j].second) <= 0) ++cnt;
#endif

	cout << cnt << endl;
//	system("pause");
	return 0;
}