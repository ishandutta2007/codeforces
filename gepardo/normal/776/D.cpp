#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//  2-SAT

class Calc2SAT {
	private:
		int n;
		vector< vector<int> > g;
		vector< vector<int> > gRev;
		vector<int> topSort;
		vector<int> compId;
		vector<char> used;
		
		void dfs1(int v) {
			if (used[v]) {
				return;
			}
			used[v] = true;
			for (int to: g[v]) {
				dfs1(to);
			}
			topSort.push_back(v);
		}
		
		void dfs2(int v, int id) {
			if (compId[v] >= 0) {
				return;
			}
			compId[v] = id;
			for (int to: gRev[v]) {
				dfs2(to, id);
			}
		}
		
		inline void addEdge(int src, int dst) {
			g[src].push_back(dst);
			gRev[dst].push_back(src);
		}
	public:
		inline void addExpression(int a, int b, const bool tab[2][2]) {
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					if (!tab[i][j]) {
						int src = 2*a ^ (!i), dst = 2*b ^ j;
						addEdge(src, dst);
						addEdge(dst^1, src^1);
					}
				}
			}
		}
		
		inline vector<char> findSolution() {
			topSort.clear();
			compId.assign(2*n, -1);
			used.assign(2*n, false);
			for (int i = 0; i < 2*n; i++) {
				dfs1(i);
			}
			reverse(topSort.begin(), topSort.end());
			int cid = 0;
			for (int v: topSort) {
				dfs2(v, cid++);
			}
			vector<char> res(n);
			for (int i = 0; i < n; i++) {
				if (compId[2*i] == compId[2*i + 1]) {
					return {};
				} else {
					res[i] = compId[2*i] < compId[2*i + 1];
				}
			}
			return res;
		}
		
		Calc2SAT(int n)
			: n(n), g(2*n), gRev(2*n), compId(2*n, -1), used(2*n, false) {
		}
};

int main() {
	ios_base::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	vector<int> values(n);
	for (int i = 0; i < n; i++) {
		cin >> values[i];
	}
	vector< vector<int> > whoControls(n);
	for (int i = 0; i < m; i++) {
		int l; cin >> l;
		for (int j = 0; j < l; j++) {
			int val; cin >> val; val--;
			whoControls[val].push_back(i);
		}
	}
	Calc2SAT sat(m);
	for (int i = 0; i < n; i++) {
		int a = whoControls[i][0], b = whoControls[i][1];
		bool tab[2][2] = {{0, 0}, {0, 0}};
		tab[0][!values[i]] = true;
		tab[1][values[i]] = true;
		sat.addExpression(a, b, tab);
	}
	cout << (sat.findSolution().empty() ? "NO" : "YES") << endl;
	return 0;
}