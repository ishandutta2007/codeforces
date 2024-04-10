#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

inline int getInt() {
	int n;
	scanf("%d", &n);
	return n;
}

struct pii {
	int x, y;
};

inline bool operator<(const pii& a, const pii& b) {
	return make_pair(a.x, a.y) < make_pair(b.x, b.y);
}

namespace CompsFinder {
	struct DfsNode {
		void *ret;
		int v, k, i;
	};

	vector< vector<int> > g;
	vector<int> comps;
	vector<char> used;
	stack<DfsNode> stk;
	
	vector<int> find() {
		while (!stk.empty()) {
			stk.pop();
		}
		used.assign(g.size(), false);
		int k = 0;
		for (int i = 0; i < (int)g.size(); i++) {
			if (!used[i]) {
				stk.push({&&globalRet, i, k++, 0});
				
				entry:
				#define return { \
					void* retPoint = stk.top().ret; \
					stk.pop(); \
					goto *retPoint; \
				}
				#define v stk.top().v
				#define k stk.top().k
				#define i stk.top().i
				if (used[v]) {
					return;
				}
				used[v] = true;
				comps[v] = k;
				for (i = 0; i < (int)g[v].size(); i++) {
					stk.push({&&ret, g[v][i], k, 0});
					goto entry;
					ret:
					;
				}
				return;
				#undef v
				#undef k
				#undef i
				#undef return
				
				globalRet:
				;
			}
		}
		return comps;
	}

	void init(const vector< vector<int> > &aG) {
		g = aG;
		comps.resize(g.size());
	}
};

namespace TopSortFinder {
	struct DfsNode {
		void *ret;
		int v, i;
	};

	vector< vector<int> > g;
	vector<char> used;
	vector<int> res;
	stack<DfsNode> stk;

	vector<int> find() {
		while (!stk.empty()) {
			stk.pop();
		}
		res.clear();
		used.assign(g.size(), false);
		for (int i = 0; i < (int)g.size(); i++) {
			if (!used[i]) {
				stk.push({&&globalRet, i, 0});
				
				entry:
				#define return { \
					void* retPoint = stk.top().ret; \
					stk.pop(); \
					goto *retPoint; \
				}
				#define v stk.top().v
				#define i stk.top().i
				if (used[v]) {
					return;
				}
				used[v] = true;
				for (i = 0; i < (int)g[v].size(); i++) {
					stk.push({&&ret, g[v][i], 0});
					goto entry;
					ret: 
					;
				}
				res.push_back(v);
				return;
				#undef v
				#undef i
				#undef return
				
				globalRet:
				;
			}
		}
		reverse(res.begin(), res.end());
		return res;
	}

	void init(const vector< vector<int> > &aG) {
		g = aG;
	}
};


int main() {
	//freopen("compress_table.in", "r", stdin);
	//freopen("compress_table.out", "w", stdout);
	int n = getInt(), m = getInt();
	vector< vector<int> > a(n, vector<int>(m));
	vector< vector<pii> > x(n, vector<pii>(m)), y(m, vector<pii>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = getInt();
			x[i][j] = {a[i][j], j};
			y[j][i] = {a[i][j], i};
		}
	}
	for (int i = 0; i < n; i++) {
		sort(x[i].begin(), x[i].end());
	}
	for (int i = 0; i < m; i++) {
		sort(y[i].begin(), y[i].end());
	}
	vector< vector<int> > g(n * m);
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (x[i][j-1].x == x[i][j].x) {
				int src = i * m + x[i][j-1].y, dst = i * m + x[i][j].y;  
				g[src].push_back(dst);
				g[dst].push_back(src);
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (y[i][j-1].x == y[i][j].x) {
				int src = y[i][j-1].y * m + i, dst = y[i][j].y * m + i;  
				g[src].push_back(dst);
				g[dst].push_back(src);
			}
		}
	}
	CompsFinder::init(g);
	vector<int> comps = CompsFinder::find();
	int compCount = 0;
	for (int i = 0; i < (int)comps.size(); i++) {
		compCount = max(compCount, comps[i] + 1);
	}
	vector< vector<int> > g2(compCount);
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (x[i][j-1].x < x[i][j].x) {
				int src = i * m + x[i][j-1].y, dst = i * m + x[i][j].y;  
				g2[comps[src]].push_back(comps[dst]);
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (y[i][j-1].x < y[i][j].x) {
				int src = y[i][j-1].y * m + i, dst = y[i][j].y * m + i;  
				g2[comps[src]].push_back(comps[dst]);
			}
		}
	}
	TopSortFinder::init(g2);
	vector<int> topSort = TopSortFinder::find();
	vector<int> dp(compCount, 1);
	for (int i = 0; i < compCount; i++) {
		int v = topSort[i];
		for (int j = 0; j < (int)g2[v].size(); j++) {
			int to = g2[v][j];
			dp[to] = max(dp[to], dp[v] + 1);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", dp[comps[i * m + j]]);
		}
		printf("\n");
	}
	return 0;
}