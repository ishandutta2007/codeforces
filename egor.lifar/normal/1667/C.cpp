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
bool badx[MAXN], bady[MAXN], badd[MAXN];
int c[1000][1000];


void solve() {
	cin >> n;
	if (n == 1 || n == 2) {
		cout << 1 << '\n';
		cout << 1 << ' ' << 1 << '\n';
		return;
	}
	int a = (n + 1) / 3;
	cout << 2 * a - 1 + (n % 3 == 2 ? 0: (n % 3 == 1 ? 2: 1))<< '\n';
	for (int i = 1; i <= a; i++) {
		cout << i << ' ' << a - i + 1 << '\n';
	}
	for (int i = 1; i <= a - 1; i++) {
		cout << 2 * a + i << ' ' << 2 * a + (a - 1 - i) + 1 << '\n';
	}
	if (n % 3 == 1) {
		cout << n - 1 << ' ' << n - 1 << '\n';
		cout << n << ' ' << n << '\n'; 
	} else if (n % 3 == 2) {

	} else if (n % 3 == 0) {
		cout << n << ' ' << n << '\n';
	}
}


int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;
	t = 1;
	//cin >> t;
	while (t--) {
	//	cerr << t << endl;
		solve();
	}
}