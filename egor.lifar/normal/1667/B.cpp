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
template<typename T1, typename T2> inline bool chkmin(T1 &a, T2 b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<typename T1, typename T2> inline bool chkmax(T1 &a, T2 b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
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
const int MAXN = 500228;


int n;
int a[MAXN];
int dp[MAXN], dp1[MAXN];



struct rmq{
	vector<int> d;
	int ss = 1;
	void init(int n) {
		while (ss < n) {
			ss <<= 1;
		}
		d.resize(2 * ss);
		for (auto &x: d) {
			x = -1e9;
		}
	}
	void change(int i, int val) {
		i += ss;
		chkmax(d[i], val);
		while (i >> 1 > 0) {
			i >>= 1;
			d[i] = max(d[i * 2], d[i * 2 + 1]);
		}
	}
	int get(int l, int r) {
		l += ss;
		r += ss;
		int res = -1e9;
		while (l <= r) {
			if (l & 1) {
				chkmax(res, d[l]);
				l++;
			}
			if (!(r & 1)) {
				chkmax(res, d[r]);
				r--;
			}
			l >>= 1;
			r >>= 1;
		}
		return res;
	}
};


void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<ll> st;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		st.pb(sum);
	}
	sort(all(st));
	st.resize(distance(st.begin(), unique(all(st))));
	for (int i = 0; i < n; i++) {
		dp1[i] = -1e9;
	}
	rmq kek, kek1;
	kek.init(n);
	kek1.init(n);
	sum = 0;	
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (sum == 0) {
			dp[i] = 0;
		} else if (sum > 0) {
			dp[i] = i + 1;
		} else {
			dp[i] = -(i + 1);
		}
		int pos = lower_bound(all(st), sum) - st.begin();
		chkmax(dp[i], dp1[pos]);
		chkmax(dp[i], kek.get(0, pos - 1) + i);
		chkmax(dp[i], kek1.get(pos + 1, sz(st) - 1) - i);
		chkmax(dp1[pos], dp[i]);
		kek.change(pos, dp[i] - i);
		kek1.change(pos, dp[i] + i);
	}
	cout << dp[n - 1] << '\n';
}


int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;
	t = 1;
	cin >> t;
	while (t--) {
	//	cerr << t << endl;
		solve();
	}
}