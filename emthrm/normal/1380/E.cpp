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
  int n, m; cin >> n >> m;
  vector<set<int>> tower(m);
  REP(i, n) {
    int t; cin >> t; --t;
    tower[t].emplace(i);
  }
  int ans = m - 1;
  REP(i, m) {
    for (auto it = next(tower[i].begin()); it != tower[i].end(); ++it) {
      ans += *it - *prev(it) != 1;
    }
  }
  cout << ans << '\n';
  function<void(int, int)> unite = [&](int a, int b) {
    if (tower[a].size() < tower[b].size()) swap(a, b);
    vector<int> ins;
    for (int e : tower[b]) ins.emplace_back(e);
    int l = ins.size();
    for (int i = 0; i < l;) {
      int j = i + 1;
      while (j < l && ins[j] - ins[j - 1] == 1) ++j;
      ans -= tower[a].count(ins[i] - 1) == 1;
      ans -= tower[a].count(ins[j - 1] + 1) == 1;
      i = j;
    }
  };
  REP(_, m - 1) {
    int a, b; cin >> a >> b; --a; --b;
    unite(a, b);
    if (tower[a].size() < tower[b].size()) {
      for (int e : tower[a]) tower[b].emplace(e);
      tower[a].clear();
      swap(tower[a], tower[b]);
    } else {
      for (int e : tower[b]) tower[a].emplace(e);
    }
    cout << ans << '\n';
  }
  return 0;
}