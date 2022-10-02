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
const int MAXN = 300228;



struct rmq
{
	int ss = 1;
	vector<int> d;
	void init(int n) {
		while (ss < n) {
			ss <<= 1;
		}
		d.resize(2 * ss);
		for (int i = 0; i < 2 * ss; i++) {
			d[i] = 1e9;
		}
	}
	void change(int i, int x) {
		i += ss;
		d[i] = x;
		while (i >> 1 > 0) {
			i >>= 1;
			d[i] = min(d[i * 2], d[i * 2 + 1]);
		}
	}
	int get(int l, int r) {
		l += ss;
		r += ss;
		int res = 1e9;
		while (l <= r) {
			if (l & 1) {
				chkmin(res, d[l]);
				l++;
			}
			if (!(r & 1)) {
				chkmin(res, d[r]);
				r--;
			}
			l >>= 1;
			r >>= 1;
		}
		return res;
	}
};



int n;
int a[MAXN];
rmq kek, kek1;
int g[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	int fk = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		chkmax(fk, a[i]);
	}
	for (int i = n; i < 2 * n; i++) {
		a[i] = a[i - n];
	}
	kek.init(2 * n);
	for (int i = 0; i < 2 * n; i++) {
		kek.change(i, a[i]);
	}
	for (int i = 0; i < n; i++) {
		int l = i;
		int r = i + n;
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			if (kek.get(i, mid) * 2 < a[i]) {
				r = mid - 1;
			} else {
				l = mid;
			}
		}
		g[i] = l;
		g[i + n] = l + n;
	}
	kek1.init(2 * n);
	for (int i = 0; i < 2 * n; i++) {
		kek1.change(i, g[i]);
	}
	for (int i = 0; i < n; i++) {
		int l = i;
		int r = i + n;
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			if (kek1.get(i, mid) < mid) {
				r = mid - 1;
			} else {
				l = mid;
			}
		}
		if (r == i + n) {
			int f = fk;
			int l = i;
			int r = i + n;
			while (l < r) {
				int mid = (l + r + 1) >> 1;
				if (kek.get(i, mid) * 2 < f) {
					r = mid - 1;
				} else {
					l = mid;
				}
			}
			if (l == i + n) {
				cout << -1 << ' ';
			} else {
				cout << n + 1 + l - i << ' ';
			}
		} else {
			cout << r - i + 1 << ' ';
		}
	}
	cout << '\n';
 	return 0;
}