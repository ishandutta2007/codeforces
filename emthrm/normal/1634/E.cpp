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
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int m; cin >> m;
  vector<vector<int>> a(m);
  REP(i, m) {
    int n; cin >> n;
    a[i].resize(n);
    REP(j, n) cin >> a[i][j];
  }
  vector<int> nums;
  REP(i, m) copy(ALL(a[i]), back_inserter(nums));
  sort(ALL(nums));
  nums.erase(unique(ALL(nums)), nums.end());
  const int n = nums.size();
  vector<int> c(n, 0);
  REP(i, m) for (int& j : a[i]) {
    j = lower_bound(ALL(nums), j) - nums.begin();
    ++c[j];
  }
  REP(i, n) {
    if (c[i] % 2 == 1) {
      cout << "NO\n";
      return 0;
    }
    c[i] /= 2;
  }
  vector<string> ans(m);
  vector<unordered_set<int>> pos(n), rem(m);
  vector<unordered_map<int, int>> mp(m);
  REP(i, m) {
    ans[i] = string(a[i].size(), 'R');
    map<int, vector<int>> mp_sub;
    REP(j, a[i].size()) mp_sub[a[i][j]].emplace_back(j);
    for (auto& [a_ij, v] : mp_sub) {
      while (v.size() > 1) {
        ans[i][v.back()] = 'L';
        v.pop_back();
        v.pop_back();
      }
      if (!v.empty()) {
        pos[a_ij].emplace(i);
        rem[i].emplace(v.back());
        mp[i][a_ij] = v.back();
      }
    }
  }
  REP(i, m) {
    while (!rem[i].empty()) {
      int ver = i;
      do {
        const int idx = *rem[ver].begin();
        rem[ver].erase(rem[ver].begin());
        ans[ver][idx] = 'L';
        const int val = a[ver][idx];
        pos[val].erase(ver);
        ver = *pos[val].begin();
        pos[val].erase(pos[val].begin());
        rem[ver].erase(mp[ver][val]);
      } while (ver != i);
    }
  }
  cout << "YES\n";
  REP(i, m) cout << ans[i] << '\n';
  return 0;
}