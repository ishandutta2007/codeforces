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

const int nax = 1e5 + 5;
int t[nax];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int small = 1e9 + 5;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &t[i]);
		small = min(small, t[i]);
	}
	long long answer = 0;
	for(int i = 0; i < n; ++i) {
		int diff = t[i] - small;
		if(diff % k) {
			puts("-1");
			return 0;
		}
		answer += diff / k;
	}
	printf("%lld\n", answer);
}