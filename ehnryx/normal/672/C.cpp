//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define FILENAME sadcactus

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

ld sqr(ld x) { return x*x; }

template <class T>
struct Min2 {
  T a, b;
  Min2(T init): a(init), b(init) {}
  void push(T v) {
    if(v < a) {
      b = a;
      a = v;
    } else if(v < b) {
      b = v;
    }
  }
};

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(10);
#if defined(ONLINE_JUDGE) && defined(FILENAME)
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif

  int ax, ay, bx, by, tx, ty;
  cin >> ax >> ay >> bx >> by >> tx >> ty;

  int n;
  cin >> n;
  ld sum = 0;
  Min2<pair<ld,int>> av(make_pair(1e19, 0)), bv(make_pair(1e19, 0));
  for(int i=0; i<n; i++) {
    int x, y;
    cin >> x >> y;
    ld cur = sqrt(sqr(tx - x) + sqr(ty - y));
    sum += 2 * cur;
    av.push(make_pair(sqrt(sqr(ax - x) + sqr(ay - y)) - cur, i));
    bv.push(make_pair(sqrt(sqr(bx - x) + sqr(by - y)) - cur, i));
  }

  ld best = min(av.a.first, bv.a.first) + sum;
  if(n > 1) {
    if(av.a.second != bv.a.second) {
      best = min(best, av.a.first + bv.a.first + sum);
    } else {
      best = min(best, min(av.a.first + bv.b.first, av.b.first + bv.a.first) + sum);
    }
  }
  cout << best << nl;

  return 0;
}