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
const int MAXN = 100229;



int n;
ll a[MAXN];
ll kek[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << 1 << ' ' << 1 << '\n';
		cout << 0 << '\n';
		cout << 1 << ' ' << 1 << '\n';
		cout << 0 << '\n';
		cout << 1 << ' ' << 1 << '\n';
		cout << -a[0] << '\n';
		return 0;
	}
	for (int i = 0; i < n; i++) {
		kek[((ll)(n - 1) * i) % n] = (ll)(n - 1) * i; 
	}
	cout << 1 << ' ' << n - 1 << '\n';
	for (int i = 0; i < n - 1; i++) {
		ll need = (n - (a[i] % n + n) % n) % n;
		cout << kek[need] << ' ';
		a[i] += kek[need];
	}
	cout << '\n';
	cout << 2 << ' ' << n << '\n';
	for (int i = 1; i < n; i++) {
		ll need = (n - (a[i] % n + n) % n) % n;
		cout << kek[need] << ' ';
		a[i] += kek[need];
	}
	cout << '\n';
	for (int i = 0; i < n; i++) {
		assert(a[i] % n == 0);
	}
	cout << 1 << ' ' << n << '\n';
	for (int i = 0; i < n; i++) {
		cout << -a[i] << ' ';
	}
	cout << '\n';
}