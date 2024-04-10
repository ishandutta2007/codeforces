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
const int MAXN = 100228;



int n;
int a[MAXN];
int b[MAXN];


void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n % 2 == 1) {
		cout << "NO\n";
		return;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			b[i] = a[i / 2];
		} else {
			b[i] = a[i / 2 + n / 2];
		}
	}
	for (int i = 0; i < n; i++) {
		int c = (i + 1 == n ? b[0]: b[i + 1]);
		int d = (i - 1 == -1 ? b[n - 1]: b[i - 1]);
		if (b[i] < min(c, d) || b[i] > max(c, d)) {
			continue;
		}
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			b[i] = a[i / 2];
			cout << a[i / 2];
		} else {
			b[i] = a[i / 2 + n / 2];
			cout << a[i / 2 + n / 2];
		}
		cout << ' ';
	}
	cout << '\n';
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