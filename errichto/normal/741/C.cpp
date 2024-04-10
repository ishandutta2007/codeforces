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

const int nax = 2e5 + 5;
pair<int,int> p[nax];
int inv[nax], ans[nax];

void dfs(int a) {
	for(int b : {inv[a], ((a-1)^1)+1})
		if(!ans[b]) {
			ans[b] = 3 - ans[a];
			dfs(b);
		}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		p[i] = {a, b};
		inv[a] = b;
		inv[b] = a;
	}
	for(int i = 1; i <= 2 * n; ++i) if(!ans[i]) {
		ans[i] = 1;
		dfs(i);
	}
	for(int i = 1; i <= n; ++i)
		printf("%d %d\n", ans[p[i].first], ans[p[i].second]);
}