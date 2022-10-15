// Code written by gepardo
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

inline int s2i(const string &s) {
	int ans = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		ans += (s[i] - '0') << i;
	}
	return ans;
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n, m, q; cin >> n >> m >> q;
	vector<int> w(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	vector<int> knt(1 << n);
	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		knt[s2i(s)]++;
	}
	vector<int> kx(1 << n);
	for (int i = 0; i < (1 << n); i++) {
		for (int k = 0; k < n; k++) {
			if ((i >> k) & 1) {
				continue;
			}
			kx[i] += w[k];
		}
	}
	vector< vector< pair<int, int> > > queries(1 << n);
	for (int i = 0; i < q; i++) {
		string s; cin >> s; int w; cin >> w;
		assert(w <= 100);
		queries[s2i(s)].emplace_back(w, i);
	}
	for (int i = 0; i < (1 << n); i++) {
		sort(queries[i].begin(), queries[i].end());
	}
	vector<int> ans(q);
	for (int i = 0; i < (1 << n); i++) {
		vector<int> ksts(101);
		for (int j = 0; j < (1 << n); j++) {
			int kost = kx[i^j];
			if (kost <= 100) {
				ksts[kost] += knt[j];
			}
		}
		auto &qry = queries[i];
		int p = 0, soom = 0;
		for (int j = 0; j <= 100; j++) {
			soom += ksts[j];
			while (p < (int)qry.size() && qry[p].first == j) {
				ans[qry[p].second] = soom;
				p++;
			}
		}
	}
	for (int i = 0; i < q; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}