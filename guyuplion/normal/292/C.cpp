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

int y[50], x[50], o[50];
char s[50];
int top, n;
vector<string> vec;

bool ck(int l, int r)
{
	if (r - l > 3) return false;
	int v = 0;
	FOR (i, l + 1, r)
		v = v * 10 + y[i];
	if (v > 255) return false;
	if (v != 0 && y[l + 1] == 0) return false;
	if (v == 0 && r - l != 1) return false;
	return true;
}

void dfs2(int d, int t, int c, int lx)
{
	s[top++] = y[d] + '0';
	if (d == t) {
		if (c == 3 && ck(lx, t)) s[top] = '\0', vec.push_back(s);
		--top;
		return ;
	}
	dfs2(d + 1, t, c, lx);
	if (c != 3 && ck(lx, d)) {
		s[top++] = '.';
		dfs2(d + 1, t, c + 1, d);
		--top;
	}
	--top;
}

void check(bool b, int d)
{
	int t = d - b;
	ROF (i, d, 1)
		y[++t] = y[i];
	dfs2(1, t, 0, 0);
}

void dfs(int d, int w)
{
	if (y[1] == 7 && y[2] == 8 && y[3] == 1 && y[4] == 9 && y[5] == 0 && d == 7)
		top = 0;
	if (w == 0 && d >= 2) check(0, d - 1);
	if (w == 0 && d >= 3) check(1, d - 1);
	if (d == 7) return ;
	FOR (i, 1, n) {
		y[d] = x[i];
		++o[i];
		dfs(d + 1, w - (o[i] == 1));
		--o[i];
	}
}

int main(int argc, char **argv)
{
#ifndef ONLINE_JUDGE
	freopen("C.in" , "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin >> n;
	FOR (i, 1, n) {
		cin >> x[i];
	}
	dfs(1, n);

	cout << SZ(vec) << endl;
	for (auto &s : vec)
		cout << s << endl;

	return 0; 
}