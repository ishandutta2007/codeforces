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

const int nax = 1e5 + 5;
vector<int> w[nax];
int type[nax];
int dist[105][nax];

int main() {
	int n, m, s, k;
	scanf("%d%d%d%d", &n, &m, &k, &s);
	for(int i = 1; i <= n; ++i) scanf("%d", &type[i]);
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		w[a].push_back(b);
		w[b].push_back(a);
	}
	for(int val = 1; val <= k; ++val) {
		vector<int> kol;
		vector<bool> done(n + 1);
		for(int i = 1; i <= n; ++i) if(type[i] == val) {
			kol.push_back(i);
			done[i] = true;
		}
		for(int i = 0; i < (int) kol.size(); ++i) {
			int a = kol[i];
			for(int b : w[a]) if(!done[b]) {
				done[b] = true;
				kol.push_back(b);
				dist[val][b] = dist[val][a] + 1;
			}
		}
	}
	for(int a = 1; a <= n; ++a) {
		vector<int> they(k);
		for(int i = 1; i <= k; ++i) they[i-1] = dist[i][a];
		debug() << imie(a) imie(they);
		sort(they.begin(), they.end());
		int total = 0;
		for(int i = 0; i < s; ++i) total += they[i];
		printf("%d ", total);
	}
	puts("");
}