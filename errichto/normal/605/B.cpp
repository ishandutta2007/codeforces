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

const int nax = 1e5 + 5;
pair<int,int> ans[nax];

struct E {
	int cost, type, id;
	bool operator <(const E& he) const {
		return make_pair(cost, -type) < make_pair(he.cost, -he.type);
	}
	void choose(int a, int b) {
		ans[id] = {a, b};
	}
};

void check(bool x) {
	if(!x) {
		puts("-1");
		exit(0);
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<E> edges;
	for(int id = 0; id < m; ++id) {
		int cost, type;
		scanf("%d%d", &cost, &type);
		edges.push_back(E{cost, type, id});
	}
	sort(edges.begin(), edges.end());
	check(edges[0].type == 1);
	edges[0].choose(1, 2);
	int nxt = 3;
	int j = 3, k = 2;
	for(int i = 1; i < (int) edges.size(); ++i) {
		debug() << imie(i);
		if(edges[i].type == 1) {
			edges[i].choose(1, nxt);
			nxt++;
		}
		else {
			debug() << imie(i) imie(j) imie(k);
			check(j < nxt);
			edges[i].choose(j, k);
			k++;
			if(j == k) {
				j++;
				k = 2;
			}
		}
	}
	for(int i = 0; i < m; ++i) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
}