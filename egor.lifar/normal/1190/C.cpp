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


using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
const string FILENAME = "input";
const int MAXN = 200228;

int n, k;
string s;
set<int> pos[2];
vector<int> g[2];

bool can() {
	if (pos[0].empty() || pos[1].empty()) {
		return true;
	}
	if (*pos[0].rbegin() - *pos[0].begin() + 1 <= k) {
		return true;
	}
	if (*pos[1].rbegin() - *pos[1].begin() + 1 <= k) {
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> k;
	cin >> s;
	int it = 0;
	for (auto x: s) {
		g[x - '0'].pb(it);
		it++;
	}
	if (g[0].empty() || g[1].empty()) {
		cout << "tokitsukaze\n";
		exit(0);
	}
	if (g[0].back() - g[0][0] + 1 <= k) {
		cout << "tokitsukaze\n";
		exit(0);
	}
	if (g[1].back() - g[1][0] + 1 <= k) {
		cout << "tokitsukaze\n";
		exit(0);
	}
	for (int j = k; j < n; j++) {
		pos[s[j] - '0'].insert(j);
	}
	bool bad = false;
	for (int i = 0; i <= n - k; i++) {
		for (int t = 0; t < 2; t++) {
			pos[t].insert(i);
			pos[t].insert(i + k - 1);
			if (!can()) {
				bad = true;
			}
			pos[t].erase(i);
			pos[t].erase(i + k - 1);
		}
		pos[s[i] - '0'].insert(i);
		if (i + k < n) {
			pos[s[i + k] - '0'].erase(i + k);
		}
	}
	if (!bad) {
		cout << "quailty\n";
		exit(0);
	}
	cout << "once again" << '\n';
	return 0;
}