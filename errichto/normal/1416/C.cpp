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

const int nax = 300123 * 31;
int child[nax][2];
int nxt = 1;
int cnt[nax];
long long inv[31][2];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		int node = 0;
		for(int pos = 29; pos >= 0; --pos) {
			bool bit = bool(x & (1 << pos));
			// inv[pos][0] += cnt[child[node][bit]];
			inv[pos][bit] += cnt[child[node][!bit]];
			if(child[node][bit] == 0) {
				child[node][bit] = nxt++;
			}
			node = child[node][bit];
			cnt[node]++;
		}
	}
	long long answer = 0;
	long long x = 0;
	for(int pos = 0; pos < 30; ++pos) {
		if(inv[pos][0] > 0 && inv[pos][1] > 0) {
			debug() << imie(pos) imie(inv[pos][0]) imie(inv[pos][1]);
		}
		if(inv[pos][0] > inv[pos][1]) {
			x ^= (1 << pos);
		}
		answer += min(inv[pos][0], inv[pos][1]);
	}
	printf("%lld %lld\n", answer, x);
}