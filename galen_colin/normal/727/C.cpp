#include <bits/stdc++.h>
#include <chrono> 
 
using namespace std;
using namespace std::chrono; 
 
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #pragma optimization_level 3
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define f0rd(a, b) for (long long a = b; a >= 0; a--)
#define f1rd(a, b, c) for (long long a = b; a >= c; a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define mp make_pair
#define f first
#define s second
#define presum(p, a, n) {p[0] = a[0]; for (int i = 1; i < n; i++) p[i] = a[i] + p[i-1];}
#define all(v) v.begin(), v.end()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);}
#define ai(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
#define ain(a, lb, rb) for (int ele = lb; ele <= rb; ele++) cin >> a[ele];
#define ao(a, n) {for (int ele = 0; ele < n; ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
#define aout(a, lb, rb) {for (int ele = lb; ele <= rb; ele++) { if (ele > lb) cout << " "; cout << a[ele]; } cout << '\n';}
typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
 
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
 
// template<typename A, typename B> ll max(A x, B y) {
//   return x > y ? x : y;
// }
// template<typename A, typename B> ll min(A x, B y) {
//   return x < y ? x : y;
// }
 
mt19937 rng(steady_clock::now().time_since_epoch().count());
/* usage - just do rng() */
 
void usaco(string filename) {
  #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
const ll mod = 1000000007;

struct convex_hull {
  using TYPE = ll;
  using point = pair<TYPE, TYPE>;
  vector<point> points;
  vector<point> hull_up, hull_down, hull_tot;

  void add_point(TYPE a, TYPE b) {
    points.push_back(make_pair(a, b));
  }

  /* sort by x, then y */
  static bool point_comp(point a, point b) {
    return a.f < b.f || (a.f == b.f && a.s < b.s);
  } 

  /*
  -1 - clockwise
  0 - collinear
  1 - counterclockwise
  */
  int orient(point a, point b, point c) {
    TYPE val = a.f * (b.s - c.s) + b.f * (c.s - a.s) + c.f * (a.s - b.s);

    if (val < 0) return -1;
    else if (val > 0) return 1;
    return 0;
  }

  void find_hull() {
    if (points.size() == 1) {
      hull_up = hull_down = hull_tot = points;
      return;
    }
    sort(points.begin(), points.end(), point_comp);

    point p1 = points[0], p2 = points.back();

    hull_up.push_back(p1);
    hull_down.push_back(p1);

    int sz = (int)points.size();
    for (int i = 1; i < sz; i++) {
      /* end or clockwise */
      if (i == points.size() - 1 || orient(p1, points[i], p2) == -1) {
        /* while not cw */
        while (hull_up.size() >= 2 && orient(hull_up[hull_up.size() - 2], hull_up.back(), points[i]) != -1)
          hull_up.pop_back();
        hull_up.push_back(points[i]);
      }

      /* end or ccw */
      if (i == points.size() - 1 || orient(p1, points[i], p2) == 1) {
        /* while not ccw */
        while (hull_down.size() >= 2 && orient(hull_down[hull_down.size() - 2], hull_down.back(), points[i]) != 1) 
          hull_down.pop_back();
        hull_down.push_back(points[i]);
      }
    }

    for (int i = 0; i < (int)hull_up.size(); i++)     
      hull_tot.push_back(hull_up[i]);
    for (int i = hull_down.size() - 2; i > 0; i--) 
      hull_tot.push_back(hull_down[i]);
  }
};

ll n, m, k, q, Q, T, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;

ll su[5001];

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  // freopen("file.in", "r", stdin);
 
  // usaco("file");

  cin >> n;
  f1r(i, 1, n) {
    cout << "? " << 1 << " " << i + 1 << endl;
    cin >> su[i - 1];
  }

  cout << "? " << 2 << " " << 3 << endl;
  cin >> x;

  a[0] = (su[0] + su[1] - x) / 2;
  f1r(i, 1, n) a[i] = su[i - 1] - a[0];

  cout << "!";
  f0r(i, n) {
    cout << " " << a[i];
  }
  cout << endl;
}