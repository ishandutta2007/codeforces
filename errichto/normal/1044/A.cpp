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

const int MAX = 1000 * 1000 * 1000;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> piony(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &piony[i]);
	}
	sort(piony.begin(), piony.end());
	vector<pair<int,int>> events;
	int sure = 0;
	for(int i = 0; i < m; ++i) {
		int x1, x2, y;
		scanf("%d%d%d", &x1, &x2, &y);
		if(x1 == 1 && x2 == MAX) {
			++sure;
			continue;
		}
		if(x1 == 1) {
			events.push_back({x2, y});
			++sure;
		}
	}
	sort(events.begin(), events.end());
	int answer = sure;
	debug() << imie(sure);
	int ie = 0;
	int tmp = 0;
	piony.push_back(INT_MAX);
	for(int x : piony) {
		while(ie < (int) events.size() && events[ie].first < x) {
			++ie;
			--tmp;
		}
		answer = min(answer, sure + tmp);
		++tmp;
	}
	printf("%d\n", answer);
}