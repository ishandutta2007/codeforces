#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iomanip>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
const ld PI = acosl(ld(-1));

int c, w, h;

inline bool read()
{
	if (!(cin >> c >> w >> h))
		return false;
			
	return true;
}

const int N = 105;
typedef int mt[N][N];

void copy(mt a, mt b) {
	forn(i, N)
		forn(j, N)
			b[i][j] = a[i][j];
}

const int MOD = int(1e6) + 3;

int add(int a, int b) {
	return (a + b) % MOD;
}

void inc(int &a, int b) {
	a = add(a, b);
}

int mul(int a, int b) {
	return (a * 1ll * b) % MOD;
}

void mul(mt a, mt b, mt c) {
	forn(i, N)
		forn(j, N) {
			c[i][j] = 0;
			forn(k, N)
				inc(c[i][j], mul(a[i][k], b[k][j]));	
		}
}

mt tmp;

void binpow(mt a, int b, mt d) {
	mt c;
	forn(i, N)
		forn(j, N)
			c[i][j] = (i == j);
			
	while (b) {
		if (b & 1) {
			mul(a, c, tmp);
			copy(tmp, c);
		}			
		
		mul(a, a, tmp);
		copy(tmp, a);
		b >>= 1;

	}
	
	copy(c, d);
}

mt dp;

inline void solve()
{
	memset(dp, 0, sizeof(dp));
	forn(i, w) {
		inc(dp[i][i + 1], h);
		inc(dp[i][0], 1);
	}
	inc(dp[w][0], 1);
	
	binpow(dp, c, dp);
	int res = 0;
	forn(i, w + 1)
		inc(res, dp[0][i]);
	cout << res << endl;				
}

int main()
{
#ifdef SU2_PROJ
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));

	while (read()) {
		solve();
	}

#ifdef SU2_PROJ
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}