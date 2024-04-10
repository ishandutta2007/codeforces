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

constexpr int M = 10;

void solve() {
  int n; cin >> n;
  vector<int> a[M]{};
  REP(_, n) {
    int a_i; cin >> a_i;
    a[a_i % M].emplace_back(a_i);
  }
  if (!a[5].empty()) {
    for (const int a_i : a[5]) a[0].emplace_back(a_i + 5);
  }
  if (!a[0].empty()) {
    sort(ALL(a[0]));
    cout << (a[0].size() == n && a[0].front() == a[0].back() ? "Yes\n" : "No\n");
    return;
  }
  for (const int m : vector<int>{1, 3, 7, 9}) {
    for (const int a_i : a[m]) a[m * 2 % M].emplace_back(a_i + m);
    a[m].clear();
  }
  for (const int m : vector<int>{2, 4, 8, 6}) {
    for (const int a_i : a[m]) a[m * 2 % M].emplace_back(a_i + m);
    a[m].clear();
    // REP(i, M) cout << a[i].size() << " \n"[i + 1 == M];
  }
  assert(a[2].size() == n);
  FOR(i, 1, n) {
    if (a[2][i] % (M * 2) != a[2][i - 1] % (M * 2)) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}