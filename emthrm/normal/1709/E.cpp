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

int main() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<vector<int>> graph(n);
  REP(_, n - 1) {
    int x, y; cin >> x >> y; --x; --y;
    graph[x].emplace_back(y);
    graph[y].emplace_back(x);
  }
  vector<int> al(n, 0);
  vector<set<int>> s(n);
  int ans = 0;
  auto f = [&](auto&& f, int par, int ver) -> void {
    bool must_change = false;
    for (int e : graph[ver]) {
      if (e == par) continue;
      f(f, ver, e);
      must_change |= s[e].count(al[e] ^ a[ver]);
      if (s[ver].size() < s[e].size()) {
        swap(s[ver], s[e]);
        swap(al[ver], al[e]);
      }
      for (int child : s[e]) must_change |= s[ver].count(child ^ al[e] ^ al[ver] ^ a[ver]);
      for (int child : s[e]) s[ver].emplace(child ^ al[e] ^ al[ver]);
    }
    s[ver].emplace(al[ver]);
    al[ver] ^= a[ver];
    if (must_change) {
      ++ans;
      s[ver].clear();
    }
  };
  f(f, -1, 0);
  cout << ans << '\n';
  return 0;
}