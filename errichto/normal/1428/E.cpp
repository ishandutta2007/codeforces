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

long long value(int len, int parts) {
	int len1 = len / parts;
	int len2 = len1 + 1;
	int cnt2 = len % parts;
	int cnt1 = parts - cnt2;
	return (long long) cnt1 * len1 * len1 + (long long) cnt2 * len2 * len2;
}

struct S {
	int len, parts;
	long long impr() const {
		return value(len, parts) - value(len, parts + 1);
	}
	bool operator <(const S& he) const {
		return impr() > he.impr();
	}
};

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	multiset<S> all;
	for(int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		all.insert(S{x, 1});
	}
	for(int rep = 0; rep < k - n; ++rep) {
		S s = *all.begin();
		all.erase(all.begin());
		all.insert(S{s.len, s.parts + 1});
		// for(S s : all) cerr << s.len << "," << s.parts << " ";
		// cerr << endl;
	}
	long long answer = 0;
	for(S s : all) {
		answer += value(s.len, s.parts);
	}
	printf("%lld\n", answer);
}