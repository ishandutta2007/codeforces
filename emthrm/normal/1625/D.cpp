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
  constexpr int B = 30;
  int n, k; cin >> n >> k;
  if (k == 0) {
    cout << n << '\n';
    REP(i, n) cout << i + 1 << " \n"[i + 1 == n];
    return 0;
  }
  vector<int> a(n); REP(i, n) cin >> a[i];
  const auto g = [&](auto&& g, int b, const vector<int>& O, const vector<int>& I) -> vector<int> {
    if (O.empty() || I.empty()) return {};
    if (b < 0) return {O.front(), I.front()};
    int u = 0, v = 0;
    while (u < O.size() && !(a[O[u]] >> b & 1)) ++u;
    while (v < I.size() && !(a[I[v]] >> b & 1)) ++v;
    if (k >> b & 1) {
      vector<int> ans = g(g, b - 1, vector<int>(O.begin(), O.begin() + u), vector<int>(I.begin() + v, I.end()));
      if (!ans.empty()) return ans;
      return g(g, b - 1, vector<int>(O.begin() + u, O.end()), vector<int>(I.begin(), I.begin() + v));
    } else {
      if (u > 0 && v < I.size()) return {O.front(), I.back()};
      if (u < O.size() && v > 0) return {O.back(), I.front()};
      return g(g, b - 1, O, I);
    }
  };
  const int msb = 31 - __builtin_clz(k);
  vector<int> as[B]{};
  map<int, vector<int>> uniq;
  REP(i, n) uniq[a[i]].emplace_back(i);
  for (const auto [_, is] : uniq) {
    const int i = is.front();
    const int msb_i = (a[i] == 0 ? -1 : 31 - __builtin_clz(a[i]));
    as[max(msb_i, msb)].emplace_back(i);
  }
  vector<int> ans;
  const auto f = [&](auto&& f, int b, const vector<int>& v) -> void {
    if (v.empty()) return;
    vector<int> nxt[2]{};
    for (int i : v) nxt[a[i] >> b & 1].emplace_back(i);
    if (b == msb) {
      if (nxt[0].empty()) {
        ans.emplace_back(nxt[1].front());
      } else if (nxt[1].empty()) {
        ans.emplace_back(nxt[0].front());
      } else {
        vector<int> tmp = g(g, b - 1, nxt[0], nxt[1]);
        if (tmp.empty()) tmp = {nxt[0].front()};
        copy(ALL(tmp), back_inserter(ans));
      }
      return;
    }
    REP(i, 2) f(f, b - 1, nxt[i]);
  };
  FOR(i, msb, B) {
    sort(ALL(as[i]), [&](int l, int r) -> bool { return a[l] < a[r]; });
    f(f, i, as[i]);
  }
  const int l = ans.size();
  if (l < 2) {
    cout << "-1\n";
    return 0;
  }
  // REP(i, l) FOR(j, i + 1, l) assert((a[ans[i]] ^ a[ans[j]]) >= k);
  cout << l << '\n';
  REP(i, l) cout << ans[i] + 1 << " \n"[i + 1 == l];
  return 0;
}