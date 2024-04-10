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

const int maxn = 55, mod = 1000000007;

int w[maxn];
int64 f[maxn * 4][maxn][maxn], cb[maxn][maxn];

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
	freopen("C.in" , "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);

	int n, k;

	cin >> n >> k, k /= 50;

	int ma = 0, mb = 0;
	FOR (i, 1, n) {
		int w;
		cin >> w, w /= 50;
		if (w == 1) ++ma;
		else ++mb;
	}
	FOR (i, 0, n) {
		FOR (j, 0, n) {
			cb[i][j] = j ? (cb[i - 1][j - 1] + cb[i - 1][j]) % mod : 1;
		}
	}

	f[0][ma][mb] = 1;
	FOR (x, 0, n * 4) {
		ROF (i, ma, 0) {
			ROF (j, mb, 0) {
				f[x][i][j] %= mod;
				if (!f[x][i][j]) continue;
				FOR (p, 0, i) {
					FOR (q, 0, j) {
						if (!p && !q) continue;
						if (p + 2 * q > k) break;
						int64 r = f[x][i][j] * cb[i][p] % mod * cb[j][q] % mod;
						f[x + 1][ma - i + p][mb - j + q] += r;
					}
				}
			}
		}
		if ((~x & 1) && f[x + 1][ma][mb]) {
			cout << x + 1 << endl
			     << f[x + 1][ma][mb] % mod << endl;
			return 0;
		}
	}
	cout << -1 << endl
	     << 0 << endl;

	return 0; 
}