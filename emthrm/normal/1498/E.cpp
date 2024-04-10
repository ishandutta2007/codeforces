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

constexpr int C = 100000;

int main() {
  int n; cin >> n;
  vector<int> k(n); REP(i, n) cin >> k[i];
  int node = n;
  vector<bool> alive(n, true);
  int all_out = -1;
  REP(i, n) {
    if (k[i] == 0) {
      all_out = i;
      break;
    }
  }
  while (all_out != -1) {
    alive[all_out] = false;
    --node;
    int nx = -1;
    REP(ver, n) {
      if (alive[ver]) {
        --k[ver];
        if (k[ver] == 0) {
          assert(nx == -1);
          nx = ver;
        }
      }
    }
    swap(all_out, nx);
  }
  while (node > 0) {
    int all_in = -1;
    REP(ver, n) {
      if (alive[ver] && k[ver] == node - 1) {
        all_in = ver;
        break;
      }
    }
    if (all_in == -1) break;
    alive[all_in] = false;
    --node;
  }
  vector<pair<int, int>> ab;
  REP(i, n) FOR(j, i + 1, n) {
    if (alive[i] && alive[j]) ab.emplace_back(i, j);
  }
  sort(ALL(ab), [&](const pair<int, int> &a, const pair<int, int> &b) -> bool {
    return abs(k[a.first] - k[a.second]) > abs(k[b.first] - k[b.second]);
  });
  for (auto [a, b] : ab) {
    if (k[a] < k[b]) swap(a, b);
    cout << "? " << a + 1 << ' ' << b + 1 << endl;
    string res; cin >> res;
    if (res == "Yes") {
      cout << "! " << a + 1 << ' ' << b + 1 << endl;
      return 0;
    }
  }
  cout << "! 0 0" << endl;
  return 0;
}