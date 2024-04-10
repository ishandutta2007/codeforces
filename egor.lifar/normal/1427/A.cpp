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


void solve() {
	cin >> n;
	int s = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}
	if (s == 0) {
		cout << "NO\n";
		return;
	}
	vector<int> st, st1;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			st.pb(a[i]);
		} else {
			st1.pb(a[i]);
		}
	}
	int sst = 0, sst1 = 0;
	for (auto x: st) {
		sst += x;
	}
	for (auto y: st1) {
		sst1 += -y;
	}
	if (sst > sst1) {
		sort(all(st));
		reverse(all(st));
		sort(all(st1));
		cout << "YES\n";
		for (auto x: st) {
			cout << x << ' ';
		}
		for (auto x: st1) {
			cout << x << ' ';
		}
		cout << '\n';
	} else {
		st.clear();
		st1.clear();
		for (int i = 0; i < n; i++) {
			a[i] *= -1;
			if (a[i] > 0) {
				st.pb(a[i]);
			} else {
				st1.pb(a[i]);
			}
		}
		sort(all(st));
		reverse(all(st));
		sort(all(st1));
		cout << "YES\n";
		for (auto x: st) {
			cout << -x << ' ';
		}
		for (auto x: st1) {
			cout << -x << ' ';
		}
		cout << '\n';
	}
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
}