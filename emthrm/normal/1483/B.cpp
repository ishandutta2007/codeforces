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
  set<int> st, rem;
  REP(i, n) {
    st.emplace(i);
    rem.emplace(i);
  }
  int cur = 0;
  vector<int> ans;
  while (!st.empty()) {
    auto it = rem.upper_bound(cur);
    int nx = (it == rem.end() ? *rem.begin() : *it);
    if (gcd(a[cur], a[nx]) == 1) {
      ans.emplace_back(nx);
      st.erase(nx);
      rem.erase(nx);
      auto it2 = st.upper_bound(cur);
      cur = (it2 == st.end() ? *st.begin() : *it2);
    } else {
      st.erase(cur);
      if (st.empty()) break;
      auto it2 = st.lower_bound(cur);
      cur = (it2 == st.end() ? *st.begin() : *it2);
    }
  }
  int k = ans.size();
  cout << k << " \n"[k == 0];
  REP(i, k) cout << ans[i] + 1 << " \n"[i + 1 == k];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}