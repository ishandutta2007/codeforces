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

int main() {
  int n; cin >> n;
  auto query = [&](int r) -> vector<int> {
    cout << "? " << r + 1 << endl;
    vector<int> d(n); REP(i, n) cin >> d[i];
    return d;
  };
  vector<int> r0 = query(0);
  vector<vector<int>> dist(*max_element(ALL(r0)) + 1);
  REP(i, n) dist[r0[i]].emplace_back(i);
  vector<int> a, b;
  int f = 0;
  for (int i = 1; i < dist.size(); i += 2) f += dist[i].size();
  if (f <= (n - 1) / 2) {
    for (int i = 1; i < dist.size(); i += 2) {
      for (int ai : dist[i]) {
        vector<int> d = query(ai);
        REP(j, n) {
          if (d[j] == 1) {
            a.emplace_back(ai);
            b.emplace_back(j);
          }
        }
      }
    }
  } else {
    a.assign(dist[1].size(), 0);
    copy(ALL(dist[1]), back_inserter(b));
    for (int i = 2; i < dist.size(); i += 2) {
      for (int ai : dist[i]) {
        vector<int> d = query(ai);
        REP(j, n) {
          if (d[j] == 1) {
            a.emplace_back(ai);
            b.emplace_back(j);
          }
        }
      }
    }
  }
  assert(a.size() == n - 1);
  cout << "!\n";
  REP(i, n - 1) cout << a[i] + 1 << ' ' << b[i] + 1 << endl;
  return 0;
}