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
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  sort(ALL(a));
  priority_queue<ll> que;
  que.emplace(accumulate(ALL(a), 0LL));
  while (!que.empty() && que.size() <= a.size()) {
    const ll w = que.top(); que.pop();
    if (w == a.back()) {
      a.pop_back();
    } else if (w < a.back()) {
      cout << "NO\n";
      return;
    } else {
      que.emplace(w / 2);
      que.emplace((w + 1) / 2);
    }
  }
  cout << (que.empty() && a.empty() ? "YES\n" : "NO\n");
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}