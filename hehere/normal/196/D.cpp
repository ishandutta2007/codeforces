#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <cstdlib>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
using std::sort; using std::min; using std::max;
#include <vector>
using std::vector;
#include <set>
using std::set;
#include <queue>
using std::queue; using std::priority_queue;
#include <utility>
using std::pair;
typedef pair<int, int> pii;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define pass printf("%s : Line.%d\n", __FUNCTION__, __LINE__);

const int maxN = 400000 + 233;
int n, d;
char s[maxN];
//const LL b1 = 137, p1 = 1000000007;
//const LL b2 = 203, p2 = 998244353;
/*
struct Hash {
private:
	static LL pow_mod(LL a, LL b, LL p) {
		LL r = 1;
		while(b) {
			if(b & 1) (r *= a) %= p;
			(a *= a) %= p;
			b >>= 1;
		}
		return r;
	}
	static void inc(LL a, LL b, LL p) {
		(a += b) >= p ? a -= p : a;
	}
	static void dec(LL a, LL b, LL p) {
		(a -= b) < 0 ? a += p : a;
	}
public:
	static void initialize(Hash *w) {
		w[0] = Hash(1, 1);
		w[1] = Hash(b1, b2);
		w[-1] = Hash(pow_mod(b1, p1 - 2, p1), pow_mod(b2, p2 - 2, p2));
//		printf("%lld * %lld = %lld, %lld * %lld = %lld\n",
//			b1, w[-1].v1, b1 * w[-1].v1 % p1,
//			b2, w[-1].v2, b2 * w[-1].v2 % p2);
		for(int i = 2; i <= n + 2; ++i) w[i] = w[i-1] * w[1], w[-i] = w[-(i-1)] * w[-1];
	}
	LL v1, v2;
	Hash() : v1(0), v2(0) {}
	Hash(LL _v1, LL _v2) : v1(_v1), v2(_v2) {}
	Hash &operator = (const int &rhs) {
		v1 = v2 = rhs;
		return *this;
	}
	Hash &operator = (const LL &rhs) {
		v1 = v2 = rhs;
		return *this;
	}
	Hash &operator += (const Hash &rhs) {
		inc(v1, rhs.v1, p1);
		inc(v2, rhs.v2, p2);
		return *this;
	}
	friend Hash operator + (const Hash &lhs, const Hash &rhs) {
		Hash h = lhs; h += rhs;
		return h;
	}
	Hash &operator -= (const Hash &rhs) {
		dec(v1, rhs.v1, p1);
		dec(v2, rhs.v2, p2);
		return *this;
	}
	friend Hash operator - (const Hash &lhs, const Hash &rhs) {
		Hash h = lhs; h -= rhs;
		return h;
	}
	Hash &operator *= (const Hash &rhs) {
		(v1 *= rhs.v1) %= p1;
		(v2 *= rhs.v2) %= p2;
		return *this;
	}
	friend Hash operator * (const Hash &lhs, const Hash &rhs) {
		Hash h = lhs; h *= rhs;
		return h;
	}
	friend bool operator == (const Hash &lhs, const Hash &rhs) {
		return lhs.v1 == rhs.v1 && lhs.v2 == rhs.v2;
	}
};
Hash bucket[maxN * 2];
Hash *w = bucket + maxN;*/
ULL B = 123456789123456789ULL;
ULL w[maxN];
ULL h[maxN], rh[maxN];

//#define BF
bool isp(int l, int r) {
	if(l < 1) return false;
#ifndef BF
	ULL x = (h[r] - h[l - 1] * w[r - l + 1]) * w[l - 1];
	ULL y = rh[r] - rh[l - 1];
	return x == y;
#else
	for(int i = l, j = r; i <= j; ++i, --j) if(s[i] != s[j]) return false;
	return true;
#endif
}

void no_solution() {
	printf("Impossible\n");
	exit(0);
}

int increase(int x) {
	while(s[x] == 'z') {
		s[x] = 'a';
		--x;
	}
	if(!x) no_solution();
	++s[x];
	return x;
}

void solve() {
	increase(n);
	w[0] = 1;
	for(int i = 1; i <= n + 5; ++i) w[i] = w[i-1] * B;
//	Hash::initialize(w);
	h[0] = rh[0] = 0;
	int front = maxN;
	for(int i = 1; i <= n; ++i) {
		if(i > front) s[i] = 'a';
		h[i] = h[i - 1] * B + s[i];
		rh[i] = rh[i - 1] + s[i] * w[i - 1];
		if(isp(i - d, i)) {
			front = increase(i);
			i = front - 1;
		} else if(isp(i - d + 1, i)) {
			front = increase(i);
			i = front - 1;
		}
	}
}

int main() {
	scanf("%d", &d);
	memset(s, 0, sizeof(s));
	scanf("%s", s + 1);
	n = strlen(s + 1);
	solve();
	printf("%s\n", s + 1);
	return 0;
}