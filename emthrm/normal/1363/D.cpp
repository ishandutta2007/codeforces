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

int query(const vector<int> &v) {
  int c = v.size();
  cout << "? " << c << ' ';
  REP(i, c) {
    cout << v[i] + 1;
    if (i + 1 < c) cout << ' ';
  }
  cout << endl;
  int x; cin >> x;
  assert(x != -1);
  return x;
}

void solve() {
  int n, k; cin >> n >> k;
  vector<vector<int>> s(k);
  REP(i, k) {
    int c; cin >> c;
    s[i].resize(c);
    REP(j, c) cin >> s[i][j], --s[i][j];
  }
  int mx = [&]() {
    vector<int> v(n);
    iota(ALL(v), 0);
    return query(v);
  }();
  int lb = -1, ub = k - 1;
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    vector<int> v;
    REP(i, mid + 1) for (int e : s[i]) v.emplace_back(e);
    (query(v) == mx ? ub : lb) = mid;
  }
  vector<int> ans(k, mx);
  ans[ub] = [&]() {
    vector<bool> v(n, true);
    for (int e : s[ub]) v[e] = false;
    vector<int> u;
    REP(i, n) {
      if (v[i]) u.emplace_back(i);
    }
    return query(u);
  }();
  cout << "! ";
  REP(i, k) {
    cout << ans[i];
    if (i + 1 < k) cout << ' ';
  }
  cout << endl;
  string t; cin >> t;
  assert(t == "Correct");
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}