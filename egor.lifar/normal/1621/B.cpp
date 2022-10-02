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
template<typename T1, typename T2> inline bool chkmin(T1 &a, T2 b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<typename T1, typename T2> inline bool chkmax(T1 &a, T2 b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
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
const int Mod = 998244353;


int sum(int a, int b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
	return ((ll)a * b) % Mod;
}


int powm(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = mul(res, a);
		}
		b >>= 1;
		a = mul(a, a);
	}
	return res;
}



int n;
map<pair<int, int>, int> m;

 
void solve() {
	cin >> n;
	int minl = 1e9 + 2;
	int costl = 1e9 + 2;
	int maxr = 0;
	int costr = 1e9 + 2;
	m.clear();
	for (int i = 0; i < n; i++) {
		int l, r, c;
		cin >> l >> r >> c;
		if (m.find(mp(l, r)) == m.end()) {
			m[mp(l, r)] = c;
		} else {
			chkmin(m[mp(l, r)], c);
		}
		if (maxr < r) {
			maxr = r;
			costr = c;
		} else if (maxr == r) {
			chkmin(costr, c);
		}
		if (minl > l) {
			minl = l;
			costl = c;
		} else if (minl == l) {
			chkmin(costl, c);
		}
		ll res = costl + costr;
		if (m.find(mp(minl, maxr)) != m.end()) {
			chkmin(res, m[mp(minl, maxr)]);
		}
		cout << res << '\n';
	}	
}


int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;
	t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}