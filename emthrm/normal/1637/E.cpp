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
  map<int, int> a;
  while (n--) {
    int ai; cin >> ai;
    ++a[ai];
  }
  set<pair<int, int>> bad;
  while (m--) {
    int x, y; cin >> x >> y;
    bad.emplace(x, y);
  }
  map<int, vector<int>> cnts;
  for (const auto [ai, cnt] : a) cnts[cnt].emplace_back(ai);
  ll ans = 0;
  for (auto it1 = cnts.begin(); it1 != cnts.end(); it1 = next(it1)) {
    const int it1_size = it1->second.size();
    const ll first_term = it1->first * 2;
    int r = -1;
    for (int i = it1_size - 1; i >= 0 && r < it1_size - 1; --i) {
      for (int j = it1_size - 1; j > r; --j) {
        if (j != i && !bad.count(minmax(it1->second[i], it1->second[j]))) {
          chmax(ans, first_term * (it1->second[i] + it1->second[j]));
          r = j;
          break;
        }
      }
    }
    for (auto it2 = next(it1); it2 != cnts.end(); it2 = next(it2)) {
      const int it2_size = it2->second.size();
      const ll first_term = it1->first + it2->first;
      int r = -1;
      for (int i = it1_size - 1; i >= 0 && r < it2_size - 1; --i) {
        for (int j = it2_size - 1; j > r; --j) {
          if (!bad.count(minmax(it1->second[i], it2->second[j]))) {
            chmax(ans, first_term * (it1->second[i] + it2->second[j]));
            r = j;
            break;
          }
        }
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}