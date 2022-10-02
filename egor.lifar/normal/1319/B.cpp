#include <bits/stdc++.h>


using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define rank rank228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;
// const int MAXMEM = 200 * 1000 * 1024;
// char _memory[MAXMEM];
// size_t _ptr = 0;
// void* operator new(size_t _x) { _ptr += _x; return _memory + _ptr - _x; }
// void operator delete (void*) noexcept {}
const string FILENAME = "input";
const int MAXN = 200228;


int n;
ll b[MAXN];
ll dp[MAXN * 10];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	read(FILENAME);
	cin >> n;
	for  (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	ll res = 0;
	for (int i = 0; i < n; i++) {
		//i - j == b[i] - b[j];
		//i - b[i] == j - b[j];
		dp[i] = b[i] + dp[i - b[i] + 400228];
		chkmax(dp[i - b[i] + 400228], dp[i]);
		chkmax(res, dp[i]);
	}
	cout << res << '\n';
}