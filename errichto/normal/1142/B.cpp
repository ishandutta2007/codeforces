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

const int nax = 2e5 + 5;
int inv[nax];
int a[nax];
int nxt[nax];
int up_to[nax];
int down_to[nax];
vector<int> queries[nax];
vector<int> process[nax];
int best[nax];
int answer[nax];
int must[nax];

int main() {
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		inv[x] = i;
	}
	for(int i = 1; i <= m; ++i) {
		int x;
		scanf("%d", &x);
		a[i] = inv[x];
	}
	for(int i = 1; i <= n; ++i) {
		nxt[i] = m + 1;
	}
	up_to[m+1] = m + 1;
	for(int i = m; i >= 1; --i) {
		nxt[a[i]] = i;
		if(a[i] == n) {
			up_to[i] = i;
			continue;
		}
		up_to[i] = up_to[nxt[a[i]+1]];
	}
	
	for(int i = 1; i <= n; ++i) {
		nxt[i] = 0;
	}
	down_to[0] = 0;
	for(int i = 1; i <= m; ++i) {
		nxt[a[i]] = i;
		if(a[i] == 1) {
			down_to[i] = i;
			continue;
		}
		down_to[i] = down_to[nxt[a[i]-1]];
	}
	debug() << imie(range(a + 1, a + m + 1));
	debug() << imie(range(up_to + 1, up_to + m + 1));
	debug() << imie(range(down_to + 1, down_to + m + 1));
	
	for(int i = 1; i <= m; ++i) {
		queries[up_to[i]+1].push_back(i);
	}
	for(int i = 0; i <= n; ++i) {
		best[i] = m + 1;
	}
	for(int i = 0; i <= m; ++i) {
		answer[i] = m + 1;
	}
	for(int i = m; i >= 1; --i) {
		process[down_to[i]].push_back(i);
		for(int j : process[i]) {
			best[a[j]] = min(best[a[j]], j);
		}
		for(int j : queries[i]) {
			answer[j] = best[a[j]-1];
		}
	}
	debug() << imie(range(answer + 1, answer + m + 1));
	must[m+1] = m + 1;
	for(int i = m; i >= 1; --i) {
		must[i] = must[i+1];
		if(a[i] == 1) {
			must[i] = min(must[i], up_to[i]);
		}
		else {
			must[i] = min(must[i], answer[i]);
		}
	}
	debug() << imie(range(must + 1, must + m + 1));
	while(q--) {
		int L, R;
		scanf("%d%d", &L, &R);
		printf(must[L] <= R ? "1" : "0");
	}
	puts("");
}