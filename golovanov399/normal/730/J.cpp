//MIPT Cryptozoology
//Room 202
#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:128000000")
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <bitset>
#include <set>
#include <map>
#include <cassert>
#include <memory.h>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define itn int

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

typedef long long li;
typedef long long i64;
typedef double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

void precalc();

int TESTNUM = 0;
#define FILENAME ""

int main() {
	string s = FILENAME;
#ifdef YA
	//assert(!s.empty());
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//cerr<<FILENAME<<endl;
	//assert (s != "change me please");
	clock_t start = clock();
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(FILENAME ".in", "r", stdin);
	//freopen(FILENAME ".out", "w", stdout);
	cin.tie(0);
#endif
	cout.sync_with_stdio(0);
	cout.precision(10);
	cout << fixed;
	precalc();
	int t = 1;
	//cin >> t;
	while (t--) {
		++TESTNUM;
		solve();
	}
#ifdef YA
	cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
	return 0;
}

//#define int li

/*int pr[] = { 97, 2011 };
int mods[] = { 1000000007, 1000000009 };

const int C = 100500;
int powers[2][C];*/

//int MOD = 1000000007;

//int c[5010][5010];

template<typename T>
T binpow(T q, T w, T mod) {
	if (!w)
		return 1 % mod;
	if (w & 1)
		return q * 1LL * binpow(q, w - 1, mod) % mod;
	return binpow(q * 1LL * q % mod, w / 2, mod);
}

void precalc() {

	/*for (int w = 0; w < 2; ++w) {
	powers[w][0] = 1;
	for (int j = 1; j < C; ++j) {
	powers[w][j] = (powers[w][j - 1] * 1LL * pr[w]) % mods[w];
	}
	}*/

	/*for (int i = 0; i < 5010; ++i) {
	c[i][i] = c[i][0] = 1;
	for (int j = 1; j < i; ++j) {
	c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
	}
	}*/
}

template<typename T>
T gcd(T q, T w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}
template<typename T>
T lcm(T q, T w) {
	return q / gcd(q, w) * w;
}

inline int nxt(){
	int x;
	cin >> x;
	return x;
}

//#define int li

const int C = 100 * 101;

void solve() {
	int n;
	cin >> n;
	//n = 100;
	vector<int> a(n), b(n);
	int a_sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		//a[i] = rand() % 100;
		a_sum += a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		//b[i] = rand() % 100;
	}
	vector<vector<vector<int>>> dp(2, vector<vector<int>>(n + 1, vector<int>(C, 1e9)));
	dp[0][0][0] = 0;
	int par = 0;
	for (int i = 0; i < n; ++i) {
		dp[par ^ 1].assign(n + 1, vector<int>(C, 1e9));
		for (int used = 0; used <= i; ++used) {
			for (int sum = 0; sum < C; ++sum) {
				dp[par ^ 1][used][sum] = min(dp[par ^ 1][used][sum], dp[par][used][sum] + a[i]);
				if (sum + b[i] < C) {
					dp[par ^ 1][used + 1][sum + b[i]] = min(dp[par ^ 1][used + 1][sum + b[i]], dp[par][used][sum]);
				}
			}
		}
		par ^= 1;
	}

	int used = 0;
	while (true) {
		bool f = false;
		for (int sum = a_sum; sum < C; ++sum) {
			if (dp[par][used][sum] < 1e8) {
				f = true;
				break;
			}
		}
		if (f) {
			break;
		}
		++used;
	}

	cout << used << " ";
	int res = 1e9;
	for (int sum = a_sum; sum < C; ++sum) {
		res = min(res, dp[par][used][sum]);
	}
	cout << res << "\n";

}