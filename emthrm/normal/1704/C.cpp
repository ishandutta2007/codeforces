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
  vector<int> a(m); REP(i, m) cin >> a[i], --a[i];
  sort(ALL(a));
  priority_queue<int> que;
  FOR(i, 1, m) {
    if (a[i - 1] + 1 < a[i]) que.emplace(a[i] - a[i - 1] - 1);
  }
  if (a.front() != 0 || a.back() != n - 1) que.emplace(a.front() + n - 1 - a.back());
  int ans = 0, day = 0;
  while (!que.empty()) {
    const int seg = que.top(); que.pop();
    if (seg <= day * 2) break;
    if (seg - day * 2 <= 2) {
      ++ans;
      ++day;
    } else {
      ans += seg - day * 2 - 1;
      day += 2;
    }
  }
  cout << n - ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}