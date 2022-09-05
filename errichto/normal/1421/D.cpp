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
	long long x, y;
	scanf("%lld%lld", &x, &y);
	long long c[7];
	for(int i = 1; i <= 6; ++i) {
		scanf("%lld", &c[i]);
	}
	auto green_cost = [&](long long a) {
		if(a >= 0) {
			return a * c[6];
		}
		return -a * c[3];
	};
	auto red_cost = [&](long long a) {
		if(a >= 0) {
			return a * c[2];
		}
		return -a * c[5];
	};
	auto blue_cost = [&](long long a) {
		if(a >= 0) {
			return a * c[1];
		}
		return -a * c[4];
	};
	
	long long red_green = green_cost(x) + red_cost(y);
	long long red_blue = blue_cost(x) + red_cost(y - x);
	long long green_blue = blue_cost(y) + green_cost(x - y);
	printf("%lld\n", min({red_green, red_blue, green_blue}));
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}