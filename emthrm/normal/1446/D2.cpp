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
  vector<int> a(n); REP(i, n) cin >> a[i], --a[i];
  vector<vector<int>> cnt(n);
  REP(i, n) cnt[a[i]].emplace_back(i);
  int d, max_count = 0;
  REP(i, n) {
    if (cnt[i].size() > max_count) {
      d = i;
      max_count = cnt[i].size();
    }
  }
  REP(i, n) {
    if (i != d && cnt[i].size() == max_count) {
      cout << n << '\n';
      return 0;
    }
  }
  vector<int> prevd(n, -1), nextd(n, n);
  REP(i, n) prevd[i] = a[i] == d ? i : (i == 0 ? -1 : prevd[i - 1]);
  for (int i = n - 1; i >= 0; --i) nextd[i] = a[i] == d ? i : (i + 1 < n ? nextd[i + 1] : n);
  vector<int> rui(n, 0);
  REP(i, n) rui[i] = (a[i] == d) + (i > 0 ? rui[i - 1] : 0);
  int ans = 0;
  REP(v, n) {
    if (cnt[v].size() == 0 || v == d) continue;
    if (1LL * cnt[v].size() * cnt[v].size() <= n) {
      const vector<int> &vs = cnt[v];
      int x = vs.size();
      REP(i, x) FOR(j, i, x) {
        int p = vs[i], q = vs[j];
        int num_v = j - i + 1, num_d = rui[q] - (p == 0 ? 0 : rui[p - 1]);
        if (num_d > num_v) continue;
        int l = i == 0 ? -1 : vs[i - 1], r = j + 1 == x ? n : vs[j + 1];
        while (num_d < num_v) {
          if (a[p] == d) {
            if (p == 0 || prevd[p - 1] <= l) break;
            p = prevd[p - 1];
          } else {
            if (prevd[p] <= l) break;
            p = prevd[p];
          }
          ++num_d;
        }
        while (num_d < num_v) {
          if (a[q] == d) {
            if (q + 1 == n || nextd[q + 1] >= r) break;
            q = nextd[q + 1];
          } else {
            if (nextd[q] >= r) break;
            q = nextd[q];
          }
          ++num_d;
        }
        if (num_d < num_v) continue;
        auto solve = [&]() {
          assert(0 <= p && p <= q && q < n && rui[q] - (p == 0 ? 0 : rui[p - 1]) == num_v);
          int left = a[p] == d ? (p == 0 ? -1 : prevd[p - 1]) : prevd[p];
          chmax(left, l);
          ++left;
          int right = a[q] == d ? (q + 1 == n ? n : nextd[q + 1]) : nextd[q];
          chmin(right, r);
          --right;
          chmax(ans, right - left + 1);
        };
        solve();
        while (num_d <= num_v) {
          if (a[p] == d) {
            if (p + 1 < n && nextd[p + 1] < vs[i]) {
              p = nextd[p + 1];
              --num_d;
            }
          } else {
            if (nextd[p] < vs[i]) {
              p = nextd[p];
              --num_d;
            }
          }
          if (a[q] == d) {
            if (q + 1 == n || nextd[q + 1] >= r) break;
            q = nextd[q + 1];
            ++num_d;
          } else {
            if (nextd[q] >= r) break;
            q = nextd[q];
            ++num_d;
          }
          if (num_d > num_v && nextd[p] + 1 <= vs[i]) {
            --num_d;
            p = nextd[p] + 1;
          }
          if (num_d == num_v) solve();
        }
      }
    } else {
      vector<int> sum(n, 0);
      REP(i, n) {
        if (a[i] == d) ++sum[i];
        if (a[i] == v) --sum[i];
      }
      FOR(i, 1, n) sum[i] += sum[i - 1];
      int w = max(-*min_element(ALL(sum)), 0);
      REP(i, n) sum[i] += w;
      vector<vector<int>> pos(*max_element(ALL(sum)) + 1);
      for (int i = n - 1; i >= 0; --i) pos[sum[i]].emplace_back(i);
      REP(i, n) {
        if (!pos[w].empty() && nextd[i] <= pos[w].front()) chmax(ans, pos[w].front() - i + 1);
        if (a[i] == d) ++w;
        if (a[i] == v) --w;
        pos[w].pop_back();
      }
    }
  }
  cout << ans << '\n';
  return 0;
}