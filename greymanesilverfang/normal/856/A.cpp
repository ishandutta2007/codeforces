// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <functional>
#include <utility>
#include <algorithm>
#include <iomanip>

// Containers
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>

using namespace std;

// Macros
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define endl '\n'
#define _dbn cerr << endl
#define _dbi(a) for (int x: (a)) cerr << x << " ";_dbn
#define _dbl(a) for (ll x: (a)) cerr << x << " ";_dbn
#define _dbp(a) for (pi x: (a)) cerr << x.fi << " " << x.se << endl
#define _dbg(a) cerr << #a << " = " << (a) << endl
#define _dbt(a) cerr << #a << " = {" << (a).fi << ", " << (a).se << "}" << endl
#define IOS ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(a) (int)a.size()
#define len(a) (int)a.length()
#define emp(a) a.empty()
#define gcd __gcd
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define clr(a, x) memset((a), (x), sizeof(a))
#define cpy(a, b) memcpy((a), (b), sizeof(a))
#define _sp setprecision
#define cb1 __builtin_popcountll
#define cl0 __builtin_clz
#define ct0 __builtin_ctz
#define lg2(x) ((sizeof(x) >> 3) - cl0(x))
#define gbit(x, i) ((x >> i) & 1)
#define nbit(x) (x & (-x))
#define sbit(x, i) (x | (1LL << i))
#define obit(x, i) (x & (~(1LL << i)))
#define pq priority_queue
#define sqr(x) (x)*(x)
#define cub(x) (x)*(x)*(x)
#define fout(n) _fout(n),putchar(' ')

#define prev prev2910
#define next next2910

// Typedefs
typedef long long          ll;
typedef long double        ld;
typedef unsigned long long ul;
typedef pair < int, int >  pi;
typedef pair < ll, ll >    pl;
typedef vector < int >     vi;
typedef vector < ll >      vl;
typedef vector < pi >      vp;
typedef set < int >        si;
typedef set < pi >         sp;
typedef map < int, int >   mi;
typedef queue < int >      qi;
typedef queue < pi >       qp;
typedef multiset < int >   ti;

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree < int, less < int >, null_type, rb_tree_tag, tree_order_statistics_node_update > ordset;
*/

// Constants
const int base = 31;
const int _mod = 2147483629;
const int mod  = 1e9 + 7;
const int inf  = 0x3f3f3f3f;
const ll linf  = 0x3f3f3f3f3f3f3f3fLL;

const double eps = 1e-9;
const double Pi  = 3.141592653589793; // 15 precisions

const double deg_rad = Pi / 180.0;
const double rad_deg = 180.0 / Pi;

// Debugs
template < typename T > void _err (T t) { cerr << t << " "; }
template < typename T, typename... _T >
      void _err (T t, _T... args) {
            cerr << t << " ";
            _err(args...);
      }

// Templates
template < typename T > inline void Max (T& a, T b) { if (b > a) a = b; }
template < typename T > inline void Min (T& a, T b) { if (b < a) a = b; }
template < typename T, typename _T >
      inline T pw (T b, _T e) {
            T rep = 1;
            for (; e; e >>= 1, b *= b) rep = rep * (e & 1 ? b : 1);
            return rep;
      }
template < typename T, typename _T, typename __T >
      inline T pw_m (T b, _T e, __T mod) {
            T rep = 1;
            for (; e; e >>= 1, b = b * b % mod) rep = rep * (e & 1 ? b : 1) % mod;
            return rep;
      }
template < typename T >
      inline void fin (T& n) {
            n = 0;
            char c = getchar();
            bool neg = 0;
            while (c != '-' && (c < '0' || c > '9')) c = getchar();
            if (c == '-') {
                  neg = 1;
                  c = getchar();
            }
            while (c >= '0' && c <= '9') {
                  n = (n << 3) + (n << 1) + c - '0';
                  c = getchar();
            }
            if (neg) n *= (-1);
      }
template < typename T >
      inline void _fout (T n) {
            if (n < 0) {
                  putchar('-');
                  _fout(-n);
                  return;
            }
            if (n / 10) _fout(n / 10);
            putchar(n % 10 + '0');
      }

// Geo
struct Point {
      int x, y;
      Point() {}
      Point(int _x, int _y): x(_x), y(_y) {}
      ll sqrdist (Point p) {
            return 1LL * (p.x - x) * (p.x - x) + 1LL * (p.y - y) * (p.y - y);
      }
      ld dist (Point p) {
            return sqrt(1LL * (p.x - x) * (p.x - x) + 1LL * (p.y - y) * (p.y - y));
      }
      int mahdist (Point p) {
            return abs(p.x - x) + abs(p.y - y);
      }
      void rot (Point O, int angle) { // negative angle = rotate clockwise
            double c = cos(angle * deg_rad), s = sin(angle * deg_rad);
            x += ((O.x - x) * c) - ((y - O.y) * s);
            y += ((y - O.y) * c) - ((O.x - x) * s);
      }
};

// Solution

const int N = 101, M = 1000001;

int a[N], b[N], mark[M];

int main() {
      #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
      #endif
      clr(mark, -1);
      int t;
      fin(t);
      while (t--) {
            int n, k = 1;
            bool ok = 1;
            fin(n);
            for (int i = 1; i <= n; ++i) fin(a[i]);
            sort(a + 1, a + n + 1);
            for (int i = 1; i <= n; ++i) {
                  while (k < M && mark[k] == t) ++k;
                  if (k >= M) {
                        ok = 0;
                        break;
                  }
                  b[i] = k;
                  for (int j = 1; j <= n; ++j) {
                        int tmp = b[i] + a[j];
                        for (int z = 1; z <= n; ++z)
                              if ((tmp - a[z]) < M && (tmp - a[z]) > 0) mark[tmp - a[z]] = t;
                  }
            }
            if (!ok) {
                  puts("NO");
                  continue;
            }
            puts("YES");
            for (int i = 1; i <= n; ++i) fout(b[i]);
            puts("");
      }
      return 0;
}