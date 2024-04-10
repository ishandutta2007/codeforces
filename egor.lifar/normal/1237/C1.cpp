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
#define mp make_pair
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int MAXN = 50228;



int n;
int x[MAXN], y[MAXN], z[MAXN];
int id[MAXN];
bool del[MAXN];


bool comp(int i, int j) {
	return x[i] < x[j] || (x[i] == x[j] && (y[i] < y[j] || (y[i] == y[j] && z[i] < z[j])));
}



set<pair<int, int> > f;
set<int> all;



void add(int xx) {
	auto it = all.upper_bound(xx);
	if (it == all.end()) {
		return;
	}
	int yy = *it;
	int cnt = 0;
	if (x[id[xx]] == x[id[yy]]) {
		cnt++;
		if (y[id[xx]] == y[id[yy]]) {
			cnt++;
			if (z[id[xx]] == z[id[yy]]) {
				cnt++;
			}
		}
	}
	f.insert({cnt, xx});
}


void dels(int xx) {
	auto it = all.upper_bound(xx);
	if (it == all.end()) {
		return;
	}
	int yy = *it;
	int cnt = 0;
	if (x[id[xx]] == x[id[yy]]) {
		cnt++;
		if (y[id[xx]] == y[id[yy]]) {
			cnt++;
			if (z[id[xx]] == z[id[yy]]) {
				cnt++;
			}
		}
	}
	f.erase({cnt, xx});
}


bool del1[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> z[i];
		id[i] = i;
	}
	sort(id, id + n, comp);
	for (int i = 0; i < n; i++) {
		all.insert(i);
	}
	for (int i = 0; i < n - 1; i++) {
		add(i);
	}
	for (int i = 0; i < n / 2; i++) {
		auto p = *f.rbegin();
		while (del1[p.second]) {
			f.erase(p);
			p = *f.rbegin();
		}
		int a = p.second;
		auto it = all.upper_bound(a);
		int b = *it;
		all.erase(a);
		all.erase(b);
		auto it1 = all.lower_bound(a);
		if (it1 != all.begin()) {
			it1--;
			all.insert(a);
			dels(*it1);
			all.erase(a);
			add(*it1);
		}
		del1[a] = true;
		del1[b] = true;
		a = id[a];
		b = id[b];
		del[a] = true;
		del[b] = true;
		// for (int j = 0; j < n; j++) {
		// 	if (!del[j]) {
		// 		if (x[j] >= min(x[a], x[b]) && x[j] <= max(x[a], x[b])) {
		// 			if (y[j] >= min(y[a], y[b]) && y[j] <= max(y[a], y[b])) {
		// 				if (z[j] >= min(z[a], z[b]) && z[j] <= max(z[a], z[b])) {
		// 					exit(1);
		// 				}
		// 			}
		// 		}
		// 	}
		// }
		cout << a + 1 << ' ' << b + 1 << '\n';
	}
 	return 0;
}