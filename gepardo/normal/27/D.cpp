#include <vector>
#include <algorithm>
#include <cstdint>
#include <queue>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <functional>
#include <cmath>
#include <random>
#include <chrono>

using namespace std;
using namespace chrono;

const int infinity = 1234567890;
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

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
					res[i] = compId[2*i] > compId[2*i + 1];
				}
			}
			return res;
		}
		
		Calc2SAT(int n)
			: n(n), g(2*n), gRev(2*n), compId(2*n, -1), used(2*n, false) {
		}
};

int main() {
	int n, m; cin >> n >> m;
	vector< pair<int, int> > v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i].first >> v[i].second;
		v[i].first--; v[i].second--;
	}
	Calc2SAT sat(m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < i; j++) {
			const bool mat[2][2] = {
				{0, 1},
				{1, 0}
			};
			int a = v[i].first, b = v[i].second;
			int c = v[j].first, d = v[j].second;
			b -= a; c -= a; d -= a; a = 0;
			b = (b % n + n) % n;
			c = (c % n + n) % n;
			d = (d % n + n) % n;
			if (
				(a < c && c < b && b < d) ||
				(a < d && d < b && b < c)
			) {
				sat.addExpression(i, j, mat);
			}
		}
	}
	auto sol = sat.findSolution();
	if (sol.empty()) {
		cout << "Impossible" << endl;
	} else {
		for (int i = 0; i < m; i++) {
			cout << (sol[i] ? "i" : "o");
		}
		cout << endl;
	}
	return 0;
}