#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <sstream>
#include <tuple>
#include <vector>

using namespace std;
using namespace chrono;

#ifdef DEBUG
	//#define LOCAL_INPUT_FILE
#else
	//#define USE_FILE_IO
#endif

#ifdef USE_FILE_IO
	#define INPUT_FILE "input.txt"
	#define OUTPUT_FILE "output.txt"
	#define cin ____cin
	#define cout ____cout
	ifstream cin(INPUT_FILE);
	ofstream cout(OUTPUT_FILE);
#else
	#ifdef LOCAL_INPUT_FILE
		#define cin ____cin
		ifstream cin("input.txt");
	#endif
#endif

const int infinity = (int)1e9 + 42;
const int64_t llInfinity = (int64_t)1e18 + 256;
const int module = (int)1e9 + 7; 
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n, m; cin >> n >> m;
	vector< vector<int> > g(n);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	vector<int> d(n, INT_MAX);
	vector<int> p(n, -1);
	queue<int> q;
	q.push(0);
	d[0] = 0;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int to: g[v]) {
			if (d[to] == INT_MAX) {
				d[to] = d[v] + 1;
				p[to] = v;
				q.push(to);
			}
		}
	}
	int ans1 = d[n-1];
	
	int idx2 = -1;
	for (int i = 0; i < n; i++) {
		if (d[i] == 2) {
			idx2 = i;
			break;
		}
	}
	
	if (ans1 > 4 && idx2 >= 0) {
		cout << 4 << endl;
		cout << 1 << " " << p[idx2]+1 << " " << idx2+1 << " " << 1 << " " << n << endl;
		return 0;
	}
	
	if (ans1 > 5) {
		vector<char> used(n, false);
		vector< vector<int> > komps;
		vector<int> kompId(n, -1);
		
		used[0] = true;
		
		function<void(int)> dfs = [&](int v) {
			if (used[v]) {
				return;
			}
			used[v] = true;
			kompId[v] = (int)komps.size() - 1;
			komps.back().push_back(v);
			for (int to: g[v]) {
				dfs(to);
			}
		};
		
		for (int i: g[0]) {
			if (!used[i]) {
				komps.emplace_back();
				dfs(i);
			}
		}
		
		for (int i = 0; i < n; i++) {
			sort(g[i].begin(), g[i].end());
		}
		
		for (auto &komp: komps) {
			sort(komp.begin(), komp.end());
			bool klika = true;
			int ngsz = (int)komp.size();
			int x = -1, y = -1;
			for (int i: komp) {
				if ((int)g[i].size() == ngsz) {
					continue;
				}
				for (int j: komp) {
					if (i == j) {
						continue;
					}
					if (!binary_search(g[i].begin(), g[i].end(), j)) {
						x = i; y = j;
						break;
					}
				}
				if (x < 0 || y < 0) {
					for (;;);
				}
				klika = false;
				break;
			}
			if (klika) {
				continue;
			}
			int z = -1;
			vector<int> xReach;
			for (int i = 1; i < n; i++) {
				if (i == x || i == y) {
					continue;
				}
				bool findX = binary_search(g[i].begin(), g[i].end(), x);
				bool findY = binary_search(g[i].begin(), g[i].end(), y);
				if (findX && findY) {
					z = i;
					break;
				} else if (findX) {
					xReach.push_back(i);
				}
			}
			if (z < 0) {
				z = -1;
				for (int i: xReach) {
					for (int j: g[i]) {
						if (
							j == x || j == 0 ||
							binary_search(xReach.begin(), xReach.end(), j)
						) {
							continue;
						}
						y = j; z = i;
						break;
					}
					if (z >= 0) {
						break;
					}
				}
				assert(z >= 0);
			}
			cout << 5 << endl;
			cout << 1 << " " << x+1 << " " << z+1 << " " << y+1 << " " << x+1 << " " << n << endl;
			return 0;
		}
	}
	
	if (ans1 == INT_MAX) {
		cout << -1 << endl;
		return 0;
	}
	cout << ans1 << endl;
	vector<int> res;
	int kur = n-1;
	while (kur >= 0) {
		res.push_back(kur+1);
		kur = p[kur];
	}
	reverse(res.begin(), res.end());
	for (int i: res) {
		cout << i << " ";
	}
	cout << endl;
	
	return 0;
}