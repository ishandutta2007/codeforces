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

bool check(long long n, long long k) {
	if(k < 2) {
		return false;
	}
	//~ if(k > 3 * sqrt(n) + 1) {
		//~ return false;
	//~ }
	__int128 tmp = (__int128) k * (k - 1) / 2;
	if(tmp >= n) {
		return false;
	}
	return ((n - tmp) % k == 0);
}

void test_case(long long n) {
	//~ for(int k = 2; k <= n; ++k) {
		//~ if(check(n, k)) {
			//~ printf("%d\n", k);
			//~ return;
		//~ }
	//~ }
	for(long long k = 2; k <= n + 1; k *= 2) {
		if(n % k == 0) {
			long long x = n / k;
			if(x >= 2 && check(n, x)) {
				printf("%lld\n", x);
				return;
			}
		}
		for(int x : {k-1, k, k+1}) {
			if(x >= 2) {
				if(check(n, k)) {
					printf("%lld\n", k);
					return;
				}
			}
		}
	}
	assert(__builtin_popcountll(n) == 1);
	puts("-1");
}

int main() {
	//~ for(int n = 2; n <= 50123123; n++) {
		//~ printf("%d: ", n);
		//~ test_case(n);
	//~ }
	int T;
	scanf("%d", &T);
	while(T--) {
		long long n;
		scanf("%lld", &n);
		test_case(n);
	}
}