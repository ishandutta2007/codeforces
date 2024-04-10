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
  vector<pair<int, int>> b;
  b.reserve(n);
  for (int i = 0; i < n;) {
    int j = i + 1;
    while (j < n && a[j] == a[i]) ++j;
    b.emplace_back(a[i], j - i);
    i = j;
  }
  vector<int> tmp;
  tmp.reserve(n);
  REP(_, n - 1) {
    int z = 0;
    for (const auto& [_, len] : b) {
      z += len - 1;
    }
    const int b_size = b.size();
    FOR(i, 1, b_size) tmp.emplace_back(b[i].first - b[i - 1].first);
    sort(ALL(tmp));
    b.clear();
    if (z > 0) b.emplace_back(0, z);
    for (int i = 0; i < b_size - 1;) {
      int j = i + 1;
      while (j < b_size - 1 && tmp[j] == tmp[i]) ++j;
      b.emplace_back(tmp[i], j - i);
      i = j;
    }
    tmp.clear();
  }
  cout << b.front().first << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}