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
 
const int MAX_N = 5e5 + 5;
vector<pair<int,int>> edges[MAX_N];
bool visited[MAX_N];
pair<int,int> parent[MAX_N];
int depth[MAX_N];
// vector<vector<int>> cycles;
vector<int> smallest;
 
vector<int> find_path(int a, int b) {
	assert(visited[a] && visited[b]);
	vector<int> left, right;
	while(a != b) {
		if(depth[a] > depth[b]) {
			left.push_back(parent[a].second);
			a = parent[a].first;
		}
		else {
			right.push_back(parent[b].second);
			b = parent[b].first;
		}
	}
	reverse(right.begin(), right.end());
	for(int x : right) {
		left.push_back(x);
	}
	return left;
}
 
void dfs(int a) {
	assert(!visited[a]);
	visited[a] = true;
	for(pair<int,int> e : edges[a]) {
		int b = e.first;
		int id = e.second;
		if(b == parent[a].first) {
			continue;
		}
		if(!visited[b]) {
			depth[b] = depth[a] + 1;
			parent[b] = {a, id};
			dfs(b);
		}
		else {
			// cycle
			vector<int> cycle = find_path(a, b);
			cycle.push_back(id);
			// 4 3 1 9 8 5
			// 5 8 9 1 3 4
			int s = cycle.size();
			assert(s >= 3);
			debug() << imie(a) imie(b) imie(cycle);
			int ws = 0, wb = 0;
			for(int i = 0; i < s; ++i) {
				if(cycle[i] < cycle[ws]) {
					ws = i;
				}
				if(cycle[i] > cycle[wb]) {
					wb = i;
				}
			}
			bool ok = true;
			for(int i = ws; i != wb; i = (i + 1) % s) {
				if(cycle[i] > cycle[(i+1)%s]) {
					ok = false;
				}
			}
			for(int i = wb; i != ws; i = (i + 1) % s) {
				if(cycle[i] < cycle[(i+1)%s]) {
					ok = false;
				}
			}
			if(ok) {
				smallest[cycle[wb]] = cycle[ws];
			}
			// for(int rep = 0; rep < 2; ++rep) {
				// int last_big = -1;
				// for(int i = 0; i < s; ++i) {
					// if(cycle[i] > cycle[(i+1)%s]) {
						// if(last_big != -1) {
							// last_big = -2;
							// break;
						// }
						// last_big = i;
					// }
				// }
				// if(last_big != -2) {
					// 5 8 9 1 3 4
					// smallest[abs(cycle[last_big])] = abs(cycle[(last_big+1)%s]);
				// }
				// for(int& x : cycle) {
					// x *= -1;
				// }
			// }
		}
	}
}
 
int main() {
    cerr << "123" << endl;
	// CF #609, div1-E, Happy Cactus   https://codeforces.com/contest/1268/problem/E
	int n, m;
	scanf("%d%d", &n, &m);
	smallest.resize(m, -1);
	vector<pair<int,int>> order(m);
	for(int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		int j = m - 1 - i; // I reversed the order of edges!!!
		edges[a].emplace_back(b, j);
		edges[b].emplace_back(a, j);
		order[j] = {a, b};
	}
	dfs(0);
	vector<int> sum(n, 1);
	vector<int> memo(m);
	for(int id = 0; id < m; ++id) {
		int a = order[id].first;
		int b = order[id].second;
		int together = sum[a] + sum[b];
		if(smallest[id] != -1) {
			together -= memo[smallest[id]];
		}
		memo[id] = together;
		sum[a] = sum[b] = together;
	}
	for(int x : sum) {
		printf("%d ", x - 1);
	}
	puts("");
	// a, b
	// not connected -> parent[a] = b
	// connected -> ?
}