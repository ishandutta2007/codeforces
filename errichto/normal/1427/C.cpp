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

struct S {
	int time, x, y;
	void read() {
		scanf("%d%d%d", &time, &x, &y);
	}
	int dist(const S& he) const {
		return abs(x - he.x) + abs(y - he.y);
	}
	bool can(const S& he) const {
		return dist(he) <= abs(time - he.time);
	}
};

int main() {
	int r, n;
	scanf("%d%d", &r, &n);
	vector<S> they(n + 1);
	they[0] = S{0, 1, 1};
	for(int i = 1; i <= n; ++i) {
		they[i].read();
	}
	const int INF = 1e9 + 5;
	vector<int> dp(n + 1, -INF);
	dp[0] = 0;
	int answer = 0;
	for(int i = 0; i <= n; ++i) {
		answer = max(answer, dp[i]);
		for(int j = i + 1; j <= min(n, i + 4 * r + 3); ++j) {
			if(they[i].can(they[j])) {
				debug() << imie(i) imie(j);
				dp[j] = max(dp[j], dp[i] + 1);
			}
		}
	}
	debug() << imie(dp);
	printf("%d\n", answer);
}