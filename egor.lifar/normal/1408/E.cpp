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
const int MAXN = 100228;


int m, n;
int a[MAXN], b[MAXN];
int s[MAXN];
vector<int> tr[MAXN];
int parent[MAXN];
vector<int> last[MAXN];


int findset(int v) {
	if (v == parent[v]) {
		return v;
	}
	return parent[v] = findset(parent[v]);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		parent[i] = i; 
	}
	for (int j = 0; j < n; j++) {
		cin >> b[j];
	}
	for (int i = 0; i < m; i++) {
		cin >> s[i];
		for (int j = 0; j < s[i]; j++) {
			int a;
			cin >> a;
			a--;
			tr[i].pb(a);
		}
		sort(all(tr[i]));
	}
	vector<pair<int, pair<int, int> > > st;
	for (int i = 0; i < m; i++) {
		for (auto x: tr[i]) {
			st.pb(mp(a[i] + b[x], mp(x, i)));
		}
	}		
	sort(all(st));
	reverse(all(st));
	ll ans = 0;
	for (auto y: st) {
		ans += y.first;
	}
	for (auto x: st) {
		int cost = x.first;
		int id = x.second.first;
		int pos = x.second.second;
		if (last[id].empty()) {
			last[id].pb(pos);
			ans -= cost;
		} else {
			int d = findset(last[id].back());
			int k = findset(pos);
			if (k != d) {
				ans -= cost;
				parent[k] = d;
			}
		}
	}
	cout << ans << '\n';
}