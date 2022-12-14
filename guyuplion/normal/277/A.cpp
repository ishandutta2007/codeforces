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

const int maxn = 500;

int ufs[maxn];
bool v[maxn][maxn];

int find(int t) 
{
	return ufs[t] ? ufs[t] = find(ufs[t]) : t;
}

int main ()
{
#ifndef ONLINE_JUDGE
	freopen("A.in" , "r", stdin);
	freopen("A.out", "w", stdout);
#endif
	ios_base::sync_with_stdio (false);

	int n, m, ans;

	cin >> n >> m, ans = n;
	for (int i = 1; i <= n; ++i) {

		int k, t;
		cin >> k;
		if (k) ans = n - 1;
		for (; k--; ) {
			cin >> t;
			v[i][t] = true;
		}
	}
	cerr << ans << endl;
	
	for (int i = 1; i <= m; ++i) {
		int r = 0;
		for (int j = 1; j <= n; ++j) {
			if (v[j][i]) {
				if (r) {
					int x = find(j), y = find(r);
					if (x != y) {
						ufs[x] = y;
						--ans;
					}
				} else {
					r = j;
				}
			}
		}
	}

	cout << ans << endl;
	return 0; 
}