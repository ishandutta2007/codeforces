#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>


using namespace std;
template<class T1, class T2> inline bool chkmin(T1 &x, const T2& y) {
	if (x > y) {
		x = y;
		return true;
	}
	return false;
}
template<class T1, class T2> inline bool chkmax(T1 &x, const T2& y) {
	if (x < y) {
		x = y;
		return true;
	}
	return false;
}
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define mp make_pair
#define pb push_back
#define int long long
using ll = long long;
using ld = long double;
const int MAXN = 300228;



int n;
int h[MAXN], b[MAXN];
int l[MAXN], r[MAXN];
ll dp[MAXN];
ll d[MAXN * 4];
int ss = -1;



void change(int i, ll val) {
	i += ss;
	d[i] = val;
	while (i >> 1 > 0) {
		i >>= 1;
		d[i] = max(d[i * 2], d[i * 2 + 1]);
	}
}


ll getmax(int l, int r) {
	l += ss - 1;
	r += ss - 1;
	ll ans = -1e18;
	while (l <= r) {
		if (l & 1) {
			chkmax(ans, d[l]);
			l++;
		}
		if (!(r & 1)) {
			chkmax(ans, d[r]);
			r--;
		}
		l >>= 1;
		r >>= 1;
	}
	return ans;
}


vector<ll> del[MAXN];


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	vector<int> st;
	for (int i = 0; i < n; i++) {
		while (!st.empty() && h[st.back()] > h[i]) {
			st.pop_back();
		}
		l[i] = (st.empty() ? 0: st.back() + 1);
		st.pb(i);
	}
	st.clear();
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() && h[st.back()] > h[i]) {
			st.pop_back();
		}
		r[i] = (st.empty() ? n - 1: st.back() - 1);
		st.pb(i);
	}
	for (int i = 0; i < n; i++) {
		dp[i] = -1e18;
	}
	ss = 1;
	while (ss < n) {
		ss <<= 1;
	}
	for (int i = 0; i < 2 * ss; i++) {
		d[i] = -1e18;
	}
	multiset<ll> s;
	for (int i = 0; i < n; i++) {
		for (auto x: del[i]) {
			s.erase(s.find(x));
		}
		if (!s.empty()) {
			chkmax(dp[i], *s.rbegin());
		}
		chkmax(dp[i], (i == 0 ? 0: dp[i - 1]) + b[i]);
		if (l[i] == 0) {
			chkmax(dp[i], b[i]);
		}
		chkmax(dp[i], b[i] + getmax(max(l[i], 1LL), i));
		s.insert(dp[i]);
		del[r[i] + 1].pb(dp[i]);
		change(i, dp[i]);
	}
	cout << dp[n - 1] << '\n';
}