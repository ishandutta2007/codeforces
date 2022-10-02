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
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define rank rank228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int MAXN = 100228;


int n, k;
int a[MAXN];
int ss = 1;
ll d[MAXN * 4];
int where[MAXN];
int vals[MAXN];


void inc(int i, ll x) {
	i += ss;
	while (i) {
		d[i] += x;
		i >>= 1;
	}
}


ll get(int l, int r) {
	l += ss;
	r += ss;
	ll ans = 0;
	while (l <= r) {
		if (l & 1) {
			ans += d[l];
			l++;
		}
		if (!(r & 1)) {
			ans += d[r];
			r--;
		}
		l >>= 1;
		r >>= 1;
	}
	return ans;
}

ll count(int x) {
	ss = 1;
	while (ss <= n) {
		ss <<= 1;
	}
	for (int i =0; i < 2 * ss; i++) {
		d[i] = 0;
	}
	int pref = 0;
	vector<pair<int, int> > st;
	st.pb(mp(0, 0));
	for (int i = 0; i < n; i++) {
		int val = 0;
		if (a[i] >= x) {
			val = 1;
		} else {
			val = -1;
		}
		pref += val;
		vals[i] = pref;
		st.pb(mp(pref, i + 1));
	}
	sort(all(st));
	for (int i = 0; i < sz(st); i++) {
		where[st[i].second] = i;
	}
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		int x = where[i - 1];
		inc(x, 1);
		int f = lower_bound(all(st), mp(vals[i], 0)) - st.begin();
		ans += get(0, f - 1);
	}
	return ans;
}

void solve() {
	cin >> n >> k;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == k) {
			cnt++;
		}
	}
	if (cnt == n) {
		cout << "yes\n";
		return;
	}
	if (cnt == 0) {
		cout << "no\n";
		return;
	}
	ll s = count(k) - count(k + 1);
	assert(s >= 0);
	if (s != 0) {
		cout << "yes\n";
		return;
	}
	s = count(k + 1);
	if (s != 0) {
		cout << "yes\n";
		return;
	}
	cout << "no\n";
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