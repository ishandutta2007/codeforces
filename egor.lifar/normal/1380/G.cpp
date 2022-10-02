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
const int MAXN = 300228;


int sum(int a, int b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}

int mul(int a, int b) {
	return ((ll)a * b)% Mod;
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


int n;
int c[MAXN];
int pref[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	sort(c, c + n);
	pref[0] = c[0];
	for (int i = 1; i < n; i++) {
		pref[i] = sum(pref[i - 1], c[i]);
	}
	for (int k = 1; k <= n; k++) {
		int ans = 0;
 		int have = n - k;
 		int level = 0;
 		while (have) {
 			level++;
 			int need = min(k, have);
 			ans = sum(ans, mul(level, sum(pref[have - 1], Mod - (have - need == 0 ? 0: pref[have - need - 1]))));
 			have -= need;
 		}
 		ans = mul(ans, powm(n, Mod - 2));
		cout << ans << '\n';
	}
}