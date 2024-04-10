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



int n, x, y;
int a[MAXN], b[MAXN];
bool used[MAXN];
int col;
vector<int> who[MAXN];


void solve() {
	for (int i = 0; i <= n + 1; i++) {
		used[i] = false;
	}
	cin >> n >> x >> y;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		b[i]--;
		used[b[i]] = true;
	}
	col = -1;
	for (int i = 0; i <= n; i++) {
		if (!used[i]) {
			col = i;
		} 
	}
	assert(col != -1);
	for (int i = 0; i < n; i++) {
		a[i] = col;
	}
	for (int i = 0; i <= n; i++) {
		who[i].clear();
	}
	for (int i = 0; i < n; i++) {
		who[b[i]].pb(i);
	}
	set<pair<int, int> > s;
	for (int i = 0; i <= n; i++) {
		s.insert({sz(who[i]), i});
	}
	for (int it = 0; it < x; it++) {
		auto x = *s.rbegin();
		s.erase(x);
		int id = x.second;
		a[who[id].back()] = id;
		who[id].pop_back();
		s.insert({sz(who[id]), id});
	}
	vector<int> st, st1;
	vector<int> order;
	while (!s.empty()) {
		auto x = *s.rbegin();
		s.erase(x);
		if (x.first == 0) {
			break;
		}
		st.pb(x.first);
		st1.pb(x.second);
		for (int it = 0; it < x.first; it++) {
			order.pb(x.second);
		}
	}
	if (x == y) {
		cout << "YES\n";
		for (int i = 0; i < n; i++) {
			cout << a[i] + 1 << ' ';
		}
		cout << '\n';
		return;
	}
	if (sz(st1) == 1) {
		cout << "NO\n";
		return;
	}
	int uk = 0;
	int uk1 = 0;
	while (order[uk1] == order[0]) {
		uk1++;
	}
	for (int it = 0; it < y - x; it++) {
		while (uk < sz(st1) && (st[uk] == 0 || order[uk1] == st1[uk])) {
			uk++;
		}
		if (uk == sz(st1)) {
			cout << "NO\n";
			return;
		}
		int pos = who[order[uk1]].back();
		who[order[uk1]].pop_back();
		a[pos] = st1[uk];
		st[uk]--;
		uk1++;
		if (uk1 == sz(order)) {
			uk1 = 0;
		}
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		cout << a[i] + 1 << ' ';
	}
	cout << '\n';
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