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
using ld = long double;
const string FILENAME = "input";
const int MAXN = 3005;


int n, k;
vector<int> who[MAXN];
bool used[MAXN];



int query(vector<int> d) {
	sort(all(d));
	d.resize(distance(d.begin(), unique(all(d))));
	cout << "? " << sz(d);
	for (auto x: d) {
		cout << ' ' << x;
	}
	cout << endl;
	int res;
	cin >> res;
	return res;
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		used[i] = false;
	}
	for (int i = 0; i < k; i++) {
		int p;
		cin >> p;
		who[i].clear();
		for (int j = 0; j < p; j++) {
			int a;
			cin >> a;
			used[a] = true;
			who[i].pb(a);
		}
	}
	vector<int> add;
	vector<int> f;
	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			add.pb(i);
		}
		f.pb(i);
	}
	int maxd = query(f);
	int l = 0;
	int r = k -1;
	while (l < r) {
		int mid = (l + r) >> 1;
		vector<int> t;
		for (int i = 0; i <= mid; i++) {
			for (auto x: who[i]) {
				t.pb(x);
			}
		}
		for (auto y: add) {
			t.pb(y);
		}
		if (query(t) != maxd) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	vector<int> t = add;
	for (int i = 0; i < k; i++) {
		if (i != l) {
			for (auto x: who[i]) {
				t.pb(x);
			}
		}
	}
	int d = query(t);
	cout << "!";
	for (int i = 0; i < k; i++) {
		if (i == l) {
			cout << ' ' << d;
		} else {
			cout << ' '  << maxd;
		}
	}
	cout << endl;
	string res;
	cin >> res;
	assert(res == "Correct");
}

int main() {
	ios_base::sync_with_stdio(false);

 	//read(FILENAME);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0; 	
}