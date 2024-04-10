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
	#define LOCAL_INPUT_FILE
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
	
	int n, s; cin >> n >> s;
	vector<int> v(n);
	map<int, int> kompr;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		kompr[v[i]] = 42;
	}
	int k = 0;
	for (auto &it: kompr) {
		it.second = k++;
	}
	for (int i = 0; i < n; i++) {
		v[i] = kompr[v[i]];
	}
	auto w = v;
	sort(w.begin(), w.end());
	
	vector< vector<int> > g(k);
	map< pair<int, int>, vector<int> > indices;
	for (int i = 0; i < n; i++) {
		if (w[i] == v[i]) {
			continue;
		}
		s--;
		g[w[i]].push_back(v[i]);
		indices[{w[i], v[i]}].push_back(i);
	}
	
	if (s < 0) {
		cout << -1 << "\n";
		return 0;
	}
	
	vector<int> pass;
	function<void(int)> dfs = [&](int v) {
		while (!g[v].empty()) {
			int to = g[v].back();
			g[v].pop_back();
			dfs(to);
		}
		pass.push_back(v);
	};
	
	vector< vector<int> > ans;
	for (int i = 0; i < k; i++) {
		if (g[i].empty()) {
			continue;
		}
		pass.clear();
		dfs(i);
		ans.emplace_back();
		for (int j = 1; j < (int)pass.size(); j++) {
			auto &vec = indices[{pass[j], pass[j-1]}];
			assert(!vec.empty());
			ans.back().push_back(vec.back());
			vec.pop_back();
		}
		reverse(ans.back().begin(), ans.back().end());
	}
	
	int canUnite = min(s, (int)ans.size());
	if (canUnite > 2) {
		vector<int> united;
		vector<int> loop2;
		for (int i = 0; i < canUnite; i++) {
			united.insert(united.end(), ans.back().begin(), ans.back().end());
			loop2.push_back(ans.back()[0]);
			ans.pop_back();
		}
		ans.push_back(united);
		reverse(loop2.begin(), loop2.end());
		ans.push_back(loop2);
	}
	
	cout << ans.size() << "\n";
	for (auto vec: ans) {
		cout << vec.size() << "\n";
		for (auto it: vec) {
			cout << it+1 << " ";
		}
		cout << "\n";
	}
	
	return 0;
}