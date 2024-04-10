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
	//~ #define USE_FILE_IO
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

struct Point {
	int x, y, z;
	int idx;
};

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n; cin >> n;
	vector<Point> v(n);
	map< pair<int, int>, vector<Point> > byRow;
	for (int i = 0; i < n; ++i) {
		cin >> v[i].x >> v[i].y >> v[i].z;
		v[i].idx = i+1;
		byRow[{v[i].x, v[i].y}].push_back(v[i]);
	}
	map< int, vector<Point> > byPlane;
	
	auto iterDel = [&](vector<Point> &v) {
		while (v.size() > 1) {
			Point a = v.back(); v.pop_back();
			Point b = v.back(); v.pop_back();
			cout << a.idx << " " << b.idx << "\n";
		}
	};
	
	for (auto &it : byRow) {
		sort(begin(it.second), end(it.second), [&](Point a, Point b) { return a.z < b.z; });
		iterDel(it.second);
		if (!it.second.empty()) {
			byPlane[it.second.back().x].push_back(it.second.back());
		}
	}
	
	vector<Point> byCube;
	for (auto &it : byPlane) {
		sort(begin(it.second), end(it.second), [&](Point a, Point b) { return a.y < b.y; });
		iterDel(it.second);
		if (!it.second.empty()) {
			byCube.push_back(it.second.back());
		}
	}
	
	sort(begin(byCube), end(byCube), [&](Point a, Point b) { return a.x < b.x; });
	iterDel(byCube);
	assert(byCube.empty());
	
	return 0;
}