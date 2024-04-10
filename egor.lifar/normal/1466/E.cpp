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



const int MAXN = 500228;


int n;
ll x[MAXN];
int cnt[60];
int a[60], b[60];


void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; i++) {
		for (int t = 0; t < 60; t++) {
			if (x[i] & (1LL << t)) {
				cnt[t]++;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (int t = 0; t < 60; t++) {
			if (x[i] & (1LL << t)) {
				a[t] = sum(a[t], cnt[t]);
				b[t] = sum(n, b[t]);
			} else {
				b[t] = sum(cnt[t], b[t]);
			}
		}
		int res = 0;
		for (int t = 0; t < 60; t++) {
			res = sum(res, mul((1LL << t) % Mod, b[t]));
		}
		for (int t = 0; t < 60; t++) {
			ans = sum(ans, mul(res, mul((1LL << t) % Mod, a[t])));
		}
	}
	cout << ans << '\n';
} 


int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
 	int t;
 	cin >> t;
 	while (t--) {
 		solve();
 	}
   	return 0;
}