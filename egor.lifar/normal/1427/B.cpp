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
const int MAXN = 200228;


int n, k;
string s;



void solve() {
	cin >> n >> k;
	cin >> s;
	int ans = 0;
	vector<int> d;
	int l = 0;
	int l1 = 0;
	int l2 = 0;
	bool was = false;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'W') {
			if (l) {
				if (was) {
					d.pb(l);
				} else {
					l1 = l;
				}
			}
			was = true;
			l = 0;
			ans++;
			if (i && s[i - 1] == 'W') {
				ans++;
			}
		} else {
			l++;
		}
	}
	if (l) {
		l2 = l;
	}
	if (k == 0) {
		cout << ans << '\n';
		return;
	}
	if (l2 == n) {
		cout << k + max(0, k - 1) << '\n';
		return;
	}
	sort(all(d));
	int have = 0;
	for (auto y: d) {
		have += y;
	}
	have += l1;
	have += l2;
	int add = min(have, k) * 2;
	int cur = 0;
	for (auto x: d) {
		have -= x;
		k -= x;
		if (k < 0) {
			break;
		}
		cur += max(x - 1, 0) * 2 + 3;
		chkmax(add, cur + min(have, k) * 2);
	}
	cout << ans + add << '\n';
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