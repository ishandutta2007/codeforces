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
constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
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
  int n, q; cin >> n >> q;
  vector<int> a(n); REP(i, n) cin >> a[i], --a[i];
  deque<int> deq;
  REP(i, n) deq.emplace_back(i);
  vector<vector<int>> win(n);
  for (int rd = 1; rd <= n; ++rd) {
    int x = deq[0], y = deq[1];
    REP(_, 2) deq.pop_front();
    if (a[x] < a[y]) swap(x, y);
    deq.emplace_front(x);
    deq.emplace_back(y);
    win[x].emplace_back(rd);
  }
  while (q--) {
    int i, k; cin >> i >> k; --i;
    cout << upper_bound(ALL(win[i]), k) - win[i].begin() + (deq.front() == i ? max(k - n, 0) : 0) << '\n';
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}