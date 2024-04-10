#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int n, q; cin >> n >> q;
  set<int> p;
  while (n--) {
    int pi; cin >> pi;
    p.emplace(pi);
  }
  multiset<int> dist;
  for (auto it = next(p.begin()); it != p.end(); ++it) dist.emplace(*it - *prev(it));
  auto solve = [&]() {
    if (dist.empty()) {
      cout << 0 << '\n';
    } else {
      cout << *p.rbegin() - *p.begin() - *dist.rbegin() << '\n';
    }
  };
  solve();
  while (q--) {
    int t, x; cin >> t >> x;
    if (t == 0) {
      auto it = p.lower_bound(x);
      assert(*it == x);
      int l = -1, r = -1;
      if (it != p.begin()) {
        l = *prev(it);
        dist.erase(dist.lower_bound(x - l));
      }
      if (next(it) != p.end()) {
        r = *next(it);
        dist.erase(dist.lower_bound(r - x));
      }
      p.erase(it);
      if (l != -1 && r != -1) dist.emplace(r - l);
    } else if (t == 1) {
      auto it = p.lower_bound(x);
      assert(it == p.end() || *it != x);
      int l = -1, r = -1;
      if (it != p.begin()) l = *prev(it);
      if (it != p.end()) r = *it;
      if (l != -1 && r != -1) dist.erase(dist.lower_bound(r - l));
      if (l != -1) dist.emplace(x - l);
      if (r != -1) dist.emplace(r - x);
      p.emplace(x);
    }
    solve();
  }
  return 0;
}