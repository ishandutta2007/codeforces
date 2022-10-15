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
	//#define LOCAL_INPUT_FILE
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
	int s1, s2; cin >> s1 >> s2;
	vector< pair<int, int> > v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v.begin(), v.end());
	vector<int> minScale(n);
	vector<int> maxDel(n);
	for (int i = 0; i < n; i++) {
		minScale[i] = (s2 + v[i].first - 1) / v[i].first;
		maxDel[i] = n - i - minScale[i];
	}
	vector<int> pm(n+1), sm(n+1);
	pm[0] = -infinity;
	for (int i = 0; i < n; i++) {
		pm[i+1] = max(pm[i], maxDel[i]);
	}
	sm[n] = -infinity;
	for (int i = n-1; i >= 0; i--) {
		sm[i] = max(sm[i+1], maxDel[i]);
	}
	for (int len = 1; len <= n; len++) {
		int minPow = (s1 + len - 1) / len;
		int lb = lower_bound(v.begin(), v.end(), make_pair(minPow, INT_MIN)) - v.begin();
		int rb = lb + len - 1;
		if (rb >= n) {
			continue;
		}
		int rOk = sm[rb+1];
		int lOk = pm[lb] - len;
		if (lOk < 0 && rOk < 0) {
			continue;
		}
		cout << "Yes\n";
		vector<int> q2;
		int bst = max(lOk, rOk);
		int ko = 0;
		bool ok = false;
		for (int j = n-1; j >= 0; j--) {
			if (j == rb) {
				ko = -len;
				j = lb-1;
				if (j < 0) {
					break;
				}
			}
			q2.push_back(v[j].second + 1);
			if (maxDel[j] + ko == bst) {
				ok = true;
				break;
			}
		}
		assert(ok);
		cout << rb - lb + 1 << " " << q2.size() << endl;
		for (int j = lb; j <= rb; j++) {
			cout << v[j].second + 1 << " ";
		}
		cout << endl;
		for (int i: q2) {
			cout << i << " ";
		}
		cout << endl;
		return 0;
	}
	cout << "No" << endl;
	return 0;
}