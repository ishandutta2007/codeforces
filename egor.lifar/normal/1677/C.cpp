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
const int MAXN = 100228;


int n;
int ca[MAXN], cb[MAXN];
int wherea[MAXN], whereb[MAXN];
vector<int> g[MAXN];
bool used[MAXN];
int cnt = 0;


void dfs(int u) {
	used[u] = true;
	cnt++;
	for (auto h: g[u]) {
		if (!used[h]) {
			dfs(h);
		}
	}
}


void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ca[i];
		wherea[ca[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> cb[i];
		whereb[cb[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		g[i].clear();
		used[i] = false;
	}
	for (int i = 1; i <= n; i++) {
		g[wherea[i]].pb(whereb[i]);
		g[whereb[i]].pb(wherea[i]);
	}
	vector<int> st, st1;
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			cnt = 0;
			dfs(i);
			if (cnt == 1) {
				continue;
			}
			if (cnt & 1) {
				st.pb(cnt);
			} else {
				st1.pb(cnt);
			}
		}
	}
	sort(all(st));
	sort(all(st1));
	reverse(all(st));
	reverse(all(st1));
	int uk = 1;
	int uk1 = n;
	ll ans = 0;
	for (auto x: st1) {
		vector<int> tl;
		for (int i = 0; i < x; i++) {
			if (!(i & 1)) {
				tl.pb(uk);
				uk++;
			} else {
				tl.pb(uk1);
				uk1--;
			}
		}
		for (int i = 0; i < sz(tl); i++) {
			ans += abs(tl[i] - tl[(i + 1) % sz(tl)]);
		}
	}
	for (auto x: st) {
		vector<int> tl;
		for (int i = 0; i < x - 1; i++) {
			if (!(i & 1)) { 
				tl.pb(uk);
				uk++;
			} else {
				tl.pb(uk1);
				uk1--;
			}
		}
		for (int i = 0; i < sz(tl); i++) {
			ans += abs(tl[i] - tl[(i + 1) % sz(tl)]);
		}
	}
	cout << ans << '\n';
}


int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;
	t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}