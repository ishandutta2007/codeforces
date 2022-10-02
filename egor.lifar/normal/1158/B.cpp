 /*
 



















 
 */
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>

using namespace std;
template<class T1, class T2> inline void chkmin(T1 &x, const T2 &y) {if (x > y) x = y;}
template<class T1, class T2> inline void chkmax(T1 &x, const T2 &y) {if (x < y) x = y;}
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define mp make_pair
#define pb push_back
#define read(FILENAME) freopen((string(FILENAME) + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((string(FILENAME) + ".out").c_str(), "w", stdout);



bool check(string s, int k) {
	bool bad = false;
	int n = sz(s);
	for (int len = 1; len <= k; len++) {
		map<string, int> was;
		for (int i = 0; i <= n - len; i++) {
			string g;
			for (int j = i; j < i + len; j++) {
				g += s[j];
			}
			was[g]++;
		}
		int cnt = 0;
		for (auto x: was) {
			if (x.second == 1) {
				cnt++;
			}
		}
		if (cnt && len < k) {
			bad = true;
			break;
		}
		if (cnt == 0 && len == k) {
			bad = true;
			break;
		}
	}
	return !bad;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read("input");
	int n, k;
	cin >> n >> k;
	if (k == n) {
		for (int i = 0; i < n; i++) {
			cout << 1;
		}	
		cout << '\n';
		return 0;
	}
	if (k == 1) {
		cout << 0;
		for (int i = 1; i < n; i++) {
			cout << 1;
		}	
		cout << '\n';
		return 0;
	}
	int fuck = (n - k) / 2;
	string ans;
	for (int i = 0; i < n; i++) {
		if (i % (fuck + 1) == 0) {
			cout << 1;
			ans += '1';
		} else {
			cout << 0;
			ans += '0';
		}
	}
	cout << endl;
	//cout << check(ans, k) << endl;
	// int f = 2 * k - n;
	// //cout << f << endl;
	// for (int mask = 0; mask < (1 << n); mask++) {
	// 	string s;
	// 	for (int i = 0; i < n; i++) {
	// 		if (mask & (1 << i)) {
	// 			s += char('1');
	// 		} else {
	// 			s += char('0');
	// 		}
	// 	}
	// 	bool bad = false;
	// 	for (int len = 1; len <= k; len++) {
	// 		map<string, int> was;
	// 		for (int i = 0; i <= n - len; i++) {
	// 			string g;
	// 			for (int j = i; j < i + len; j++) {
	// 				g += s[j];
	// 			}
	// 			was[g]++;
	// 		}
	// 		int cnt = 0;
	// 		for (auto x: was) {
	// 			if (x.second == 1) {
	// 				cnt++;
	// 			}
	// 		}
	// 		if (cnt && len < k) {
	// 			bad = true;
	// 			break;
	// 		}
	// 		if (cnt == 0 && len == k) {
	// 			bad = true;
	// 			break;
	// 		}
	// 	}
	// 	if (!bad) {
	// 		cout << s << endl;
	// 		exit(0);
	// 	}
	// }
}