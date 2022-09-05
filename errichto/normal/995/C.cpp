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

ll K(ll x) { return x * x; }

const ll M = K(1000 * 1000);

struct P {
	int x, y;
	ll dist2() const {
		return K(x) + K(y);
	}
	P operator + (const P & he) const {
		return P{x + he.x, y + he.y};
	}
	P operator - (const P & he) const {
		return P{x - he.x, y - he.y};
	}
	P operator - () const {
		return P{-x, -y};
	}
	void read() {
		scanf("%d%d", &x, &y);
	}
};

debug & operator << (debug & dd, P p) {
	dd << "(" << p.x << ", " << p.y << ") ";
	return dd;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<P> in(n);
	for(P & p : in) p.read();
	vector<int> ans(n, 1);
	if(n == 1) {
		puts("1");
		return 0;
	}
	int b = 1;
	vector<int> with_b;
	for(int c = 2; c < n; ++c) {
		if((in[0] + in[c]).dist2() <= M) {
			in[0] = in[0] + in[c];
			continue;
		}
		if((in[0] - in[c]).dist2() <= M) {
			in[0] = in[0] - in[c];
			ans[c] = -1;
			continue;
		}
		if((in[b] + in[c]).dist2() <= M) {
			in[b] = in[b] + in[c];
			with_b.push_back(c);
			continue;
		}
		if((in[b] - in[c]).dist2() <= M) {
			in[b] = in[b] - in[c];
			with_b.push_back(c);
			ans[c] = -1;
			continue;
		}
		if((in[0] + in[b]).dist2() <= M) {
			in[0] = in[0] + in[b];
			with_b.clear();
			b = c;
			continue;
		}
		if((in[0] - in[b]).dist2() <= M) {
			in[0] = in[0] - in[b];
			for(int x : with_b) ans[x] *= -1;
			assert(ans[b] == 1);
			ans[b] = -1;
			with_b.clear();
			b = c;
			continue;
		}
		debug() << imie(c) << in[0] << in[b] << in[c];
		assert(false);
	}
	with_b.push_back(b);
	if((in[0] + in[b]).dist2() <= K(1500 * 1000)) { }
	else if((in[0] - in[b]).dist2() <= K(1500 * 1000)) {
		for(int x : with_b) ans[x] *= -1;
	}
	else assert(false);
	for(int x : ans) printf("%d ", x);
	puts("");
}