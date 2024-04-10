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
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
const string FILENAME = "input";



void solve() {
	int n;
	cin >> n;
	cout << 1 << ' ' << n - 1 << ' ' << 1;
	for (int i = 2; i <= n; i++) {
		cout << ' ' << i;
	}
	cout << endl;
	int res;
	cin >> res;
	int l = 2;
	int r = n;
	while (l < r) {
		int mid = (l + r) >> 1;
		cout << 1 << ' ' << mid - 1 << ' ' << 1;
		for (int i = 2; i <= mid; i++) {
			cout << ' ' << i;
		}
		cout << endl;
		int sf;
		cin >> sf;
		if (sf < res) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	cout << 1 << ' ' << n - 1 << ' ' << l;
	for (int i = 1; i <= n; i++) {
	 	if (i == l) {
	 		continue;
	 	}
		cout << ' ' << i;
	}
	cout << endl;
	int f;
	cin >> f;
	cout << -1 << ' ' << f << endl;
}


int main() {
	ios_base::sync_with_stdio(false);
 	//read(FILENAME);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0; 	
}