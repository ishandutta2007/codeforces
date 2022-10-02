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
#include <iomanip>
 
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define rank rank228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;

// const int MAXMEM = 200 * 1000 * 1024;
// char _memory[MAXMEM];
// size_t _ptr = 0;
// void* operator new(size_t _x) { _ptr += _x; return _memory + _ptr - _x; }
// void operator delete (void*) noexcept {}
const string FILENAME = "input";
const int MAXN = 3505;



int n, m, k;
int a[MAXN];
int val[MAXN];


void solve() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int len = n - m + 1;
	for (int i = 0; i <= n - len; i++) {
		val[i] = max(a[i], a[i + len - 1]);
	}
	int ans = 0;
	for (int i = 0; i <= n - len; i++) {
		if (i > k) {
			break;
		}
		int res = 2e9;
		for (int j = i; j <= max(i, n - len - (k - i)); j++) {
			chkmin(res, val[j]);
		}
		chkmax(ans, res);
	}
	cout << ans << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	int z;
	cin >> z;
	while (z--) {
		solve();
	}
	return 0;
}