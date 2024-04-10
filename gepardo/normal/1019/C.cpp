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

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n, m; cin >> n >> m;
	vector< vector<int> > g(n), gr(n);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		gr[b].push_back(a);
	}
	vector<char> used(n, false);
	vector<int> val(n, 1);
	vector<int> cand;
	int ptr = 0;
	for (;;) {
		while (ptr < n && used[ptr]) {
			ptr++;
		}
		if (ptr == n) {
			break;
		}
		cand.push_back(ptr);
		used[ptr] = true;
		for (int i: g[ptr]) {
			if (!used[i]) {
				used[i] = true;
				val[i] = 0;
			}
		}
	}
	reverse(cand.begin(), cand.end());
	for (int i: cand) {
		for (int j: gr[i]) {
			val[i] &= !val[j];
		}
	}
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (val[i]) {
			ans.push_back(i);
		}
	}
	cout << ans.size() << endl;
	for (int i: ans) {
		cout << i+1 << " ";
	}
	cout << endl;
	return 0;
}