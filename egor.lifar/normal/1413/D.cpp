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
const int MAXN = 200229;


int n;
string s[MAXN];
int x[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	read(FILENAME);
	cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		cin >> s[i];
		if (s[i] == "-") {
			cin >> x[i];
		}
	}
	int bal = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (s[i] == "-") {
			bal--;
		} else {
			bal++;
		}
		if (bal < 0) {
			cout << "NO\n";
			return 0;
		}
	}
	set<int> have;
	vector<int> res;
	for (int i = 2 * n - 1; i >= 0; i--) {
		if (s[i] == "-") {
			have.insert(x[i]);
		} else {
			if (have.empty()) {
				cout << "NO\n";
				return 0;
			}
			int d = *have.begin();
			have.erase(d);
			res.pb(d);
		}
	}
	reverse(all(res));
	set<int> cur;
	int it = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (s[i] == "-") {
			if (cur.empty()) {
				cout << "NO\n";
				return 0;
			}
			int d = *cur.begin();
			cur.erase(d);
			if (d != x[i]) {
				cout << "NO\n";
				return 0;
			}
		} else {
			cur.insert(res[it]);
			it++;
		}
	}
	cout << "YES\n";
	for (auto x: res) {
		cout << x << ' ';
	}
	cout << '\n';
	return 0;
}