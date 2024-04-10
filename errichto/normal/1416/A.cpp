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

void test_case() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	vector<vector<int>> where(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		a[i]--;
		where[a[i]].push_back(i);
	}
	vector<int> ans(n + 1, -1);
	int nxt = n;
	for(int val = 0; val < n; ++val) {
		int dist = -1;
		int prv = -1;
		where[val].push_back(n);
		for(int pos : where[val]) {
			dist = max(dist, pos - prv);
			prv = pos;
		}
		while(dist <= nxt && nxt >= 1) {
			ans[nxt] = val + 1;
			nxt--;
		}
		debug() << imie(val) imie(dist);
	}
	for(int i = 1; i <= n; ++i) {
		printf("%d ", ans[i]);
	}
	puts("");
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}