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

typedef bitset<2020> GaussLine;

struct GaussEntry {
	GaussLine ln;
	int pivot;
};

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n, m; cin >> n >> m;
	vector<int> cr(n, 1), cy(n, 2), cb(n, 3);
	vector<GaussEntry> gg;
	
	auto addLine = [&](GaussLine ln) {
		for (const GaussEntry &e : gg) {
			if (ln[e.pivot]) ln ^= e.ln;
		}
		if (ln.none()) return;
		int pivot = ln._Find_first();
		if (pivot == 2*n) {
			cout << "NO\n";
			exit(0);
		}
		for (GaussEntry &e : gg) {
			if (e.ln[pivot]) e.ln ^= ln;
		}
		gg.push_back({ln, pivot});
	};
	
	for (int i = 0; i < m; ++i) {
		string type; cin >> type;
		int x; cin >> x;
		vector<int> a(x);
		for (int j = 0; j < x; ++j) {
			cin >> a[j]; --a[j];
		}
		if (type == "mix") {
			char res; cin >> res;
			int rr = res == 'Y' || res == 'B';
			int ry = res == 'R' || res == 'B';
			if (x & 1) {
				rr ^= 1;
				ry ^= 1;
			}
			{
				GaussLine ln;
				for (int j : a) {
					if (cr[j] == 3) {
						ln[2*j].flip();
						ln[2*j+1].flip();
						rr ^= 1;
					} else {
						ln[2*j+cr[j]-1].flip();
					}
				}
				ln[2*n] = rr;
				addLine(ln);
			}
			{
				GaussLine ln;
				for (int j : a) {
					if (cy[j] == 3) {
						ln[2*j].flip();
						ln[2*j+1].flip();
						ry ^= 1;
					} else {
						ln[2*j+cy[j]-1].flip();
					}
				}
				ln[2*n] = ry;
				addLine(ln);
			}
		} else {
			for (int i : a) {
				if (type == "RY") {
					swap(cr[i], cy[i]);
				} else if (type == "YB") {
					swap(cy[i], cb[i]);
				} else if (type == "RB") {
					swap(cr[i], cb[i]);
				} else {
					assert(false);
				}
			}
		}
	}
	
	cout << "YES\n";
	GaussLine res;
	for (const GaussEntry &e : gg) {
		res[e.pivot] = e.ln[2*n];
	}
	string ans(n, '.');
	for (int i = 0; i < n; ++i) {
		ans[i] = "BRY."[(int)res[2*i] + 2 * (int)res[2*i+1]];
	}
	cout << ans << endl;
	
	return 0;
}