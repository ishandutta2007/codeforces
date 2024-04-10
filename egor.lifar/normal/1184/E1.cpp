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
const string FILENAME = "input";
const int MAXN = 100228;


int n, m;
int parent[MAXN];
 
 
int findset(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = findset(parent[v]);
}
 
bool unite(int a, int b) {
    a = findset(a);
    b = findset(b);
    if (a == b) {
        return false;
    }
    parent[a] = b;
    return true;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> m;
	int ta, tb;
	vector<pair<int, pair<int, int> > > st;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		if (i == 0) {
			ta = a;
			tb = b;
		} else {
			st.pb({c, {a, b}});
		}
	} 
	sort(all(st));
	int l = 0;
	int r = 1000000000;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
		bool ok = true;
		bool ts = false;
		for (auto x: st) {
			if (x.first >= mid) {
				if (findset(ta) == findset(tb)) {
					ok = false;
				}
				ts = true;
				break;
			}
			unite(x.second.first, x.second.second);
		}
		if (!ts) {
			if (findset(ta) == findset(tb)) {
				ok = false;
			}
		}
		if (ok) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << l << '\n';
	return 0;
}