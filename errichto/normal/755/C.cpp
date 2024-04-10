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
struct debug{
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
sim dor(const c &) { ris; }
#endif
};
#define imie(x) " [" << #x ": " << (x) << "] "

const int nax = 1e5 + 5;
int g[nax];
vector<int> inv[nax];

void uni(int a, int b) {
	a = g[a];
	b = g[b];
	if(a == b) return;
	if(inv[a].size() > inv[b].size()) swap(a, b);
	for(int x : inv[a]) {
		inv[b].push_back(x);
		g[x] = b;
	}
	inv[a].clear();
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		g[i] = i;
		inv[i].push_back(i);
	}
	for(int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		uni(i, x);
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
		ans += !inv[i].empty();
	printf("%d\n", ans);
}