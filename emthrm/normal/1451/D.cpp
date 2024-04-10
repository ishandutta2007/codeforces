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

void solve1() {
  int d, k; cin >> d >> k;
  vector gru(d + 1, vector(d + 1, -1));
  for (int i = d / k * k; i >= 0; i -= k) {
    ll sq = 1LL * d * d - 1LL * i * i;
    int lb = 0, ub = d + 1;
    while (ub - lb > 1) {
      int mid = (lb + ub) >> 1;
      (1LL * mid * mid <= sq ? lb : ub) = mid;
    }
    for (int j = lb / k * k; j >= 0; j -= k) {
      vector<int> adj;
      if (i + k <= d && gru[i + k][j] != -1) adj.emplace_back(gru[i + k][j]);
      if (j + k <= d && gru[i][j + k] != -1) adj.emplace_back(gru[i][j + k]);
      sort(ALL(adj));
      adj.erase(unique(ALL(adj)), adj.end());
      REP(x, adj.size()) {
        if (adj[x] != x) {
          gru[i][j] = x;
          break;
        }
      }
      if (gru[i][j] == -1) gru[i][j] = adj.size();
    }
    // for (int j = 0; j <= lb / k * k; j += k) cout << gru[i][j] << " \n"[j == lb / k * k];
  }
  cout << (gru[0][0] > 0) << " \n"[d == k];
}

void solve2() {
  int d, k; cin >> d >> k;
  int x = 0;
  while (2LL * (x + k) * (x + k) <= 1LL * d * d) x += k;
  cout << (1LL * (x + k) * (x + k) + 1LL * x * x <= 1LL * d * d ? "Ashish\n" : "Utkarsh\n");
}

int main() {
  int t; cin >> t;
  while (t--) solve2();
  return 0;
}