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
const int mod = module;
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

struct Fenwick {
	int n;
	vector<int64_t> a;
	
	inline void modify(int v, int64_t delta) {
		for (; v < n; v |= v+1) {
			a[v] += delta;
		}
	}
	
	inline int64_t sum(int v) {
		int64_t res = 0;
		for (; v >= 0; v &= v+1, --v) {
			res += a[v];
		}
		return res;
	}
	
	Fenwick(int n)
		: n(n), a(n) {}
};

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n; cin >> n;
	map<int, vector<int> > points;
	map<int, int> active;
	vector<int> act;
	for (int i = 0; i < n; ++i) {
		int x, y; cin >> x >> y;
		points[y].push_back(x);
		++active[x];
		act.push_back(x);
	}
	sort(begin(act), end(act));
	act.erase(unique(begin(act), end(act)), end(act));
	Fenwick f(act.size() + 1);
	for (int i = 1; i <= int(act.size()); ++i) {
		f.modify(i, +1);
	}
	int as = act.size();
	
	auto deactivate = [&](int x) {
		--active[x];
		if (!active[x]) {
			int pos = lower_bound(begin(act), end(act), x) - begin(act);
			f.modify(pos, -1);
			active.erase(x);
		}
	};
	
	auto locate = [&](int x) {
		int pos = lower_bound(begin(act), end(act), x) - begin(act);
		return f.sum(pos);
	};
	
	int64_t ans = 0;
	for (auto &it : points) {\
		sort(begin(it.second), end(it.second));
		int64_t knt = active.size();
		ans += knt * (knt+1) / 2;
		
		auto gap = [&](int id1, int id2) {
			int64_t gap = id2 - id1 - 1;
			ans -= gap * (gap+1) / 2;
		};
		
		gap(-1, locate(it.second[0]));
		for (int i = 1; i < int(it.second.size()); ++i) {
			gap(locate(it.second[i-1]), locate(it.second[i]));
		}
		gap(locate(it.second.back()), f.sum(as));
		
		for (int x : it.second) {
			deactivate(x);
		}
	}
	cout << ans << endl;
	
	return 0;
}