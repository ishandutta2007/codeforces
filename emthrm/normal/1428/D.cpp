#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<int> tar(n, -1);
  queue<int> two;
  REP(i, n) {
    if (a[i] == 2) {
      two.emplace(i);
      tar[i] = i;
    } else if (a[i] == 1 && !two.empty()) {
      tar[i] = two.front();
      two.pop();
    }
  }
  if (!two.empty()) {
    cout << "-1\n";
    return 0;
  }
  vector<pair<int, int>> ans;
  vector<int> can;
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] == 1) {
      if (tar[i] == -1) {
        tar[i] = i;
        can.emplace_back(i);
      }
    } else if (a[i] == 2) {
      can.emplace_back(i);
    } else if (a[i] == 3) {
      if (can.empty()) {
        cout << "-1\n";
        return 0;
      }
      tar[i] = i;
      ans.emplace_back(i, can.back());
      can.pop_back();
      can.emplace_back(i);
    }
  }
  REP(j, n) {
    if (tar[j] != -1) ans.emplace_back(tar[j], j);
  }
  cout << ans.size() << '\n';
  for (auto [r, c] : ans) cout << r + 1 << ' ' << c + 1 << '\n';
  return 0;
}