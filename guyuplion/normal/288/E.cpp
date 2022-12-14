#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <initializer_list>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#define oo 0x3F3F3F3F
#ifdef DEBUG
#define cvar(x) cerr << "<" << #x << ": " << x << ">"
#define evar(x) cvar (x) << endl
template<class T> void DISP(const char *s, T x, int n) {cerr << "[" << s << ": "; for (int i = 0; i < n; ++i) cerr << x[i] << " "; cerr << "]" << endl;}
#define disp(x,n) DISP(#x " to " #n, x, n)
#else
#define cvar(...) ({})
#define evar(...) ({})
#define disp(...) ({})
#endif
#define car first
#define cdr second
#define PB push_back
#define SZ(x) (int)((x).size())
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (int _end_ = (b), i = (a); i <= _end_; ++i)
#define ROF(i, a, b) for (int _end_ = (b), i = (a); i >= _end_; --i)

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef long double real;

int64 fpm(int64 b, int64 e, int64 m) { int64 t = 1; for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0; return t; }
template<class T> inline bool chkmin(T &a, T b) {return a > b ? a = b, true : false;}
template<class T> inline bool chkmax(T &a, T b) {return a < b ? a = b, true : false;}
template<class T> inline T sqr(T x) {return x * x;}
template <typename T> T gcd(T x, T y) {for (T t; x; t = x, x = y % x, y = t); return y; }

template<class edge> struct Graph
{
  vector<vector<edge> > adj;
  Graph(int n) {adj.clear (); adj.resize (n + 5);}
  Graph() {adj.clear (); }
  void resize(int n) {adj.resize (n + 5); }
  void add(int s, edge e){adj[s].push_back (e);}
  void del(int s, edge e) {adj[s].erase (find (iter (adj[s]), e)); }
  vector<edge>& operator [](int t) {return adj[t];}
};

const int N = 110000, mod = 1000000007;

int64 f[N], g[N], M2[N], Mb[N];
char L[N], R[N];
int64 inv9 = fpm(9, mod - 2, mod);

int64 calc(char *x)
{
	int n = strlen(x); int64 ret = 0, pre = 0;
	FOR (i, 0, n - 1) {
		int y = n - 1 - i; // how many digit remains
		if (x[i] == '7') { // update ret
			int64 b = (Mb[y] - 1) * inv9 % mod;
			ret += ((pre + 7 * Mb[y] + 4 * b) % mod) * ((pre + 4 * Mb[y] + 7 * b) % mod) % mod; // cross
			int64 p = (pre + 4 * Mb[y]) % mod;
			ret += (M2[y] - 1) * p % mod * p % mod; // A^2
			ret += g[y] * p % mod;		      // A * (x1 + x2)
			ret += f[y];				      // x1 * x2
		}
		// update using current digit
		pre = (pre + Mb[y] * (x[i] - '0')) % mod;
	}
	return ret % mod;
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
	freopen("E.in" , "r", stdin);
	freopen("E.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);

	f[1] = 28, g[1] = 11;
	M2[0] = Mb[0] = 1;
	FOR (i, 1, N - 2) {
		M2[i] = M2[i - 1] * 2 % mod;
		Mb[i] = Mb[i - 1] * 10 % mod;
	}

	FOR (i, 1, N - 2) {
		int64 p10 = Mb[i], p2 = M2[i] - 1, b = (p10 - 1) * inv9 % mod;
		f[i + 1] = (2 * f[i] + 65 * p10 % mod * p10 % mod * p2 % mod + 
			    11 * p10 % mod * g[i] % mod + 
			    ((4 * p10 + b * 7) % mod) * ((7 * p10 + b * 4) % mod) % mod) % mod;
		g[i + 1] = (2 * g[i] + 11 * p10 % mod * 2 * p2 % mod + 11 * (10 * b % mod + 1) % mod) % mod;
	}

	cin >> L >> R;
	cout << (calc(R) + mod - calc(L)) % mod << endl;

	return 0; 
}