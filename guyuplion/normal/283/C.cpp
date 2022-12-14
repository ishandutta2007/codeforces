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
#define fst first
#define snd second
#define PB push_back
#define SZ(x) (int)((x).size())
#define ALL(x) (x).begin(), (x).end()

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef long double real;

int64 pow(int64 b, int64 e, int64 m) { int64 t = 1; for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0; return t; }
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

const int maxn = 330, maxt = 110000, mod = 1000000007;

int a[maxn], ufs[maxn], ind[maxn];
int64 f[maxt], t;
Graph<int> G;

int find(int x) 
{
	return ufs[x] ? ufs[x] = find(ufs[x]) : x;
}

void dfs(int x)
{
	for (auto &y : G[x]) {
		dfs(y);
		a[x] += a[y];
		t -= a[y];
	}
}

int main ()
{
#ifndef ONLINE_JUDGE
	freopen("C.in" , "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio (false);

	int n, q;

	cin >> n >> q >> t, G.resize(n);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= q; ++i) {
		int b, c;
		
		cin >> b >> c;
		G.add(c, b);
		if (find(b) == find(c)) {
			cout << 0 << endl;
			return 0;
		} else {
			ufs[find(b)] = find(c);
		}
		++ind[b];
	}
	for (int i = 1; i <= n; ++i) {
		if (!ind[i]) {
			dfs(i);
		}
	}
	if (t < 0) {
		cout << 0 << endl;
		return 0;
	}

	f[0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= t; ++j) {
			if (j >= a[i]) {
				f[j] = (f[j] + f[j - a[i]]) % mod;
			}
		}
	}
	cout << f[t] << endl;

	return 0; 
}