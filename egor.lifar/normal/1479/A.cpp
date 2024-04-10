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
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}


int inv(int a) {
    return powm(a, Mod - 2);
}


const int MAXN = 100228;


int n;
int a[MAXN];


int myquery(int i) {
	if (i < 1 || i > n) {
		return 1e9;
	}
	if (a[i] != -1) {
		return a[i];
	}
	cout << "? " << i << endl;
	int x;
	cin >> x;
	a[i] = x;
	return a[i];
}


void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		a[i] = -1;
	}
	a[0] = 1e9;
	a[n + 1] = 1e9;
	if (n == 1) {
		cout << "! " << 1 << endl;
		return;
	}
	int t = myquery(1);
	int t1 = myquery(2);
	if (t < t1) {
		cout << "! " << 1 << endl;
		return;
	}
	int l = 2;
	int r = n;
	while (l + 3 < r) {
		int mid = (l + r) >> 1;
		int a = myquery(mid - 1);
		int b = myquery(mid);
		int c = myquery(mid + 1);
		if (b < a && b < c) {
			cout << "! " << mid << endl;
			return; 
		}
		if (a < b && b < c) {
			r = mid - 1;
			continue;
		}
		if (a > b && b > c) {
			l = mid + 1;
			continue;
		}
		if (a < b && b > c) {
			r = mid - 1;
			continue;
		}
	}
	for (int i = l; i <= r; i++) {
		int a = myquery(i - 1);
		int b = myquery(i);
		int c = myquery(i + 1);
		if (b < a && b < c) {
			cout << "! " << i << endl;
			return; 
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);
     //read(FILENAME);
   	int t;
   	t = 1;
  //	cin >> t;
   	while (t--) {
   		solve();
   	}
   	return 0;
}