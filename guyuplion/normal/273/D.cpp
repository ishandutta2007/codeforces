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
template<class T> void DISP (const char *s, T x, int n) {cerr << "[" << s << ": "; for (int i = 0; i < n; ++i) cerr << x[i] << " "; cerr << "]" << endl;}
#define disp(x,n) DISP (#x " to " #n, x, n)
#else
#define cvar(...) ({})
#define evar(...) ({})
#define disp(...) ({})
#endif
#define MKP make_pair
#define Px first
#define Py second
#define PB push_back
#define SZ(x) (int)((x).size ())
#define ALL(x) (x).begin (), (x).end ()

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef long double real;
typedef unordered_map<int, int> UMII;
typedef unordered_set<int> USI;

int64 fpm (int64 b, int64 e, int64 m) { int64 t = 1; for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0; return t; }
template<class T> inline bool chkmin (T &a, T b) {return a > b ? a = b, true : false;}
template<class T> inline bool chkmax (T &a, T b) {return a < b ? a = b, true : false;}
template<class T> inline T sqr (T x) {return x * x;}

template<class edge> struct Graph
{
  vector<vector<edge> > adj;
  Graph (int n) {adj.clear (); adj.resize (n + 5);}
  Graph () {adj.clear (); }
  void resize (int n) {adj.resize (n + 5); }
  void add (int s, edge e){adj[s].push_back (e);}
  void del (int s, edge e) {adj[s].erase (find (iter (adj[s]), e)); }
  int deg (int v) {return adj[v].size (); }
  vector<edge>& operator [](int t) {return adj[t];}
};

const int maxn = 153, mod = 1000000007;

int64 f[maxn][maxn][maxn][4], S[4][maxn][maxn];

int64 sum(int s, int li, int ri, int lj, int rj)
{
	--li, --lj;
	if (li < 0) li = 0;
	if (lj < 0) lj = 0;
	return S[s][ri][rj] - S[s][ri][lj] - S[s][li][rj] + S[s][li][lj];
}

int main ()
{
#ifndef ONLINE_JUDGE
	freopen ("D.in" , "r", stdin);
	freopen ("D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio (false);

	int n, m; int64 ans = 0;
	
	cin >> n >> m;
	for (int L = 1; L <= m; ++L) {
		for (int s = 0; s < 4; ++s) {
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					S[s][i][j] = S[s][i - 1][j] + S[s][i][j - 1] - S[s][i - 1][j - 1] + f[L - 1][i][j][s];
		}
		for (int i = 1; i <= n; ++i)
			for (int j = i; j <= n; ++j) {
				for (int s = 0; s < 4; ++s) {
					auto &v = f[L][i][j][s];

					if (L == 2 && i == 1 && j == 2 && s == 0) {
						cerr << 1 << endl;
					}
					if (s == 0) {
						v = sum(0, i, j, i, j) + 1;
					} else if (s == 1) {
						v = sum(0, 1, i - 1, i, j) + sum(1, 1, i, i, j);
					} else if (s == 2) {
						v = sum(0, i, j, j + 1, n) + sum(2, i, j, j, n);
					} else if (s == 3) {
						v = sum(0, 1, i - 1, j + 1, n) +
							sum(1, 1, i, j + 1, n) +
							sum(2, 1, i - 1, j, n) +
							sum(3, 1, i, j, n);
					}
					v %= mod;
					ans += v;
				}
			}
	}

	cout << ans % mod << endl;
	return 0; 
}