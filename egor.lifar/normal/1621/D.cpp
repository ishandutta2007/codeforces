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


const int MAXN = 505;


int n;
ll c[MAXN][MAXN];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
ll dist[MAXN][MAXN];
bool used[MAXN][MAXN];

 
void solve() {
	cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			cin >> c[i][j];
			used[i][j] = false;
			dist[i][j] = 1e18;
		}
	}
	ll add = 0;
	for (int i = n; i < 2 * n; i++) {
		for (int j = n; j < 2 * n; j++) {
			add += c[i][j];
			c[i][j] = 0;
		}
	}
	ll val = min(min(c[2 * n - 1][n - 1], c[n - 1][2 * n - 1]), min(c[n][n - 1], c[n - 1][n]));
	chkmin(val, c[0][2 * n - 1]);
	chkmin(val, c[2 * n - 1][0]);
	chkmin(val, c[n][0]);
	chkmin(val, c[0][n]);
	cout << val + add << '\n';
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