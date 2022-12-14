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

const int maxn = 222000;

int64 a[maxn];
map<pair<int, bool>, pair<int64, int>> f;
set<pair<int, bool>> S;
int n;

pair<int64, int> dfs(int x, bool b)
{
	if (x <= 0 || x > n) return make_pair(0, 0);
	if (x == 1) {
		if (b) return make_pair(0, 2);
		return make_pair(0, 1);
	}
	auto p = make_pair(x, b);
	if (S.count(p)) return make_pair(0, 2);
	if (f.count(p)) return f[p];
	S.insert(p);
	f[p] = dfs(b ? (x + a[x]) : (x - a[x]), !b);
	f[p].fst += a[x];
	S.erase(p);
	return f[p];
}

int main ()
{
#ifndef ONLINE_JUDGE
	freopen("B.in" , "r", stdin);
	freopen("B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio (false);
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i < n; ++i) {
		auto x = dfs(i + 1, 0);
		if (x.snd == 2) {
			cout << -1 << endl;
		} else if (x.snd == 1) {
			cout << x.fst + i * 2 << endl;
		} else {
			cout << x.fst + i << endl;
		}
	}

	return 0; 
}