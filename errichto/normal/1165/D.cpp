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

using ll = long long;



void test_case() {
	int n;
	scanf("%d", &n);
	vector<long long> d(n);
	for(int i = 0; i < n; ++i) {
		scanf("%lld", &d[i]);
	}
	sort(d.begin(), d.end());
	// 20 -> 2, 4, 5, 10
	long long maybe = (long long) d[0] * d.back();
	vector<long long> divisors;
	for(int i = 2; (long long) i * i <= maybe; ++i) {
		if(maybe % i == 0) {
			divisors.push_back(i);
			if((long long) i * i != maybe) {
				divisors.push_back(maybe / i);
			}
		}
	}
	sort(divisors.begin(), divisors.end());
	if(divisors == d) {
		printf("%lld\n", maybe);
	}
	else {
		puts("-1");
	}
}

int main() {
    int T;
    scanf("%d", &T);
    for(int nr = 1; nr <= T; ++nr) {
		//~ printf("Case #%d: ", nr);
		test_case();
	}
}