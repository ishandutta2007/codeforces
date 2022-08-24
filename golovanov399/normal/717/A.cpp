//MIPT Cryptozoology
//Room 202
#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:128000000")
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <bitset>
#include <set>
#include <map>
#include <cassert>
#include <memory.h>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define itn int

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

typedef long long li;
typedef long long i64;
typedef double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

void precalc();

int TESTNUM = 0;
#define FILENAME ""

int main() {
	string s = FILENAME;
#ifdef YA
	//assert(!s.empty());
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//cerr<<FILENAME<<endl;
	//assert (s != "change me please");
	clock_t start = clock();
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(FILENAME ".in", "r", stdin);
	//freopen(FILENAME ".out", "w", stdout);
	cin.tie(0);
#endif
	//cout.sync_with_stdio(0);
	cout.precision(10);
	cout << fixed;
	precalc();
	int t = 1;
	//cin >> t;
	while (t--) {
		++TESTNUM;
		solve();
	}
#ifdef YA
	cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
	return 0;
}

//#define int li

/*int pr[] = { 97, 2011 };
int mods[] = { 1000000007, 1000000009 };

const int C = 100500;
int powers[2][C];*/

//int MOD = 1000000007;

//int c[5010][5010];

template<typename T>
T binpow(T q, T w, T mod) {
	if (!w)
		return 1 % mod;
	if (w & 1)
		return q * 1LL * binpow(q, w - 1, mod) % mod;
	return binpow(q * 1LL * q % mod, w / 2, mod);
}

void precalc() {

	/*for (int w = 0; w < 2; ++w) {
	powers[w][0] = 1;
	for (int j = 1; j < C; ++j) {
	powers[w][j] = (powers[w][j - 1] * 1LL * pr[w]) % mods[w];
	}
	}*/

	/*for (int i = 0; i < 5010; ++i) {
	c[i][i] = c[i][0] = 1;
	for (int j = 1; j < i; ++j) {
	c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
	}
	}*/
}

template<typename T>
T gcd(T q, T w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}
template<typename T>
T lcm(T q, T w) {
	return q / gcd(q, w) * w;
}

inline int nxt(){
	int x;
	cin >> x;
	return x;
}

#define int li

const int mod = 1000000007;

struct Num {
	int a, b;

	Num(int x = 0, int y = 0) {
		a = x;
		b = y;
	}

	Num operator +(const Num& other) const {
		int na = a + other.a;
		int nb = b + other.b;
		if (na >= mod)
			na -= mod;
		if (nb >= mod)
			nb -= mod;
		return Num(na, nb);
	}

	Num operator -(const Num& other) const {
		int na = a - other.a;
		int nb = b - other.b;
		if (na < 0)
			na += mod;
		if (nb < 0)
			nb += mod;
		return Num(na, nb);
	}

	Num operator *(const Num& other) const {
		long long na = (1ll * a * other.a + 5ll * b * other.b) % mod;
		long long nb = (1ll * a * other.b + 1ll * b * other.a) % mod;
		if (na < 0)
			na += mod;
		if (nb < 0)
			nb += mod;
		return Num(na, nb);
	}

	int norm() const {
		int tmp = (1ll * a * a - 5ll * b * b) % mod;
		if (tmp < 0)
			tmp += mod;
		return tmp;
	}

	Num overline() const {
		return (b == 0) ? *this : Num(a, mod - b);
	}

	Num operator /(const Num& other) const {
		int inv = other.norm();
		inv = binpow<long long>(inv, mod - 2, mod);
		Num res = (*this * other.overline());
		res.a = 1ll * res.a * inv % mod;
		res.b = 1ll * res.b * inv % mod;
		return res;
	}

