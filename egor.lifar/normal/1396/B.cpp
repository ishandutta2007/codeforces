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
using ll = long long;
using ld = long double; 
const string FILENAME = "input";
const int MAXN = 105;



int n;
int a[MAXN];
string fir = "T";
string sec = "HL";



bool win(vector<int> k, int id = -1) {
	for (int i = 0; i < sz(k); i++) {
		if (i != id && k[i]) {
			auto k1 = k;
			k1[i]--;
			if (!win(k1, i)) {
				return true;
			}
		}
	}
	return false;
}


bool solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int fd = 0;
	for (int i = 0; i < n - 1; i++) {
		fd += a[i];
	}
	if (fd < a[n - 1]) {
		cout << fir << endl;
		return true;
	}
	if (fd == a[n - 1]) {
		cout << sec << endl;
		return false;
	}
	int fk = 0;
	for (int i = 0; i < n ; i++) {
		fk += a[i];
	}
	if (fk % 2 == 1) {
		cout << fir << endl;
	} else {
		cout << sec << endl;
	}
	return fk % 2 == 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	read(FILENAME);
	// while (true) {
	// 	n = rand() % 6 + 1;
	// 	for (int i = 0; i < n; i++) {
	// 		a[i] = rand() % 5 + 1; 
	// 	}
	// 	vector<int> f;
	// 	for (int i = 0; i < n; i++) {
	// 		f.pb(a[i]);
	// 	}
	// 	bool t = win(f, -1);
	// 	bool k = solve();
	// 	cout << t << ' ' << k << endl;
	// 	for (int i = 0; i < n; i++) {
	// 		cout << a[i] << ' ';
	// 	}
	// 	cout << '\n';
	// 	assert(t == k);
	// }
	// exit(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}