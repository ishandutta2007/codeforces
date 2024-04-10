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

vector<int> findLis(const vector<int> &v) {
	int n = v.size();
	vector<int> d(n+1, infinity), p(n+1, -1), pre(n, -1);
	d[0] = -infinity;
	for (int i = 0; i < n; i++) {
		int j = upper_bound(d.begin(), d.end(), v[i]) - d.begin();
		if (d[j-1] < v[i] && v[i] < d[j]) {
			d[j] = v[i];
			p[j] = i;
			pre[i] = p[j-1];
		}
	}
	for (int i = n; i >= 0; i--) {
		if (d[i] != infinity) {
			vector<int> ans;
			int j = p[i];
			while (j >= 0) {
				ans.push_back(v[j]);
				j = pre[j];
			}
			reverse(ans.begin(), ans.end());
			return ans;
		}
	}
	return vector<int>();
}

inline int getVal(vector<int> v) {
	auto q = v;
	reverse(q.begin(), q.end());
	return findLis(v).size() + findLis(q).size();
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	/*for (int n = 1; ; n++) {
		int ans = infinity;
		vector<int> v(n);
		iota(v.begin(), v.end(), 0);
		do {
			auto q = v;
			reverse(q.begin(), q.end());
			int cur = findLis(v).size() + findLis(q).size();
			ans = min(ans, cur);
		} while (next_permutation(v.begin(), v.end()));
		cout << "n = " << n << " ans = " << ans << endl;
	}*/
	/*iota(v.begin(), v.end(), 0);
	do {
		auto q = v;
		reverse(q.begin(), q.end());
		int cur = findLis(v).size() + findLis(q).size();
		if (cur == ans) {
			for (int i = 0; i < n; i++) {
				cout << v[i]+1 << " ";
			}
			cout << endl;
			break;
		}
	} while (next_permutation(v.begin(), v.end()));*/
	int n; cin >> n;
	vector<int> v(n);
	iota(v.begin(), v.end(), 1);
	int sqt = 0;
	while (sqt * sqt <= n) {
		sqt++;
	}
	sqt--;
	for (int i = 0; i < n; i += sqt) {
		int r = min(n, i + sqt);
		reverse(v.begin() + i, v.begin() + r);
	}
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}