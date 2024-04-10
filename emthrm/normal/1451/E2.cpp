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

int query(int type, int i, int j) {
  if (type == 0) {
    cout << "AND ";
  } else if (type == 1) {
    cout << "OR ";
  } else if (type == 2) {
    cout << "XOR ";
  } else {
    while (true);
  }
  cout << i + 1 << ' ' << j + 1 << endl;
  int x; cin >> x;
  while (x == -1);
  return x;
}

int main() {
  int n; cin >> n;
  vector<int> x(n, -1);
  vector<vector<int>> cnt(n);
  FOR(i, 1, n) {
    x[i] = query(2, 0, i);
    cnt[x[i]].emplace_back(i);
  }
  vector<int> ans(n, -1);
  if (!cnt[0].empty()) {
    ans[0] = query(1, 0, cnt[0][0]);
  } else {
    bool fixed = false;
    FOR(i, 1, n) {
      if (cnt[i].size() >= 2) {
        ans[cnt[i][0]] = query(1, cnt[i][0], cnt[i][1]);
        ans[0] = ans[cnt[i][0]] ^ x[cnt[i][0]];
        fixed = true;
        break;
      }
    }
    if (!fixed) ans[0] = ((query(0, 0, cnt[1][0]) >> 1) << 1) | (query(0, 0, cnt[n - 2][0]) & 1);
  }
  FOR(i, 1, n) ans[i] = ans[0] ^ x[i];
  cout << "! ";
  REP(i, n) {
    cout << ans[i];
    if (i + 1 < n) {
      cout << endl;
    } else {
      cout << ' ';
    }
  }
  return 0;
}