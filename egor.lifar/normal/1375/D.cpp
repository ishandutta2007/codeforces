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
using ll = long long;
using ld = long double; 
const string FILENAME = "input";
const int MAXN = 1028;


int n;
int a[MAXN];
int was[MAXN];
int uks = 0;


void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> res;
	while (true) {
		uks++;
		for (int j = 0; j < n; j++) {
			was[a[j]] = uks;
		}
		int t = 0;
		while (was[t] == uks) {
			t++;
		}
		if (t == n) {
			break;
		}
		res.pb(t);
		a[t] = t;
	}
	for (int j = 0; j < n; j++) {
		if (a[j] != j) {
			uks++;
			for (int j = 0; j < n; j++) {
				was[a[j]] = uks;
			}
			int t = 0;
			while (was[t] == uks) {
				t++;
			}
			for (int k = 0; k < n; k++) {
				if (a[k] == j) {
					a[k] = t;
					res.pb(k);
					break;
				}
			}
			res.pb(j);
			a[j] = j;
		}
	}
	cout << sz(res) << '\n';
	assert(sz(res) <= 2 * n);
	for (auto x: res) {
		cout << x  + 1 << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;	 	
}