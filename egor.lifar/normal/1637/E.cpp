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
 #include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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
const int MAXN = 300228;


int n, m;
int a[MAXN];
int cnt[MAXN];
cc_hash_table<int, int> g[MAXN];
vector<int> who[MAXN];



void solve() {
	cin >> n >> m;
	vector<int> st;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		st.pb(a[i]);
	}
	sort(all(st));
	st.resize(distance(st.begin(), unique(all(st))));
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x = lower_bound(all(st), x) - st.begin();
		y = lower_bound(all(st), y) - st.begin();
		g[x][y] = true;
		g[y][x] = true;
	}
	for (int i = 0; i < n; i++) {
		a[i] = lower_bound(all(st), a[i]) - st.begin();
		cnt[a[i]]++;
	}
	for (int i = 0; i < n; i++) {
		if (cnt[a[i]]) {	
			who[cnt[a[i]]].pb(a[i]);
			cnt[a[i]] = 0;
		}
	}
	vector<int> d;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		sort(all(who[i]));
		reverse(all(who[i]));
		if (!who[i].empty()) {
			d.pb(i);
		}
		for (auto x: who[i]) {
			for (auto j: d) {
				int uk = 0;
				while (uk < sz(who[j]) && (who[j][uk] == x || g[x].find(who[j][uk]) != g[x].end())) {
					uk++;
				}
				if (uk < sz(who[j])) {
					//cout << i << ' ' << j << ' ' << x << ' ' << who[j][uk] << endl;
					chkmax(ans, (ll)(i + j) * (st[x] + st[who[j][uk]]));
				}
			}
		}	
	}
	for (int i = 1; i <= n; i++) {
		who[i].clear();
	}
	for (int i = 0; i < sz(st); i++) {
		g[i].clear();
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