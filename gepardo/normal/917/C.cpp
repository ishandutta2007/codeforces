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

#define int int64_t

const int MAX_VAL = 70;

struct JumpMatrix {
	int64_t a[MAX_VAL][MAX_VAL];
	
	JumpMatrix() {
		for (int i = 0; i < MAX_VAL; i++) {
			for (int j = 0; j < MAX_VAL; j++) {
				a[i][j] = LLONG_MAX;
			}
		}
	}
};

int masks[MAX_VAL];
int deMasks[256];

inline JumpMatrix zero() {
	JumpMatrix res;
	for (int i = 0; i < MAX_VAL; i++) {
		res.a[i][i] = 0;
	}
	return res;
}

inline JumpMatrix merge(JumpMatrix a, JumpMatrix b) {
	JumpMatrix res;
	JumpMatrix bRev;
	for (int i = 0; i < MAX_VAL; i++) {
		for (int j = 0; j < MAX_VAL; j++) {
			bRev.a[i][j] = b.a[j][i];
		}
	}
	for (int i = 0; i < MAX_VAL; i++) {
		for (int j = 0; j < MAX_VAL; j++) {
			for (int k = 0; k < MAX_VAL; k++) {
				if (a.a[i][k] != LLONG_MAX && bRev.a[j][k] != LLONG_MAX) {
					res.a[i][j] = min(res.a[i][j], a.a[i][k] + bRev.a[j][k]);
				}
			}
		}
	}
	return res;
}

inline JumpMatrix genMatrix(int k, vector<int64_t> costs) {
	JumpMatrix res;
	for (int i = 0; i < MAX_VAL; i++) {
		int deI = masks[i];
		if (deI < 0) {
			continue;
		}
		if (deI & 1) {
			for (int j = 0; j < k; j++) {
				if ((deI >> (j+1)) & 1) {
					continue;
				}
				int nVal = (deI >> 1) | (1 << j);
				nVal = deMasks[nVal];
				res.a[i][nVal] = min(res.a[i][nVal], costs[j]);
			}
		} else {
			res.a[i][deMasks[deI >> 1]] = 0;
		}
	}
	return res;
}

inline JumpMatrix binPow(JumpMatrix a, int val) {
	JumpMatrix res = zero();
	while (val) {
		if (val & 1) {
			res = merge(res, a);
		}
		a = merge(a, a);
		val >>= 1;
	}
	return res;
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int x, k, n, q; cin >> x >> k >> n >> q;
	vector<int64_t> c(k);
	for (int i = 0; i < k; i++) {
		cin >> c[i];
	}
	vector< pair<int, int64_t> > s(q);
	for (int i = 0; i < q; i++) {
		cin >> s[i].first >> s[i].second; s[i].first--;
	}
	sort(s.begin(), s.end());
	
	int mc = 0;
	for (int j = 0; j < (1 << k); j++) {
		if (__builtin_popcount(j) == x) {
			deMasks[j] = mc;
			masks[mc++] = j;
		}
	}
	for (int i = mc; i < MAX_VAL; i++) {
		masks[i] = -1;
	}
	
	int minEvt = 0, maxEvt = n - x;
	
	set<int> toProcess;
	toProcess.insert(minEvt);
	toProcess.insert(maxEvt);
	for (int i = 0; i < q; i++) {
		for (int j = s[i].first - k - 2; j <= s[i].first + k + 2; j++) {
			if (minEvt <= j && j <= maxEvt) {
				toProcess.insert(j);
			}
		}
	}
	
	vector<int> v(toProcess.begin(), toProcess.end());
	
	vector<JumpMatrix> simplePows;
	simplePows.push_back(genMatrix(k, c));
	for (int i = 0; i < 29; i++) {
		simplePows.push_back(merge(simplePows.back(), simplePows.back()));
	}
	
	JumpMatrix res = zero();
	for (int i = 1; i < (int)v.size(); i++) {
		if (v[i-1] + 1 == v[i]) {
			vector<int64_t> kost = c;
			for (int j = 0; j < q; j++) {
				int ptr = s[j].first - v[i-1] - 1;
				if (0 <= ptr && ptr < k) {
					kost[ptr] += s[j].second;
				}
			}
			res = merge(res, genMatrix(k, kost));
		} else {
			int dif = (v[i] - v[i-1]);
			for (int j = 0; j < 30; j++) {
				if ((dif >> j) & 1) {
					res = merge(res, simplePows[j]);
				}
			}
		}
	}
	
	int qq = deMasks[(1 << x) - 1];
	cout << res.a[qq][qq] << endl;
	return 0;
}