	void out() const {
		if (a && b) {
			if (b == 1)
				cerr << a << " + sqrt(5)\n";
			else
				cerr << a << " + " << b << " * sqrt(5)\n";
		}
		else
		{
			if (b) {
				if (b == 1)
					cerr << "sqrt(5)\n";
				else
					cerr << b << " * sqrt(5)\n";
			}
			else
				cerr << a << "\n";
		}
	}
};

Num pw(Num a, long long n) {
	Num res(1);
	while (n){
		if (n & 1ll)
			res = res * a;
		n >>= 1;
		a = a * a;
	}
	return res;
}

Num sum(const Num& x, long long l, long long r){
	if (x.a == 1 && x.b == 0)
		return (r - l + 1) % mod;
	return pw(x, l) * (pw(x, r - l + 1) - 1) / (x - 1);
}

const int K = 222;
int C[K][K];

vector<long long> polymult(const vector<long long>& p1, const vector<long long>& p2) {
	vector<long long> res;
	for (int i = 0; i < (int)p1.size(); i++) {
		for (int j = 0; j < (int)p2.size(); j++) {
			if (res.size() <= i + j)
				res.push_back(0);
			res[i + j] += p1[i] * p2[j] % mod;
		}
	}
	for (auto& x : res) {
		x %= mod;
		if (x < 0)
			x += mod;
	}
	return res;
}

int stupid(int k, long long l, long long r) {
	int index = 1;
	l += 2, r += 2;
	int x = 0;
	int y = 1;
	long long ans = 0;
	while (index <= r){
		if (index >= l) {
			long long cur = 1;
			for (int i = 0; i < k; i++){
				cur = cur * (y - i) % mod * binpow<long long>(i + 1, mod - 2, mod) % mod;
			}
			ans += cur;
		}
		x = (x + y) % mod;
		swap(x, y);
		index++;
	}
	return ans % mod;
}

int not_stupid(int k, long long l, long long r) {
	Num phi_1(1, 1);
	Num phi_2(1, mod - 1);
	phi_1 = phi_1 / 2;
	phi_2 = phi_2 / 2;
	Num denom = Num(1) / Num(0, 1);

	l += 2;
	r += 2;

	for (int i = 0; i < K; i++){
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++) {
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			if (C[i][j] >= mod)
				C[i][j] -= mod;
		}
	}

	vector<Num> sm(k + 1);
	Num curdenom(1);
	for (int d = 0; d <= k; d++) {
		Num cur = pw(phi_1, d);
		int co = 1;
		for (int i = 0; i <= d; i++) {
			sm[d] = sm[d] + sum(cur, l, r) * C[d][i] * co;
			co = mod - co;
			cur = cur * phi_2 / phi_1;
		}
		sm[d] = sm[d] * curdenom;
		curdenom = curdenom * denom;
	}

	vector<long long> poly(1, 1);
	for (int i = 0; i < k; i++) {
		poly = polymult(poly, { -i, 1 });
	}

	Num ans(0);
	for (int i = 0; i <= k; i++) {
		ans = ans + sm[i] * poly[i];
	}

	long long fact = 1;
	for (int i = 1; i <= k; i++)
		fact = fact * i % mod;

	return (ans / fact).a;
}

void solve() {
	
	/*while (true) {
		int k = rand() % 200 + 1;
		int l = rand() % 10000 + 1, r = rand() % 10000 + 1;
		//int l = 1, r = 1e18;
		if (l > r)
			swap(l, r);
		int st = stupid(k, l, r);
		int sm = not_stupid(k, l, r);
		if (st != sm) {
		//if (sm < 0 || sm >= mod) {
			cout << k << " " << l << " " << r << "\n";
			cout << "the answer is " << st << " while you printed " << sm << "\n";
			return;
		}
		else {
			cout << "ok, ";
			fflush(stdout);
		}
	}*/
	
	int k;
	cin >> k;
	long long l, r;
	cin >> l >> r;

	int res = not_stupid(k, l, r) % mod;
	if (res < 0) {
		res += mod;
	}
	cout << res << "\n";
}