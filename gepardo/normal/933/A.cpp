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
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<int> p1(n), p2(n), s1(n), s2(n);
	p1[0] = v[0] == 1;
	p2[0] = 1;
	s2[n-1] = v[n-1] == 2;
	s1[n-1] = 1;
	for (int i = 1; i < n; i++) {
		p1[i] = p1[i-1] + (v[i] == 1);
		p2[i] = max(p1[i], p2[i-1] + (v[i] == 2));
	}
	for (int i = n-2; i >= 0; i--) {
		s2[i] = s2[i+1] + (v[i] == 2);
		s1[i] = max(s2[i], s1[i+1] + (v[i] == 1));
	}
	
	/*for (int i = 0; i < n; i++) {
		cout << p1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << p2[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << s1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << s2[i] << " ";
	}
	cout << endl;*/
	
	int ans = 0;
	for (int l = 0; l < n; l++) {
		vector<int> q1(n), q2(n), qe1(n);
		q2[l] = v[l] == 2;
		q1[l] = 1;
		qe1[l] = 1;
		for (int j = l+1; j < n; j++) {
			qe1[j] = qe1[j-1] + (v[j] == 1);
			q2[j] = q2[j-1] + (v[j] == 2);
			q1[j] = max(q2[j], q1[j-1] + (v[j] == 1));
		}
		for (int r = l; r < n; r++) {
			int l1 = (l == 0) ? 0 : p1[l-1];
			int l2 = (l == 0) ? 0 : p2[l-1];
			int m1 = q1[r], m2 = q2[r];
			int r1 = (r == n-1) ? 0 : s1[r+1];
			int r2 = (r == n-1) ? 0 : s2[r+1];
			ans = max(ans, l2 + m2 + r2);
			ans = max(ans, l1 + m1 + r2);
			ans = max(ans, l1 + qe1[r] + r1);
		}
	}
	cout << ans << endl;
	return 0;
}