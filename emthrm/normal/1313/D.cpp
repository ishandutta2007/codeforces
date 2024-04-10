#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
template <typename T> using posteriority_queue = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
template <typename T> void unique(vector<T> &a) { a.erase(unique(ALL(a)), a.end()); }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int n, m, k; cin >> n >> m >> k;
  vector<int> l(n), r(n), x;
  REP(i, n) {
    cin >> l[i] >> r[i]; ++r[i];
    x.emplace_back(l[i]);
    x.emplace_back(r[i]);
  }
  sort(ALL(x));
  unique(x);
  map<pair<int, int>, int> lr;
  REP(i, n) {
    l[i] = lower_bound(ALL(x), l[i]) - x.begin();
    r[i] = lower_bound(ALL(x), r[i]) - x.begin();
    lr[{l[i], r[i]}] = i;
  }
  int a = x.size();
  vector<vector<int> > ins(a), era(a);
  for (auto it = lr.begin(); it != lr.end(); ++it) {
    int i, e; tie(i, e) = it->first;
    ins[i].emplace_back(it->second);
    era[e].emplace_back(it->second);
  }
  vector<vector<int> > dp(a, vector<int>(1 << k, -INF));
  dp[0][0] = 0;
  map<int, int> mp;
  vector<bool> use(k, false);
  REP(i, a - 1) {
    int sub = (1 << k) - 1;
    for (int e : era[i]) {
      use[mp[e]] = false;
      sub ^= 1 << mp[e];
    }
    int add = 0, idx = 0;
    for (int e : ins[i]) {
      while (use[idx]) ++idx;
      mp[e] = idx;
      use[idx] = true;
      add |= 1 << idx;
    }
    REP(j, 1 << k) {
      if (dp[i][j] < 0) continue;
      int nx = j & sub, subset = add;
      do {
        int cnt = __builtin_popcount(nx | subset);
        chmax(dp[i + 1][nx | subset], dp[i][j] + (cnt & 1 ? x[i + 1] - x[i] : 0));
      } while ((subset = (subset - 1) & add) != add);
    }
  }
  cout << *max_element(ALL(dp[a - 1])) << '\n';
  return 0;
}