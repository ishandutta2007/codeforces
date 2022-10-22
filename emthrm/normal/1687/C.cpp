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
constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};
constexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n, m; cin >> n >> m;
  vector<ll> a(n); REP(i, n) cin >> a[i];
  REP(i, n) {
    int b; cin >> b;
    a[i] -= b;
  }
  vector<int> l(m), r(m); REP(i, m) cin >> l[i] >> r[i], --l[i], --r[i];
  vector<vector<int>> has(n + 1);
  REP(i, m) {
    has[l[i]].emplace_back(i);
    has[r[i] + 1].emplace_back(i);
  }
  vector<int> counter(m, 2);
  queue<int> que;
  auto add = [&](int i) -> void {
    for (int id : has[i]) {
      if (--counter[id] == 0) que.emplace(id);
    }
  };
  add(0);
  set<int> rem;
  FOR(i, 1, n + 1) rem.emplace(i);
  REP(i, n) {
    if (i > 0) a[i] += a[i - 1];
    if (a[i] == 0) {
      add(i + 1);
      rem.erase(i + 1);
    }
  }
  if (a.back() != 0) {
    cout << "NO\n";
    return;
  }
  while (!que.empty()) {
    const int id = que.front(); que.pop();
    for (auto it = rem.lower_bound(l[id]); it != rem.end() && *it <= r[id] + 1; it = rem.erase(it)) {
      add(*it);
    }
  }
  cout << (rem.empty() ? "YES\n" : "NO\n");
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}