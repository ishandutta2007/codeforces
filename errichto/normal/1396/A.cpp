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



int main() {
	int n;
	scanf("%d", &n);
	vector<long long> a(n + 1);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	if(n == 1) {
		for(int rep = 0; rep < 3; ++rep) {
			puts("1 1");
			if(rep == 0) {
				printf("%lld\n", -a[1]);
			}
			else {
				puts("0");
			}
		}
		return 0;
	}
	printf("%d %d\n", 2, n);
	for(int i = 2; i <= n; ++i) {
		int tmp = (a[i] % n + n) % n;
		long long add = tmp * (long long) (n - 1);
		a[i] += add;
		printf("%lld ", add);
		assert(a[i] % n == 0);
	}
	printf("%d %d\n", 1, n);
	for(int i = 1; i <= n; ++i) {
		if(i == 1) {
			printf("0 ");
		}
		else {
			printf("%lld ", -a[i]);
		}
	}
	puts("1 1");
	printf("%lld\n", -a[1]);
}