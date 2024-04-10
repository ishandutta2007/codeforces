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
const int MAXN = 200229;


int n;


int solve(const vector<int> &a, int t = 30) {
	if (sz(a) <= 2) {
		return sz(a);
	}
	int cnt = 0, cnt1 = 0;
	for (int i = 0; i < sz(a); i++) {
		if (a[i] & (1 << t)) {
			cnt++;
		} else {
			cnt1++;
		}
	}
	if (cnt == sz(a) || cnt1 == sz(a)) {
		return solve(a, t - 1);
	}
	if (cnt == 1 || cnt1 == 1) {
		vector<int> b;
		for (int i = 0; i < sz(a); i++) {
			if (cnt == 1) {
				if (a[i] & (1 << t)) {
					continue;
				}
			} else {
				if (!(a[i] & (1 << t))) {
					continue;
				}
			}
			b.pb(a[i]);
		}
		return 1 + solve(b);
	}
	vector<int> b, b1;
	for (int i = 0; i < sz(a); i++) {
		if (a[i] & (1 << t)) {
			b.pb(a[i]);
		} else {
			b1.pb(a[i]);
		}
	}
	return 1 + max(solve(b), solve(b1));
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	vector<int> a;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << n - solve(a) << '\n';
}