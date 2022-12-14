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
#if __cplusplus > 201103L
#include <initializer_list>
#include <unordered_map>
#include <unordered_set>
#endif

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

const int U = 1100000, maxn = U;
const real eps = 1e-10;

int n; real tot;
set<real> S[U * 2 + 10];
int x[maxn], y[maxn];
int w[maxn];

real work()
{
	real ret = 0;
	FOR (i, 0, U + U) S[i].clear();
	FOR (i, 1, n) {
		int l = i, r = i % n + 1;
		if (x[l] > x[r]) swap(l, r);
		if (x[l] == x[r]) {
			S[x[l] + U].insert(y[l]);
			S[x[r] + U].insert(y[r]);
			continue;
		}
		FOR (a, x[l], x[r]) {
			S[a + U].insert((real)(1ll * y[l] * (x[r] - a) + 1ll * y[r] * (a - x[l])) / (x[r] - x[l]));
		}
	}

	real S0 = 0, S1 = 0, S2 = 0;
	FOR (i, -U, U) {
		if (!SZ(S[i + U])) continue;
		real l = *S[i + U].begin(), r = *--S[i + U].end();
		int lb = ceil(l - eps);
		int rb = floor(r + eps);
		real v = rb - lb + 1;
		// cerr << i << " " << v << " " << l << " " << r << " " << lb << " " << rb << " " << SZ(S[i + U]) << endl;
		ret += v * (S2 - 2 * S1 * i + S0 * i * i);
		S2 += 1.0 * v * i * i;
		S1 += 1.0 * v * i;
		S0 += 1.0 * v;
		// w[i] = v;
		// S0 += w[i];
	}
	// FOR (i, -10, 10) {
	// 	FOR (j, -10, 10) {
	// 		ret += 1.0 * w[i] * w[j] * sqr(i - j);
	// 	}
	// }
	cerr << "ret: " << ret << " " << S0 << endl;
	if (tot) assert(tot == S0);
	tot = S0;
	FOR (i, 1, n) swap(x[i], y[i]);
	return ret;
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
	freopen("D.in" , "r", stdin);
	freopen("D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);

	cin >> n;
	FOR (i, 1, n) {
		cin >> x[i] >> y[i];
	}

	cout << setprecision(15) << (work() + work()) / tot / (tot - 1) << endl;
	return 0; 
}