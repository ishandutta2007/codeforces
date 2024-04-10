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

// n = 5
// a[1] = 1*r[1]
// a[2] = 1*r[1] + 1*r[2]
// a[3] = 2*r[1] + 1*r[2] + 1*r[3]
// a[4] = 4*r[1] + 2*r[2] + 1*r[3] + 1*r[4]
// a[5] = 8*r[1] + 4*r[2] + 2*r[3] + 1*r[4] + 1*r[5]
// a[5] = 8*(r[1]+1), then r[i] in [0, M-1]
// A = r[1]
// B = a[n]

void test_case() {
	long long A, B, M;
	scanf("%lld%lld%lld", &A, &B, &M);
	if(A == B) {
		printf("1 %lld\n", A);
		return;
	}
	for(int n = 2; n <= 50; ++n) {
		vector<long long> answer{A};
		long long pref_sum = A;
		long long already = (A + 1) << (n - 2);
		if(already > B) {
			break;
		}
		long long remaining = B - already;
		for(int i = 2; i <= n; ++i) {
			long long p_two = 1LL <<
				max(0, n - i - 1);
			long long times = min(remaining / p_two, M - 1);
			remaining -= times * p_two;
			
			long long new_value = pref_sum + times + 1;
			answer.push_back(new_value);
			pref_sum += new_value;
		}
		if(remaining == 0) {
			printf("%d", n);
			for(long long x : answer) {
				printf(" %lld", x);
			}
			puts("");
			return;
		}
	}
	puts("-1");
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}