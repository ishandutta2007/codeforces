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

const int nax = 5e5 + 5;
vector<pair<int,int>> edges[nax];
vector<pair<int, vector<pair<int,int>>>> queries[nax];
vector<int> memo_edge[nax];
int g[nax];
vector<int> inv[nax];
#define fixed fixed_compile
//~ int fixed[nax];
bool zle[nax];
int fixed_g[nax];
vector<int> fixed_inv[nax];
//~ int tmp_g[nax], tmp_inv[nax];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	
	for(int i = 1; i <= n; ++i) {
		g[i] = fixed_g[i] = i;
		inv[i] = fixed_inv[i] = {i};
	}
	
	for(int i = 0; i < m; ++i) {
		int a, b, cost;
		scanf("%d%d%d", &a, &b, &cost);
		edges[cost].push_back({a, b});
		memo_edge[i] = {a, b, cost};
	}
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; ++i) {
		int cnt;
		scanf("%d", &cnt);
		while(cnt--) {
			int x;
			scanf("%d", &x);
			vector<pair<int, vector<pair<int,int>>>> & they = queries[memo_edge[x-1][2]];
			if(they.empty() || they.back().first != i)
				they.push_back(make_pair(i, vector<pair<int,int>>{}));
			int a = memo_edge[x-1][0], b = memo_edge[x-1][1];
			they.back().second.push_back({a, b});
		}
	}
	
	for(int current = 1; current < nax; ++current) {
		for(const pair<int, vector<pair<int,int>>> & pp : queries[current]) {
			vector<int> touched;
			int iq = pp.first;
			for(pair<int,int> edge : pp.second) {
				int a = fixed_g[edge.first], b = fixed_g[edge.second];
				a = g[a];
				b = g[b];
				if(a == b) {
					zle[iq] = true;
					break;
				}
				touched.push_back(a);
				touched.push_back(b);
				if(inv[a].size() > inv[b].size()) swap(a, b);
				for(int x : inv[a]) {
					inv[b].push_back(x);
					g[x] = b;
				}
				inv[a].clear();
			}
			for(int x : touched) {
				g[x] = x;
				inv[x] = {x};
			}
			touched.clear();
		}
		vector<int> touched;
		for(pair<int,int> edge : edges[current]) {
			int a = fixed_g[edge.first], b = fixed_g[edge.second];
			//~ a = g[a];
			//~ b = g[b];
			if(a == b) continue;
			touched.push_back(a);
			touched.push_back(b);
			if(fixed_inv[a].size() > fixed_inv[b].size()) swap(a, b);
			for(int x : fixed_inv[a]) {
				fixed_g[x] = b;
				fixed_inv[b].push_back(x);
			}
			fixed_inv[a].clear();
		}
		//~ for(int x : touched) {
			
			//~ fixed[x] = g[x];
			//~ if(x == g[x]) {
				//~ inv[x] = {x};
			//~ }
			//~ else inv[x].clear();
		//~ }
	}
	
	for(int i = 0; i < q; ++i) {
		if(zle[i]) puts("NO");
		else puts("YES");
	}
}