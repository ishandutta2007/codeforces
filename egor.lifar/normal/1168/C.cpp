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
template<class T1, class T2> inline void chkmin(T1 &x, const T2 &y) {if (x > y) x = y;}
template<class T1, class T2> inline void chkmax(T1 &x, const T2 &y) {if (x < y) x = y;}
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define mp make_pair
#define pb push_back
#define read(FILENAME) freopen((string(FILENAME) + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((string(FILENAME) + ".out").c_str(), "w", stdout);
const int MAXN = 300228;


int n, q;
int a[MAXN];
int nxt[MAXN][22];
bool used[22];
int last[22][22];
int pos[22];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read("input");
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			last[i][j] = n;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 20; j++) {
			nxt[i][j] = n;
		}
		for (int j = 0; j < 20; j++) {
			if (a[i] & (1 << j)) {
				for (int j1 = 0; j1 < 20; j1++) {
					if (a[i] & (1 << j1)) {
						chkmin(last[j][j1], i);
					}
				}
			}
		}
		for (int j = 0; j < 20; j++) {
			if (a[i] & (1 << j)) {
				for (int f = 0; f < 20; f++) {
					chkmin(nxt[i][f], last[j][f]);
				}
			}
		}
	}
	for (int it = 0; it < q; it++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		queue<pair<int, int> > q;
		for (int i = 0; i < 20; i++) {
			used[i] = false;
		}
		for (int i = 0; i < 20; i++) {
			if (a[x] & (1 << i)) {
				used[i] = true;
				q.push({x, i});
				pos[i] = x;
			} else {
				pos[i] = 1e9;
			}
		}
		while (!q.empty()) {
			auto f = q.front();
			q.pop();
			int aa = f.first;
			for (int i = 0; i < 20; i++) {
				if (nxt[aa][i] <= y && pos[i] > nxt[aa][i]) {
					pos[i] = nxt[aa][i];
					used[i] = true;
					q.push({pos[i], i});
				}
			}
		}
		bool ok = false;
		for (int i = 0; i < 20; i++) {
			if (a[y] & (1 << i)) {
				if (used[i]) {
					ok = true;
				}
			}
		}
		if (ok) {
			cout << "Shi\n";
		} else {
			cout << "Fou\n";
		}
	}
}