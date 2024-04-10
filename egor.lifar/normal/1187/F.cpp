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
    
     
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; } 
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228                                                         
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
const string FILENAME = "input";
const int Mod = 1000000007;
const int MAXN = 200228;


int sum(int a, int b) {
    return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
    return (1LL * a * b) % Mod;
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
int l[MAXN], r[MAXN];
long long p[MAXN];
long long p1[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> r[i];
	}
	for (int i = 0; i < n; i++) {
		p[i] = powm(r[i] - l[i] + 1, Mod - 2);
	}
	int ans = 0;
	for (int i = 0; i < n - 2; i++) {
		int x = max({l[i], l[i + 1], l[i + 2]});
		int y = min({r[i], r[i + 1], r[i + 2]});
		if (x <= y) {
			ans = sum(ans, mul(mul(y - x + 1, p[i]), mul(p[i + 1], p[i + 2])));
		}
	}
	int res = 0;
	for (int i = 0; i < n - 1; i++) {
		int x = max({l[i], l[i + 1]});
		int y = min({r[i], r[i + 1]});
		if (x <= y) {
			p1[i] = mul(y - x + 1, mul(p[i], p[i + 1]));
			res = sum(res, p1[i]);
		}
	}
	ans = sum(ans, ans);
	for (int i = 0; i < n - 1; i++) {
		long long ft = res - p1[i] - (i == 0 ? 0: p1[i - 1]) - (i == n - 2 ? 0: p1[i + 1]);
		ft %= Mod;
		ft += Mod;
		ft %= Mod;
		ans = sum(ans, mul(p1[i], ft));
	}
	ans = sum(ans, res);
	int g = (1LL * n * n - 2LL * n * res + ans) % Mod;
	cout << (g + Mod) % Mod << '\n';
	return 0; 			
}