#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e; };
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

const int inf = 1e9 + 5;
const int nax = 82;
int memo[nax][nax][nax][2];
int edge[nax][nax];
void mini(int & a, int b) { a = min(a, b); }

int rec(int a, int b, int k, bool is_left) {
	if(a > b) return inf;
	if(k == 1) return 0;
	int & me = memo[a][b][k][is_left];
	if(me) return me;
	me = inf;
	if(is_left) {
		for(int i = a + 1; i <= b; ++i) {
			mini(me, edge[a][i] + rec(i, b, k - 1, true));
			mini(me, edge[a][i] + rec(a + 1, i, k - 1, false));
		}
	}
	else {
		for(int i = a; i < b; ++i) {
			mini(me, edge[b][i] + rec(i, b - 1, k - 1, true));
			mini(me, edge[b][i] + rec(a, i, k - 1, false));
		}
	}
	return me;
}

int main() {
	int n, k, m;
	scanf("%d%d%d", &n, &k, &m);
	for(int i = 0; i <= n + 1; ++i)
		for(int j = 0; j <= n + 1; ++j)
			edge[i][j] = inf;
	while(m--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		mini(edge[a][b], c);
		//mini(edge[b][a], c);
	}
	for(int i = 1; i <= n; ++i)
		edge[0][i] = edge[i][0] = 0;
	int ans = rec(0, n, k + 1, true);
	if(ans >= inf) puts("-1");
	else printf("%d\n", ans);
}