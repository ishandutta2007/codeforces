#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
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
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

// K = 3

// .X,,...X,,...X

// C(N-(M-1)*(K-1), M)

const int mod = 1e9 + 7;
const int nax = 2e5 + 5;
int fac[nax];
int inv_fac[nax];
int mul(int a, int b) {
	return (long long) a * b % mod;
}
int my_pow(int a, int b) {
	int r = 1;
	while(b) {
		if(b % 2) {
			r = mul(r, a);
		}
		a = mul(a, a);
		b /= 2;
	}
	return r;
}
int my_inv(int a) {
	return my_pow(a, mod - 2);
}
int C(int a, int b) {
	return mul(fac[a], mul(inv_fac[b], inv_fac[a-b]));
}
int inv_C(int a, int b) {
	return mul(inv_fac[a], mul(fac[b], fac[a-b]));
}

void test_case() {
	int n, k;
	scanf("%d%d", &n, &k);
	int answer = 1;
	for(int m = 1; m <= n; ++m) {
		long long a = n - (long long) (m - 1) * (k - 1);
		if(a >= m) {
			answer = (answer + (long long) C(a, m) * inv_C(n, m)) % mod;
		}
	}
		// C(N-(M-1)*(K-1), M)
	printf("%d\n", answer);
}

int main() {
	fac[0] = inv_fac[0] = 1;
	for(int i = 1; i < nax; ++i) {
		fac[i] = mul(fac[i-1], i);
		inv_fac[i] = my_inv(fac[i]);
	}
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}