/*

Code for problem A by cookiedoth
Generated 07 Sep 2021 at 03.10 PM



10%

30%

50%

70%

100%

-_-
z_z
=_=

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#include <random>
#include <utility>
#include <tuple>
#include <chrono>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define length(a) (int)a.size()

using namespace std;

template<class T> int chkmax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T x, ostream& out = cerr) {
	output(x.begin(), x.end(), out);
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int NEUTRAL = -1e9;

struct fast_max_rmq {
	vector<int> t;
	int n;

	void build(vector<int> &a, int v, int tl, int tr) {
		if (tl == tr)
			t[v] = a[tl];
		else {
			int tm = ((tl + tr) >> 1);
			build(a, v * 2, tl, tm);
			build(a, v * 2 + 1, tm + 1, tr);
			t[v] = max(t[v * 2], t[v * 2 + 1]);
		}
	}

	fast_max_rmq(vector<int> _a) {
		n = 1;
		while (n < (int)_a.size()) {
			n <<= 1;
		}
		_a.resize(n);
		t.resize(2 * n);
		build(_a, 1, 0, n - 1);
	}

	void update(int pos, int val) {
		pos += n;
		chkmax(t[pos], val);
		while (true) {
			pos >>= 1;
			if (pos > 0)
				t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
			else
				break;
		}
	}

	int get(int l, int r) {
		l += n;
		r += n;
		int res = NEUTRAL;
		while (l <= r) {
			if (l & 1) {
				chkmax(res, t[l]);
				l++;
				continue;
			}
			if ((r & 1) == 0) {
				chkmax(res, t[r]);
				r--;
				continue;
			}
			l >>= 1;
			r >>= 1;
		}
		return res;
	}
};

const int mx = 5e5 + 228;
int n, arr[mx], ans, rl[mx];

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	vector<int> st;
	for (int i = n - 1; i >= 0; --i) {
		while (!st.empty() && arr[i] >= arr[st.back()]) {
			st.pop_back();
		}
		rl[i] = st.empty() ? n : st.back();
		st.push_back(i);
	}
	// cerr << "arr:\n";
	// output(arr, arr + n);
	// cerr << "rl:\n";
	// output(rl, rl + n);
	fast_max_rmq T(vector<int>(n + 1));
	vector<vector<pair<int, int>>> delayed(n + 2);
	ans = 0;
	delayed[1].emplace_back(0, 1);
	for (int i = 0; i < n; ++i) {
		for (auto [key, value] : delayed[i]) {
			T.update(key, value);
		}
		int cur_dp = T.get(0, arr[i]) + 1;
		chkmax(ans, cur_dp);
		// cerr << "cur_dp for " << i << " = " << cur_dp << '\n';
		T.update(arr[i], cur_dp);
		delayed[rl[i] + 1].emplace_back(arr[i], cur_dp + 1);
	}
	cout << ans << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}