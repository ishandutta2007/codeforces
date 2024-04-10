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

// map<pair<int,int>, long long> m;

long long value(int a, int x) {
	if(a % x != 0) {
		return a;
	}
	// auto it = m.find(make_pair(a, x));
	// if(it != m.end()) {
		// return it->second;
	// }
	return a + x * value(a / x, x);
}

void test_case() {
	int n, x;
	scanf("%d%d", &n, &x);
	vector<pair<int,int>> a(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i].first);
		a[i].second = 1;
	}
	for(int i = 0; i < (int) a.size(); ++i) {
		if(a[i].first % x != 0) {
			break;
		}
		a.push_back(make_pair(a[i].first / x, a[i].second * x));
	}
	long long answer = 0;
	for(pair<int,int> p : a) {
		answer += (long long) p.first * p.second;
	}
	printf("%lld\n", answer);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}