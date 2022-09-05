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

using ll = long long;

// N=5
// {1, 2, 3} -> lcm(a[1], a[2], a[3]) > lcm(a[4], a[5])

// {1, 2}, {1, 3}, {2, 4, 3}

const int MAX_N = 10123;
bitset<MAX_N> b[51];

int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	for(int i = 0; i < m; ++i) {
		int k;
		scanf("%d", &k);
		for(int j = 0; j < k; ++j) {
			int x;
			scanf("%d", &x);
			b[i][x] = 1;
		}
	}
	for(int i = 0; i < m; ++i) {
		for(int j = i + 1; j < m; ++j) {
			debug() << imie(i) imie(j) imie(b[i]) imie(b[j]);
			if((b[i] & b[j]) == 0) {
				puts("impossible");
				return 0;
			}
		}
	}
	puts("possible");
}