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
const string FILENAME = "input";
const int MAXN = 100228;



int n;
ll xx[MAXN];
vector<int> g[MAXN];
vector<pair<long long, pair<int, int> > > cur;
long long ans = 0;


long long gcd(long long a, long long b) {
	while (a) {
		b %= a;
		swap(a, b);
	}
	return b;
}

void dfs(int u, int pr = -1, int deep = 0) {
	auto z = cur;
	for (auto &x: cur) {
		x.first = gcd(x.first, xx[u]);
	}
	cur.pb({xx[u], {deep, deep}});
	vector<pair<long long, pair<int, int> > >  st;
	for (auto x: cur) {
		if (st.empty() || st.back().first != x.first) {
			st.pb(x);
		} else {
			st.back().second.second = x.second.second;
		}
	}
	cur = st;
	for (auto h: cur) {
		ans += (h.first % 1000000007) * (h.second.second - h.second.first + 1);
		ans %= 1000000007;
	}
	for (auto h: g[u]) {
		if (h == pr) {
			continue;
		}
		dfs(h, u, deep + 1);
	}	
	cur = z;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
 	cin >> n;
 	for (int i = 0; i < n; i++) {
 		cin >> xx[i];
 	}
 	for (int i = 0; i < n - 1; i++) {
 		int a, b;
 		cin >> a >> b;
 		a--, b--;
 		g[a].pb(b);
 		g[b].pb(a);
 	}
 	dfs(0);
 	cout << ans << endl;
	return 0; 	
}