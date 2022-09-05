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

const int nax = 1e6 + 5;
const int mod = 1e9 + 7;
int dp[nax];

int mul(int a, int b) {
	return (long long) a * b % mod;
}
void add_self(int & a, int b) {
	a += b;
	if(a >= mod) a -= mod;
}
void sub_self(int & a, int b) {
	a -= b;
	if(a < 0) a += mod;
}
int add(int a, int b) {
	add_self(a, b);
	return a;
}

int my_pow(int a, int b) {
	int r = 1;
	while(b) {
		if(b % 2) r = mul(r, a);
		a = mul(a, a);
		b /= 2;
	}
	return r;
}
int my_inv(int a) {
	return my_pow(a, mod - 2);
}

int main() {
	debug() << my_pow(5, 3);
	debug() << imie(my_inv(2));
	for(int i = 2; i <= 10; ++i)
		assert(mul(i, my_inv(i)) == 1);
	
	int n, k;
	cin >> n >> k;
	dp[1] = 1;
	int z = 0;
	int przez = 1;
	for(int i = 2; i <= n; ++i) {
		add_self(z, dp[i-1]);
		dp[i] = z;
		
		
		z = mul(z, i - 1);
		przez = mul(przez, i - 1);
		debug() << "mnoz" imie(i - 1);
		if(i - k - 1 >= 1) {
			debug() << "dziel" imie(i - k - 1);
			przez = mul(przez, my_inv(i - k - 1));
		}
		
		if(i >= k + 1) {
			int tmp = dp[i-k];
			
			//~ int pp = 1;
			//~ for(int x = i - k + 1; x <= i; ++x)
				//~ pp = mul(pp, x - 1);
			//~ debug() << imie(pp) imie(przez);
			sub_self(z, mul(tmp, przez));
		}
		//~ add_self(z, dp[i]);
	}
	debug() << imie(z);
	for(int i = 1; i <= n; ++i)
		debug() << imie(i) imie(dp[i]);
	int answer = 0;
	for(int i = 1; i <= n; ++i) {
		add_self(answer, dp[i]);
		if(i != n) answer = mul(answer, i);
	}
	int fac = 1;
	for(int i = 2; i <= n; ++i)
		fac = mul(fac, i);
	printf("%d\n", (fac - answer + mod) % mod);
}