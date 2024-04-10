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
  vector<vector<int>> a(n, vector<int>(n)); REP(i, n) REP(j, n) cin >> a[i][j];
  vector<map<int, vector<int>>> b(n);
  REP(i, n) REP(j, n) {
    if (j != i) b[i][a[i][j]].emplace_back(j);
  }
  vector<int> cur(n);
  iota(ALL(cur), 0);
  auto comp = [&](int l, int r) { return b[l].size() > b[r].size(); };
  set<int> que;
  REP(i, n) que.emplace(i);
  vector<int> c(n);
  REP(i, n) c[i] = a[i][i];
  vector<int> v, u;
  while (que.size() > 1) {
    int idx = *que.begin();
    for (auto it = next(que.begin()); it != que.end(); ++it) {
      if (b[*it].size() > b[idx].size()) idx = *it;
    }
    vector<int> child{idx};
    for (int e : b[idx].begin()->second) {
      if (cur[e] != -1) {
        que.erase(e);
        child.emplace_back(e);
      }
    }
    int id = c.size();
    c.emplace_back(b[idx].begin()->first);
    for (int e : child) {
      v.emplace_back(cur[e]);
      u.emplace_back(id);
      cur[e] = -1;
    }
    cur[idx] = id;
    b[idx].erase(b[idx].begin());
    que.emplace(idx);
  }
  int k = c.size();
  cout << k << '\n';
  REP(i, k) cout << c[i] << " \n"[i + 1 == k];
  cout << cur[*que.begin()] + 1 << '\n';
  assert(v.size() == k - 1);
  REP(i, k - 1) cout << v[i] + 1 << ' ' << u[i] + 1 << '\n';
  return 0;
}