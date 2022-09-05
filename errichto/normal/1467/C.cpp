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
	int n[3];
	for(int i = 0; i < 3; ++i) {
		scanf("%d", &n[i]);
	}
	long long lost = LONG_LONG_MAX;
	long long sum = 0;
	vector<int> a[3];
	for(int i = 0; i < 3; ++i) {
		long long sum_bag = 0;
		for(int j = 0; j < n[i]; ++j) {
			int x;
			scanf("%d", &x);
			sum_bag += x;
			a[i].push_back(x);
		}
		sort(a[i].begin(), a[i].end());
		sum += sum_bag;
		lost = min(lost, sum_bag);
	}
	for(int i = 0; i < 3; ++i) {
		lost = min(lost, (long long) a[i][0] + a[(i+1)%3][0]);
	}
	printf("%lld\n", sum - 2 * lost);
}