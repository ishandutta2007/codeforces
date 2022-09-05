#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
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

typedef long long ll;

void mini(int& a, int b) {
	a = min(a, b);
}
void maxi(int& a, int b) {
	a = max(a, b);
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> x(n), y(n);
	int big_x = INT_MIN;
	int small_x = INT_MAX;
	int big_y = INT_MIN;
	int small_y = INT_MAX;
	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		mini(small_x, x[i]);
		mini(small_y, y[i]);
		maxi(big_x, x[i]);
		maxi(big_y, y[i]);
	}
	int best = 0;
	for(int i = 0; i < n; ++i) {
		maxi(best, big_x - x[i] + big_y - y[i]);
		maxi(best, x[i] - small_x + big_y - y[i]);
		maxi(best, x[i] - small_x + y[i] - small_y);
		maxi(best, big_x - x[i] + y[i] - small_y);
	}
	printf("%d ", 2 * best);
	for(int i = 4; i <= n; ++i) {
		printf("%d ", 2 * (big_x - small_x + big_y - small_y));
	}
	puts("");
}