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
const int MAXN = 300228;


int n, r;
int x[MAXN], y[MAXN];
map<int, vector<pair<pair<int, int>, int> > > g;



struct rmq
{
	vector<int> d;
	vector<int> mod;
	int ss = 1;
	void init(int n) {
		while (ss < n) {
			ss <<= 1;
		}
		d.resize(2 * ss, 0);
		mod.resize(2 * ss, 0);
	}
	void push(int v) {
		if (mod[v] != 0) {
			d[v] += mod[v];
			if (v < ss) {
				mod[v * 2] += mod[v];
				mod[v * 2 +1] += mod[v];
			}
			mod[v] = 0;
		}
	}
	void add(int v, int vl, int vr, int l, int r, int x) {
		if (vl > r || vr < l) {
			push(v);
			return;
		}
		if (l <= vl && vr <= r) {
			mod[v] += x;
			push(v);
			return;
		}
		push(v);
		add(v * 2, vl, (vl + vr) / 2, l, r, x);
		add(v * 2 +1 , (vl + vr) / 2 + 1, vr, l, r, x);
		d[v] = max(d[v * 2], d[v * 2 + 1]);
	}
} kek;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> r;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		int xt = x[i] + y[i];
		int yt = x[i] - y[i];
		x[i] = xt;
		y[i] = yt;
	}
	for (int i = 0; i < n; i++) {
		g[x[i] - r].pb({{y[i] - r, y[i] + r}, 1});
		g[x[i] + r + 1].pb({{y[i] - r, y[i] + r}, -1});
	}
	kek.init(8000000);
	int ans = 0;
	for (auto z: g) {
		for (auto f: z.second) {
			kek.add(1, 1, kek.ss, f.first.first + 4000000, f.first.second + 4000000, f.second);
		}
		chkmax(ans, kek.d[1] + kek.mod[1]);
	}
	cout << ans << '\n';
	return 0;
}