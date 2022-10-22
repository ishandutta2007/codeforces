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

int query(const int a, const int b) {
  cout << "? " << a + 1 << ' ' << b + 1 << endl;
  int n; cin >> n;
  assert(n != -1);
  return n;
}

int win(const int a, const int b) {
  return query(a, b) == 1 ? a : b;
}

void solve() {
  int n; cin >> n;
  vector<int> winners(1 << n);
  iota(ALL(winners), 0);
  while (winners.size() >= 4) {
    const int m = winners.size();
    assert(m % 4 == 0);
    vector<int> nxt;
    for (int i = 0; i < m; i += 4) {
      if (const int q = query(winners[i], winners[i + 2]); q == 0) {
        nxt.emplace_back(win(winners[i + 1], winners[i + 3]));
      } else if (q == 1) {
        nxt.emplace_back(win(winners[i], winners[i + 3]));
      } else {
        nxt.emplace_back(win(winners[i + 2], winners[i + 1]));
      }
    }
    winners.swap(nxt);
  }
  if (winners.size() == 2) {
    const int winner = win(winners[0], winners[1]);
    cout << "! " << winner + 1 << endl;
  } else {
    cout << "! " << winners.front() + 1 << endl;
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}