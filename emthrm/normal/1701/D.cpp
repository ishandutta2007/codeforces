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
  vector<tuple<int, int, int>> segments(n);
  for (int i = 1; i <= n; ++i) {
    int b; cin >> b;
    if (b == 0) {
      segments[i - 1] = {i + 1, n, i};
    } else {
      segments[i - 1] = {(i + 1 + b) / (b + 1), i / b, i};
    }
  }
  sort(ALL(segments), greater{});
  vector<int> a(n);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
  for (int i = 1; i <= n; ++i) {
    while (!segments.empty() && get<0>(segments.back()) <= i) {
      const auto [_, r, id] = segments.back();
      segments.pop_back();
      que.emplace(r, id);
    }
    assert(!que.empty());
    const auto [r, id] = que.top();
    que.pop();
    assert(i <= r);
    a[id - 1] = i;
  }
  REP(i, n) cout << a[i] << " \n"[i + 1 == n];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}