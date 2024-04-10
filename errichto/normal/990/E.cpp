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

const long long INF = 1e18L + 5;

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	set<int> allowed;
	for(int i = 0; i < n; ++i) {
		allowed.insert(i);
	}
	for(int i = 0; i < m; ++i) {
		int x;
		scanf("%d", &x);
		allowed.erase(x);
		// blocked[x] = true;
	}
	vector<int> prv_allowed(n + 1);
	for(int pos = 0; pos <= n; ++pos) {
		if(allowed.count(pos)) {
			prv_allowed[pos] = pos;
		}
		else {
			if(pos == 0) {
				prv_allowed[pos] = -1e9;
			}
			else {
				prv_allowed[pos] = prv_allowed[pos-1];
			}
		}
	}
	long long answer = INF;
	allowed.insert(-1e9);
	for(int range = 1; range <= k; ++range) {
		int cost;
		scanf("%d", &cost);
		int nxt = 0;
		int used = 0;
		bool bad = false;
		while(nxt < n) {
			debug() << imie(range) imie(cost) imie(nxt);
			++used;
			// auto it = allowed.upper_bound(nxt);
			// --it;
			// int where = *it;
			int where = prv_allowed[nxt];
			int new_nxt = where + range;
			if(new_nxt <= nxt) {
				bad = true;
				break;
			}
			else {
				nxt = new_nxt;
			}
		}
		if(!bad) {
			answer = min(answer, (long long) used * cost);
		}
	}
	if(answer == INF) {
		answer = -1;
	}
	printf("%lld\n", answer);
	
}