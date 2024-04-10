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
const int MAXN = 400228;



int n;
int a[MAXN];
int b[MAXN];
int l[MAXN], r[MAXN];
int f[MAXN];


void inc(int i, int val) {
	for (int j = i; j < n; j |= (j + 1)) {
		chkmax(f[j], val);
	}
}

int get(int i) {
	int res = 0;
	for (int j = i; j >= 0; j = (j & (j + 1)) - 1) {
		chkmax(res, f[j]);
	}
	return res;
}


void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	for (int i = 0; i <= n; i++) {
		l[i] = 1e9;
		r[i] = -1;
		f[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		chkmin(l[a[i]], i);
		chkmax(r[a[i]], i);
	}
	int kek = 0;
	int cnt = 0;
	int last = 0;
	for (int i = 1; i <= n; i++) {
		if (r[i] == -1) {
			continue;
		}
		cnt++;
		int k = (r[last] < l[i] ? f[last]: 0) + 1;
		f[i] = k;
		last = i;
		chkmax(kek, f[i]);
	}
	cout << cnt - kek << endl;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	int q;
	cin >> q;
	for (int it = 0; it < q; it++) {
		solve();
	}
	return 0;
}