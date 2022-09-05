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

typedef long long ll;

struct P {
	ll a, b;
	bool operator < (P he) {
		//return a / b < he.a / he.b;
		return a * he.b < b * he.a;
	}
};
P min(P a, P b) { return a < b ? a : b; }
P max(P a, P b) { return a < b ? b : a; }

P low{0, 1};
P high{1000 * 1000, 1};

void NO() {
	puts("-1");
	exit(0);
}

void consider(int x1, int x2, int x, int vx) {
	if(vx == 0 && (x == x1 || x == x2)) NO();
	if(vx <= 0 && x <= x1) NO();
	if(vx >= 0 && x >= x2) NO();
	if(vx == 0) return;
	if(vx > 0) {
		if(x < x1) low = max(low, P{x1 - x, vx});
		assert(x < x2);
		high = min(high, P{x2 - x, vx});
	}
	if(vx < 0) {
		if(x > x2) low = max(low, P{x - x2, -vx});
		assert(x > x1);
		high = min(high, P{x - x1, -vx});
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int x1, y1, x2, y2;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	while(n--) {
		int x, y, vx, vy;
		scanf("%d%d%d%d", &x, &y, &vx, &vy);
		consider(x1, x2, x, vx);
		consider(y1, y2, y, vy);
	}
	if(low < high) printf("%.10lf\n", (double) low.a / low.b);
	else NO();
}