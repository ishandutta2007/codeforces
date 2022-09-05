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
	int integers = 0;
	double init_sum = 0;
	int floored_sum = 0; // X
	for(int i = 0; i < 2 * n; ++i) {
		double x;
		scanf("%lf", &x);
		init_sum += x;
		if(abs(x - llround(x)) <= 1e-9) {
			integers++;
			floored_sum += llround(x);
		}
		else {
			floored_sum += llround(floor(x));
		}
	}
	int reals = 2 * n - integers;
	int at_least = max(0, n - integers);
	int at_most = min(n, reals);
	int low = floored_sum + at_least;
	int high = floored_sum + at_most;
	double ans = 1e15;
	if(init_sum < low) {
		ans = low - init_sum;
	}
	else if(high < init_sum) {
		ans = init_sum - high;
	}
	else {
		ans = min(init_sum - floor(init_sum), ceil(init_sum) - init_sum);
	}
	// for(int x = low; x <= high; ++x) {
		// ans = min(ans, abs(x - init_sum));
	// }
	printf("%.3lf\n", ans);
}