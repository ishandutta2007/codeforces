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
  vector<int> ca(n), cb(n);
  REP(i, n) cin >> ca[i], --ca[i];
  REP(i, n) cin >> cb[i], --cb[i];
  vector<int> q(n);
  REP(i, n) q[cb[i]] = i;
  vector<int> len[2]{};
  vector<int> is_visited(n, false);
  REP(s, n) {
    int l = 0;
    for (int p = s; !is_visited[p]; p = q[ca[p]]) {
      is_visited[p] = true;
      ++l;
    }
    len[l & 1].emplace_back(l);
  }
  ll ans = 0;
  int le = 0, ri = n - 1;
  sort(ALL(len[0]), greater<int>());
  for (int l : len[0]) {
    vector<int> a;
    ri -= l / 2;
    REP(d, l / 2) {
      a.emplace_back(le++);
      a.emplace_back(ri + 1 + d);
    }
    REP(i, l) ans += abs(a[i] - a[(i + 1) % l]);
  }
  sort(ALL(len[1]), greater<int>());
  vector<vector<int>> last(len[1].size());
  REP(i, len[1].size()) {
    const int l = len[1][i];
    ri -= l / 2;
    REP(d, l / 2) {
      last[i].emplace_back(le++);
      last[i].emplace_back(ri + 1 + d);
    }
  }
  REP(i, len[1].size()) {
    last[i].emplace_back(le++);
    const int l = len[1][i];
    REP(j, l) ans += abs(last[i][j] - last[i][(j + 1) % l]);
  }
  cout << ans << '\n';
  // {
  //   int answer = 0;
  //   vector<int> color(n);
  //   iota(ALL(color), 0);
  //   do {
  //     int score = 0;
  //     REP(i, n) score += abs(color[ca[i]] - color[cb[i]]);
  //     chmax(answer, score);
  //   } while (next_permutation(ALL(color)));
  //   assert(answer == ans);
  // }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;

  // int ans = 0;
  // vector<int> a(n), b;
  // iota(ALL(a), 0);
  // do {
  //   int score = 0;
  //   REP(i, n) score += abs(a[i] - a[(i + 1) % n]);
  //   if (chmax(ans, score)) b = a;
  // } while (next_permutation(ALL(a)));
  // REP(i, n) cout << b[i] << " \n"[i + 1 == n];
}