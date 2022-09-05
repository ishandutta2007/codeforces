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
	vector<pair<int,int>> events;
	for(int i = 0; i < n; ++i) {
		int a, c;
		scanf("%d%d", &a, &c);
		c += a;
		events.emplace_back(a, +1);
		events.emplace_back(c, -1);
	}
	sort(events.begin(), events.end());
	int balance = 0;
	long long answer = 0;
	int prev_x = -1;
	for(pair<int,int> event : events) {
		int x = event.first;
		if(prev_x != -1) {
			answer += (long long) max(balance, 1) * (x - prev_x);
		}
		prev_x = x;
		balance += event.second;
	}
	printf("%lld\n", answer);
}

// c[i] := c[i] + a[i]
// a[i] <= c[i]

// i -> j
// sum over max(c[i] - a[j], 0)

// c[i] = 20
// a[j] = 15
// a[j2] = 27