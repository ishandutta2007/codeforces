#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  map<int, vector<int>> mp;
  REP(i, n) mp[-a[i]].emplace_back(i);
  if (mp.begin()->second.size() >= 3) {
    int mid = mp.begin()->second[1];
    cout << "YES\n" << mid << ' ' << 1 << ' ' << n - mid - 1 << '\n';
    return;
  }
  int l = mp.begin()->second.front(), r = mp.begin()->second.back();
  int mn = *min_element(a.begin() + l, a.begin() + r + 1);
  auto yes = [&]() {
    assert(l >= 1 && r <= n - 2);
    int x_max = *max_element(a.begin(), a.begin() + l);
    int y_min = *min_element(a.begin() + l, a.begin() + r + 1);
    assert(y_min == mn);
    int z_max = *max_element(a.begin() + r + 1, a.end());
    assert(x_max == y_min && y_min == z_max);
    int z = n - 1 - r;
    cout << "YES\n" << l << ' ' << n - l - z << ' ' << z << '\n';
  };
  for (auto it = next(mp.begin()); it != mp.end(); ++it) {
    const vector<int> &pos = it->second;
    if (pos.size() >= 3 && -it->first <= mn && pos.front() < l && r < pos.back()) {
      auto it = lower_bound(ALL(pos), l);
      if (it != pos.end() && *it <= r) {
        yes();
        return;
      }
      if (it != pos.begin() && it != pos.end()) {
        if (prev(it) != pos.begin() && *prev(it) + 1 == l) {
          chmin(mn, a[--l]);
          yes();
          return;
        }
        if (next(it) != pos.end() && r + 1 == *it) {
          chmin(mn, a[++r]);
          yes();
          return;
        }
      }
    }
    for (int e : pos) {
      while (l > e) chmin(mn, a[--l]);
      while (r < e) chmin(mn, a[++r]);
    }
  }
  cout << "NO\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}