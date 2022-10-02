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
const int MAXN = 1000228;
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


int n, k;
int v[MAXN], u[MAXN];


void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int ans = 1;
	for (int i = 0; i < k; i++) {
		ans = mul(ans, i + 1);
	}
	for (int i = 0; i < n - k; i++) {
		if (v[i] == -1) {
			ans = mul(ans, i + k + 1);
		} else {
			if (v[i] == 0) {
				ans = mul(ans, k + 1);
			}
		}
	}	
	for (int i = n - k; i < n; i++) {
		if (v[i] != -1 && v[i] != 0) {
			cout << 0 << '\n';
			return;
		}
	}
	cout << ans << '\n';
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