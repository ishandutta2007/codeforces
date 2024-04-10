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
const int MAXN = 105;

int t;
int n, m;
string s[MAXN];
int a[MAXN][MAXN];
	vector<vector<pair<int, int> > > ans;


void solve(int i, int j) {
	if (i == n - 1) {
		i--;
	}
	if (j == m - 1) {
		j--;
	}
	if (a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1] == 0) {
		return;
	}
	vector<pair<int, int> > sf, sf1;
	for (int t = i; t <= i + 1; t++) {
		for (int t1 = j; t1 <= j + 1; t1++) {
			if (a[t][t1] == 1) {
				sf.pb(mp(t, t1));
			} else {
				sf1.pb(mp(t, t1));
			}
		}
	}
	while (sz(sf) != 0) {
		assert(sz(sf) + sz(sf1) == 4);
		if (sz(sf) == 3) {
			ans.pb(sf);
			break;
		}
		if (sz(sf) == 2) {
			vector<pair<int, int> > k;
			k.pb(sf.back());
			auto t = sf.back();
			sf.pop_back();
			k.pb(sf1.back());
			sf.pb(sf1.back());
			sf1.pop_back();
			k.pb(sf1.back());
			sf.pb(sf1.back());
			sf1.pop_back();
			sf1.pb(t);
			ans.pb(k);
			//2-> 3
			continue;
		}
		if (sz(sf) == 4) {
			vector<pair<int, int> > k;
			k.pb(sf.back());
			sf.pop_back();
			k.pb(sf.back());
			sf.pop_back();
			k.pb(sf.back());
			sf.pop_back();
			sf1 = k;
			ans.pb(k);
			//4-> 1
			continue;	
		}
		if (sz(sf) == 1) {
			vector<pair<int, int> > k = {sf[0]};
			auto g = sf[0];
			sf.pop_back();
			k.pb(sf1.back());
			sf.pb(sf1.back());
			sf1.pop_back();
			k.pb(sf1.back());
			sf.pb(sf1.back());
			sf1.pop_back();
			sf1.pb(g);
			ans.pb(k);
			//1->2
			continue;
		}
	}
	a[i][j] = 0;
	a[i + 1][j] = 0;
	a[i][j + 1] = 0;
	a[i + 1][j + 1] = 0;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++) {
			a[i][j] = s[i][j] - '0';
		}
	}
	ans.clear();
	//4  4
	//1  3
	//2  2
	//3  1 
	//0  0
	int who[5];
	who[0] = 0;
	who[3] = 1;
	who[2] = 2;
	who[1] = 3;
	who[4] = 4;
	while (true) {
		bool was = false;
		int pi = -1;
		int pj = -1;
		int sd = -1;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m - 1; j++) {
				int pt = a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1];
				if (pt) {
					was = true;
					if (sd == -1 || who[pt] < who[sd]) {
						sd = pt;
						pi = i;
						pj = j;
					}
				}
			}
		}
		if (!was) {
			break;
		}
		solve(pi, pj);
	}	
 	cout << sz(ans) << '\n';
	for (auto x: ans) {
		for (auto y: x) {
			cout << y.first + 1 << ' ' << y.second + 1 << ' ';
		}
		cout << '\n';
	}
} 


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> t;
	while (t--) {
		solve();
	}
}