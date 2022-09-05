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

const int nax = 1e6 + 5;
int g[nax];
vector<int> inv[nax];
#define pq priority_queue
pq<int> s[nax];

void uni(int a, int b, vector<int>& v) {
	debug() << imie(a) imie(b);
	a = g[a];
	b = g[b];
	if(a == b) {
		return;
	}
	if(inv[a].size() > inv[b].size()) {
		swap(a, b);
	}
	v = inv[a];
	for(int x : inv[a]) {
		g[x] = b;
		inv[b].push_back(x);
	}
	inv[a].clear();
}

int main() {
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	vector<int> value(n + 1);
	vector<int> inv_value(n + 1);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &value[i]);
		inv_value[value[i]] = i;
	}
	vector<pair<int,int>> edges(m + 1);
	for(int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		edges[i] = {a, b};
	}
	vector<bool> removed(m + 1);
	vector<pair<int,int>> queries(q);
	for(pair<int,int>& p : queries) {
		scanf("%d%d", &p.first, &p.second);
		if(p.first == 2) { // delete edge
			removed[p.second] = true;
		}
	}
	for(int i = 1; i <= n; ++i) {
		g[i] = i;
		inv[i] = {i};
	}
	for(int i = 1; i <= m; ++i) {
		if(!removed[i]) {
			vector<int> fake;
			uni(edges[i].first, edges[i].second, fake);
		}
	}
	vector<vector<int>> extract(q);
	debug() << "---";
	for(int i = q - 1; i >= 0; --i) {
		if(queries[i].first == 2) { // delete edge
			int id = queries[i].second;
			int a = edges[id].first;
			int b = edges[id].second;
			uni(a, b, extract[i]);
		}
	}
	for(int a = 1; a <= n; ++a) {
		debug() << imie(a) imie(g[a]) imie(inv[a]);
	}
	for(int a = 1; a <= n; ++a) {
		if(a == g[a]) {
			assert(!inv[a].empty());
			for(int x : inv[a]) {
				s[a].push(value[x]);
			}
		}
	}
	int nxt = n + 1;
	for(int iq = 0; iq < q; ++iq) {
		if(queries[iq].first == 1) { // query
			int a = queries[iq].second;
			a = g[a];
			bool done = false;
			while(!s[a].empty()) {
				int val = s[a].top();
				s[a].pop();
				if(g[inv_value[val]] != a) {
					continue;
				}
				done = true;
				// auto it = s[a].end();
				// --it;
				// int val = *it;
				value[inv_value[val]] = 0;
				// s[a].erase(it);
				printf("%d\n", val);
				break;
			}
			if(!done) {
				puts("0");
			}
		}
		else {
			debug() << imie(extract[iq]);
			int G = nxt++;
			for(int x : extract[iq]) {
				// s[g[x]].erase(value[x]);
				g[x] = G;
				// inv[G].push_back(x);
				if(value[x]) s[G].push(value[x]);
			}
		}
	}
}