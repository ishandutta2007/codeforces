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
const int MAXN = 200228;


int n, k, m;



struct rmq
{
	vector<ll> mod;
	vector<ll> d;
	int ss = 1;
	void init(int n) {
		while (ss < n) {
			ss <<= 1;
		}
		mod.resize(2 * ss);
		d.resize(2 * ss);
	}
	void push(int v) {
		if (mod[v] != 0) {
			d[v] += mod[v];
			if (v < ss) {
				mod[v * 2] += mod[v];
				mod[v * 2 + 1] += mod[v];
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
		add(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, x);
		d[v] = max(d[v * 2], d[v * 2 + 1]);
	}
	ll get(int v, int vl, int vr, int l, int r) {
		if (vl > r || vr < l) {
			return -1e18;
		}
		if (l <= vl && vr <= r) {
			return d[v] + mod[v];
		}
		push(v);
		return max(get(v * 2, vl, (vl + vr) / 2, l, r), get(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r));
	}
	void add(int l, int r, int x) {
		add(1, 1, ss, l + 1, r + 1, x);
	}
	ll get(int l, int r) {
		return get(1, 1, ss, l + 1, r + 1);
	}
};



map<pair<int, int>, int> used;
multiset<int> st;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
 	cin >> n >> k >> m;
 	k--;
 	rmq	kek;
 	kek.init(2 * n);
 	for (int i = 0; i < 2 * n; i++) {
 		kek.add(i, i, -(2 * n - i));
 	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		int val = abs(x - k) + y;
		int mod = 0;
		if (!used[mp(x, y)]) {
			mod = 1;
			used[mp(x, y)]++;
			st.insert(val);
		} else {
			mod = -1;
			used[mp(x, y)]--;
			st.erase(st.find(val));
		}
		kek.add(0, val, mod);
		if (st.empty()) {
			cout << 0 << '\n';
			continue;
		}
		auto it = st.end();
		it--;
		int r = *it;
		int h = max(r + 1, 2 * n + (int)kek.get(0, r));
		cout << max(0, h - n) << '\n';
	}
	return 0;	 	
}