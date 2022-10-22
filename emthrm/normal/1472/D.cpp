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
  vector<int> a[2];
  while (n--) {
    int ai; cin >> ai;
    a[ai & 1].emplace_back(ai);
  }
  REP(i, 2) sort(ALL(a[i]));
  ll score = 0;
  bool alice = true;
  while (!a[0].empty() || !a[1].empty()) {
    int cur = [&]() {
      REP(i, 2) {
        if (a[i].empty()) {
          int v = a[i ^ 1].back();
          a[i ^ 1].pop_back();
          return v;
        }
      }
      int x = 0;
      if (a[x].back() < a[x ^ 1].back()) x ^= 1;
      int v = a[x].back();
      a[x].pop_back();
      return v;
    } ();
    if (alice && cur % 2 == 0) score += cur;
    if (!alice && cur % 2 == 1) score -= cur;
    alice = !alice;
  }
  if (score > 0) {
    cout << "Alice\n";
  } else if (score == 0) {
    cout << "Tie\n";
  } else {
    cout << "Bob\n";
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}