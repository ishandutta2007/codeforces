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

const int nax = 5005;
const int inf = 1e9 + 5;
int cost[nax], discount[nax], parent[nax];
int always[nax][nax], better[nax][nax];
vector<int> children[nax];
int subtree[nax];

void mini(int & a, int b) { a = min(a, b); }

int main() {
	int n, money;
	scanf("%d%d", &n, &money);
	for(int i = 0; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			always[i][j] = better[i][j] = inf;
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d", &cost[i], &discount[i]);
		if(i != 1) {
			scanf("%d", &parent[i]);
			children[parent[i]].push_back(i);
		}
	}
	for(int i = n; i >= 1; --i) {
		debug() << imie(range(always[i], always[i] + n + 1));
		debug() << imie(range(better[i], better[i] + n + 1));
		subtree[i]++;
		//~ for(int j = 0; j <= subtree[i]; ++j)
			//~ mini(always[i][j], better[i][j]);
		for(int a = subtree[i]; a >= 1; --a)
			better[i][a] = min(inf, better[i][a-1] + cost[i] - discount[i]);
		for(int a = subtree[i]; a >= 1; --a)
			mini(always[i][a], always[i][a-1] + cost[i]);
		for(int j = 0; j <= subtree[i]; ++j)
			mini(better[i][j], always[i][j]);
		debug() << imie(range(always[i], always[i] + n + 1));
		debug() << imie(range(better[i], better[i] + n + 1));
		debug() << "--";
		for(int a = subtree[parent[i]]; a >= 0; --a)
			for(int b = 0; b <= subtree[i]; ++b) {
				mini(always[parent[i]][a+b], always[parent[i]][a] + always[i][b]);
				mini(better[parent[i]][a+b], better[parent[i]][a] + better[i][b]);
			}
		subtree[parent[i]] += subtree[i];
	}
	for(int j = n; j >= 0; --j)
		if(always[1][j] <= money || better[1][j] <= money) {
			printf("%d\n", j);
			return 0;
		}
	assert(false);
}