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
int c[MAXN];



void move(vector<int> d) {
	int uk = 0;
	vector<vector<int> > a;
	for (int i = 0; i < sz(d); i++) {
		vector<int> cs;
		for (int t = 0; t < d[i]; t++) {
			cs.pb(c[uk]);
			uk++;
		}
		a.pb(cs);
	}
	reverse(all(a));
	uk = 0;
	for (auto x: a) {
		for (auto y: x) {
			c[uk] = y;
			uk++;
		} 
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	vector<vector<int> > ans;
	int l = 0;
	int r = n - 1;
	while (l < r) {
		while (l < r && c[l] == l + 1) {
			l++;
		}
		while (r > l && c[r] == r + 1) {
			r--;
		}
		if (l >= r) {
			break;
		}
		int one = l + 1;
		int two = r + 1;
		int pos = 0, pos1 = 0;
		for (int t = l; t <= r; t++) {
			if (c[t] == one) {
				pos = t;
			}
			if (c[t] == two) {
				pos1 = t;
			}
		}
		vector<int> ops; 
		ops.pb(l);
		ops.pb(pos1 - l);
		ops.pb(r - pos1 + 1);
		ops.pb(n - r - 1);
		ans.pb(ops);
		move(ops);
		int l1 = l;
		int r1 = r;
		l = n - r1 - 1;
		r = n - l1 - 1;
		assert(c[l] == two);
		for (int t = l; t <= r; t++) {
			if (c[t] == one) {
				pos = t;
			}
			if (c[t] == two) {
				pos1 = t;
			}
		}
		ops.clear();
		ops.pb(l);
		ops.pb(1);
		ops.pb(pos - pos1 - 1);
		ops.pb(r - pos + 1);
		ops.pb(n - r - 1);
		ans.pb(ops);
		move(ops);
		l1 = l;
		r1 = r;
		l = n - r1 - 1;
		r = n - l1 - 1;
	}
	for (int i = 0; i < n; i++) {
		assert(c[i] == i + 1);
	}
	vector<vector<int> > st;
	for (auto x: ans) {
		vector<int> d;
		for (auto z: x) {
			if (z == 0) {
				continue;
			}
			d.pb(z);
		}
		if (sz(d) > 1) {
			st.pb(d);
		}
	}
	cout << sz(st) << '\n';
	for (auto d: st) {
		cout << sz(d);
		for (auto y: d) {
			cout << ' ' << y;
		}
		cout << '\n';
	}
}