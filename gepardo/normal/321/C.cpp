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

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

struct CentroidDecomposition {
	int n;
	vector< vector<int> > g;
	vector<int> size;
	
	vector<int> level;
	vector< vector<int> > centG;
	vector<int> centIn;
	vector< vector<int> > comps;
	
	inline int addComp(int v, int lvl, int centP) {
		int res = centG.size();
		centG.emplace_back();
		comps.emplace_back();
		comps[res].push_back(v);
		level[v] = lvl;
		centIn[v] = res;
		if (centP >= 0) {
			centG[res].push_back(centP);
			centG[centP].push_back(res);
		}
		return res;
	}
	
	void fillComps(int v = 0, int p = -1) {
		for (int to: centG[v]) {
			if (to != p) {
				fillComps(to, v);
				for (int it: comps[to]) {
					comps[v].push_back(it);
				}
			}
		}
	}
	
	void dfs(int v, int p, int lvl, int centP, int compSz) {
		if (level[v] >= 0) {
			return;
		}
		int maxSize = 0;
		size[v] = 1;
		for (int to: g[v]) {
			if (to != p) {
				dfs(to, v, lvl, centP, compSz);
				if (level[v] >= 0) {
					return;
				}
				if (level[to] < 0) {
					size[v] += size[to];
					maxSize = max(maxSize, size[to]);
				}
			}
		}
		if (p >= 0 && level[p] < 0) {
			maxSize = max(maxSize, compSz - size[v]);
		}
		if (2 * maxSize <= compSz) {
			int centV = addComp(v, lvl, centP);
			for (int to: g[v]) {
				if (to != p) {
					dfs(to, -1, lvl+1, centV, size[to]);
				}
			}
			if (p >= 0) {
				dfs(p, -1, lvl+1, centV, compSz - size[v]);
			}
		}
	}
	
	inline void build() {
		level.assign(n, -1);
		centG.clear();
		comps.clear();
		dfs(0, -1, 0, -1, n);
		fillComps();
	}
	
	CentroidDecomposition(int n)
		: n(n), g(n), size(n), level(n), centIn(n) {
	}
};

int main() {
	int n; cin >> n;
	CentroidDecomposition cd(n);
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b; a--; b--;
		cd.g[a].push_back(b);
		cd.g[b].push_back(a);
	}
	cd.build();
	for (int i = 0; i < n; i++) {
		cout << (char)('A' + cd.level[i]) << " ";
	}
	return 0;
}