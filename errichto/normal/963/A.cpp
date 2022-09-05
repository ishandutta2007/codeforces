#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
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

typedef long long ll;

const int mod = 1e9 + 9;
int mul(int a, int b) { return (ll) a * b % mod; }
int my_pow(int a, int b) {
	int r = 1;
	while(b) {
		if(b % 2) r = mul(r, a);
		a = mul(a, a);
		b /= 2;
	}
	return r;
}
int my_inv(int a) { return my_pow(a, mod - 2); }

const int nax = 1e5 + 5;
char sl[nax];

int val(int i) {
	if(sl[i] == '+') return 1;
	return mod - 1;
}

int main() {
	int n, a, b, k;
	scanf("%d%d%d%d", &n, &a, &b, &k);
	scanf("%s", sl);
	assert((int) strlen(sl) == k);
	int A = my_pow(a, n), B = 1;
	int here = 0;
	const int inv_a = my_inv(a);
	for(int i = 0; i < k; ++i) {
		here = (here + mul(val(i), mul(A, B))) % mod;
		A = mul(A, inv_a);
		B = mul(B, b);
	}
	debug() << imie(here);
	const int mno = my_pow(mul(b, inv_a), k);
	const int times = (n + 1) / k;
	int ple = (1 - my_pow(mno, times)) % mod;
	ple = mul(ple, my_inv(1 - mno));
	int answer = mul(ple, here);
	answer += mod;
	answer %= mod;
	if(mno == 1) {
		printf("%d\n", mul(here, times));
		return 0;
	}
	printf("%d\n", answer);
}