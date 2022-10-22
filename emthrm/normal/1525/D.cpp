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

// https://yukicoder.me/problems/no/1467
int main() {
  int m, n;
  vector<int> a, b;
  {
    cin >> n;
    REP(i, n) {
      int ai; cin >> ai;
      if (ai == 1) {
        a.emplace_back(i);
        a.emplace_back(i);
      }
    }
    m = a.size();
    b.resize(n);
    iota(ALL(b), 0);
  }
  sort(ALL(a));
  sort(ALL(b));
  vector<int> closest(m);
  REP(i, m) {
    closest[i] = lower_bound(ALL(b), a[i]) - b.begin();
    if (closest[i] == n || (closest[i] > 0 && a[i] - b[closest[i] - 1] <= b[closest[i]] - a[i])) --closest[i];
  }
  const int k = 1;
  {
    ll ans = 0;
    vector<deque<int>> used(n);
    REP(i, m) {
      if (used[closest[i]].size() < k) {
        used[closest[i]].emplace_back(i);
        ans += abs(b[closest[i]] - a[i]);
      } else {
        int l = closest[i] - 1, r = closest[i] + 1;
        while (l >= 0 && used[l].size() == k) --l;
        while (r < n && used[r].size() == k) ++r;
        ll l_cost = LINF, r_cost = LINF;
        if (l >= 0) {
          l_cost = 0;
          FOR(j, l, r) {
            if (j + 1 < n && !used[j + 1].empty()) {
              l_cost -= abs(b[j + 1] - a[used[j + 1].front()]);
              l_cost += abs(b[j] - a[used[j + 1].front()]);
            }
          }
          l_cost += abs(b[r == n || used[r].empty() ? r - 1 : r]  - a[i]);
        }
        if (r < n) r_cost = abs(b[r] - a[i]);
        if (l_cost <= r_cost) {
          ans += l_cost;
          FOR(j, l, r) {
            if (j + 1 < n && !used[j + 1].empty()) {
              used[j].emplace_back(used[j + 1].front());
              used[j + 1].pop_front();
            }
          }
          used[r == n || used[r].empty() ? r - 1 : r].emplace_back(i);
        } else {
          ans += r_cost;
          used[r].emplace_back(i);
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}