// This code was written by alex256
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
	int n, t; cin >> n >> t;
	vector< vector<int> > byCnt(n+1);
	multiset<int> now, was;
	vector< pair< pair<int, int>, int> > v;
	int nows = 0;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		byCnt[a].push_back(b);
		was.insert(b);
		v.emplace_back(make_pair(a, b), i+1);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		while (!was.empty() && (int)now.size() < i) {
			now.insert(*was.begin());
			nows += *was.begin();
			was.erase(was.begin());
		}
		if (nows <= t && (int)now.size() == i) {
			ans = i;
		} else {
			break;
		}
		for (int k : byCnt[i]) {
			auto iter = was.find(k);
			if (iter == was.end()) {
				nows -= k;
				now.erase(now.find(k));
				if (!was.empty()) {
					now.insert(*was.begin());
					nows += *was.begin();
					was.erase(was.begin());
				}
			} else {
				was.erase(iter);
			}
		}
		
	}
	cout << ans << endl;
	cout << ans << endl;
	vector< pair<int, int> > q;
	for (int i = 0; i < n; i++) {
		if (v[i].first.first >= ans) {
			q.emplace_back(v[i].first.second, v[i].second);
		}
	}
	sort(q.begin(), q.end());
	for (int i = 0; i < ans; i++) {
		cout << q[i].second << " ";
	}
	cout << endl;
	return 0;
}