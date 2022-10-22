#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
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
  int n, k; string s; cin >> n >> k >> s;
  vector<vector<int>> ans(k + 1);
  vector<int> turn;
  REP(i, n - 1) {
    if (s[i] == 'R' && s[i + 1] == 'L') turn.emplace_back(i);
  }
  REP(second, k + 1) {
    vector<int> nx;
    for (int e : turn) {
      if (s[e] == 'R' && s[e + 1] == 'L') nx.emplace_back(e);
    }
    turn.swap(nx);
    nx.clear();
    sort(ALL(turn));
    turn.erase(unique(ALL(turn)), turn.end());
    for (int e : turn) {
      ans[second].emplace_back(e);
      s[e] = 'L';
      s[e + 1] = 'R';
      if (e > 0) nx.emplace_back(e - 1);
      if (e + 2 < n) nx.emplace_back(e + 1);
    }
    if (ans[second].empty()) break;
    turn.swap(nx);
  }
  if (!ans[k].empty()) {
    cout << "-1\n";
    return 0;
  }
  vector<vector<int>> mov(k);
  while (!ans.empty() && ans.back().empty()) ans.pop_back();
  int idx = int(ans.size()) - 1;
  for (int i = k - 1; i >= 0; --i) {
    if (idx < 0) {
      cout << "-1\n";
      return 0;
    }
    if (i == idx) break;
    mov[i].emplace_back(ans[idx].back());
    ans[idx].pop_back();
    if (ans[idx].empty()) --idx;
  }
  for (; idx >= 0; --idx) mov[idx] = ans[idx];
  REP(second, k) {
    int m = mov[second].size();
    cout << m << ' ';
    REP(i, m) cout << mov[second][i] + 1 << " \n"[i + 1 == m];
  }
  return 0;
}