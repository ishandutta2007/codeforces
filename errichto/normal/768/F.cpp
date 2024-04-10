#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const int mod = 1e9 + 7;
const int nax = 2e5 + 5;

int my_pow(int a, int b) {
	int r = 1;
	while(b) {
		if(b % 2) r = (long long) r * a % mod;
		a = (long long) a * a % mod;
		b /= 2;
	}
	return r;
}

int fac[nax], inv[nax], inv_fac[nax];

void pre() {
	fac[0] = 1;
	for(int i = 1; i < nax; ++i)
		fac[i] = (long long) fac[i-1] * i % mod;
	inv[0] = 1;
	for(int i = 1; i < nax; ++i)
		inv[i] = my_pow(i, mod - 2);
	inv_fac[0] = 1;
	for(int i = 1; i < nax; ++i)
		inv_fac[i] = (long long) inv_fac[i-1] * inv[i] % mod;
}

int newton(long long a, int b) {
	if(a < b || a < 0 || b < 0) return 0;
	return (long long) fac[a] * inv_fac[b] % mod * inv_fac[a-b] % mod;
}

vector<int> he(int a, int h) {
	vector<int> w(nax, 0);
	for(int i = 0; i < nax; ++i)
		w[i] = newton(a - 1 - (long long) h * i, i - 1);
	if(a == 0 && h == 0) w[0] = 1;
	return w;
}

int merge(vector<int> a, vector<int> b) {
	int x = 0;
	for(int i = 0; i < (int) a.size() - 1; ++i) {
		x = (x + 2LL * a[i] * b[i]) % mod;
		x = (x + 1LL * a[i] * b[i+1]) % mod;
		x = (x + 1LL * a[i+1] * b[i]) % mod;
	}
	return x;
}

int main() {
	pre();
	int food, wine, h;
	cin >> food >> wine >> h;
	if(wine == 0) {
		puts("1");
		return 0;
	}
	vector<int> a = he(food, 0);
	vector<int> b = he(wine, 0);
	vector<int> c = he(wine, h);
	/*debug() << imie(a);
	debug() << imie(b);
	debug() << imie(c);*/
	int one = merge(a, c), two = merge(a, b);
	debug() << imie(one) << imie(two);
	int ans = (long long) my_pow(two, mod - 2) * one % mod;
	printf("%d\n", ans);
}