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

#define div div2

const int mod = 1e9 + 7;
int mul(int a, int b) { return (long long) a * b % mod; }
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
int div(int a, int b) { return mul(a, my_inv(b)); }

const int nax = 1005;
int dp[nax][nax];

int add(int a, int b) {
	a += b;
	if(a >= mod) a -= mod;
	return a;
}
void add_self(int & a, int b) { a = add(a, b); }
int sub(int a, int b) {
	a -= b;
	if(a < 0) a += mod;
	return a;
}

int main() {
	//~ debug() << imie(div(3, 4));
	int k, inA, inB;
	cin >> k >> inA >> inB;
	const int pA = div(inA, inA + inB);
	const int pB = div(inB, inA + inB);
	assert(add(pA, pB) == 1);
	dp[1][0] = 1;
	int answer = 0;
	for(int A = 1; A <= k; ++A) {
		for(int X = 0; X < k; ++X) {
			int me = dp[A][X];
			if(me == 0) continue;
			debug() << imie(A) imie(X) imie(dp[A][X]);
			int at_least = 0;
			
			if(A == k) {
				add_self(answer, mul(me, X + k));
				int anti = sub(1, pA);
				add_self(answer, mul(me, mul(pB, div(pA, mul(anti, anti)))));
				continue;
			}
			
			int tmp = pA;
			int j;
			for(j = X; j < k; j += A) {
				add_self(dp[A+1][j], mul(me, tmp));
				tmp = mul(tmp, pB);
				++at_least;
			}
			// at_least = 3
			
			add_self(answer, mul(me, mul(j, my_pow(pB, at_least))));
			
			//~ int powik = my_pow(pB, at_least);
			//~ int anti = sub(1, pB);
			
			//~ int one = div( mul(X, powik), anti);
			//~ int two = div(A, anti);
			//~ two = mul(two, add(mul(at_least, powik), div(mul(powik, pB), anti)));
			//~ add_self(answer, mul(me, mul(pA, add(one, two))));
		}
	}
	printf("%d\n", answer);
}