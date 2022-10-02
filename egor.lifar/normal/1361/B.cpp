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
const int Mod = 1000000007;
const int MAXN = 1000228;


int sum(int a, int b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
	return ((ll)a * b % Mod);
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

int n, p;
int k[MAXN];


void solve() {
	cin >> n >> p;
	for (int i = 0; i < n; i++) {
		cin >> k[i];
	}
	if (p == 1) {
		if (n % 2 == 0) {
			cout << 0 << '\n';
		} else {
			cout << 1 << '\n';
		}
		return;
	}
	sort(k, k + n);
	bool ok = false;
	int last = MAXN;
	int uk = n - 1;
	ll ans = 0;
	ll sums = 0;
	for (int i = n - 1; i >= 0; i--) {
		int x = k[i];
		int diff = last - x;
		last = x;
		ans = mul(ans, powm(p, diff));
		for (int i = 0; i < min(diff, 20); i++) {
			sums *= p;
			if (sums > MAXN) {
				ok = true;
				break;
			}
		}
		while (uk >= 0 && k[uk] == x) {
			if (ok || sums > 0) {
				sums--;
				ans = sum(ans, Mod - 1);
			} else {
				sums++;
				ans = sum(ans, 1);
			}
			uk--;
		}
	}
	ans = mul(ans, powm(p, last));
	cout << ans << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0; 	
}