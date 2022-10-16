#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

using namespace std;

int n;
int ans[110000];
vector< vector<int> > g(110000);

int OneCentroid(int root, const vector<vector<int>> &g, const vector<bool> &dead) {
        static vector<int> sz(g.size());
        function<void (int, int)> get_sz = [&](int u, int prev) {
                sz[u] = 1;
                for (auto v : g[u]) if (v != prev && !dead[v]) {
                        get_sz(v, u);
                        sz[u] += sz[v];
                }
        };
        get_sz(root, -1);
        int n = sz[root];
        function<int (int, int)> dfs = [&](int u, int prev) {
                for (auto v : g[u]) if (v != prev && !dead[v]) {
                        if (sz[v] > n / 2) {
                                return dfs(v, u);
                        }
                }
                return u;
        };
        return dfs(root, -1);
}

void CentroidDecomposition(const vector<vector<int>> &g) {
        int n = (int) g.size();
        vector<bool> dead(n, false);
        function<void (int, int)> rec = [&](int start, int level) {
                int c = OneCentroid(start, g, dead);
                ans[c] = level;           
                dead[c] = true;                                
                for (auto u : g[c]) if (!dead[u]) {
                        rec(u, level+1);                                
                }

                dead[c] = false;                              
        };
        rec(0, 0);                                                
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n-1; i++) {
		int a,b;
		scanf("%d %d", &a, &b); a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	CentroidDecomposition(g);
	for (int i = 0; i < n; i++) printf("%c ", 'A'+ans[i]);
}