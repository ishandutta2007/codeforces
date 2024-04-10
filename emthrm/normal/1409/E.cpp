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

template <typename T>
vector<T> divisor(T val) {
  vector<T> res;
  for (T i = 1; i * i <= val; ++i) {
    if (val % i == 0) {
      res.emplace_back(i);
      if (i * i != val) res.emplace_back(val / i);
    }
  }
  sort(ALL(res));
  return res;
}

void solve() {
  int n, k; cin >> n >> k;
  vector<int> x(n); REP(i, n) cin >> x[i];
  vector<int> xs = x;
  sort(ALL(xs));
  xs.erase(unique(ALL(xs)), xs.end());
  int m = xs.size();
  REP(i, n) x[i] = lower_bound(ALL(xs), x[i]) - xs.begin();
  REP(_, n) {
    int y; cin >> y;
  }
  if (m <= 2) {
    cout << n << '\n';
    return;
  }
  vector<int> cnt(m, 0), l(m, 0), r(m, 0);
  REP(i, n) ++cnt[x[i]];
  int cur = 0, pos = 0;
  REP(i, m) {
    cur += cnt[i];
    while (pos < i && xs[i] - xs[pos] > k) cur -= cnt[pos++];
    l[i] = cur;
  }
  cur = 0;
  pos = m - 1;
  for (int i = m - 1; i >= 0; --i) {
    cur += cnt[i];
    while (pos > i && xs[pos] - xs[i] > k) cur -= cnt[pos--];
    r[i] = cur;
  }
  // REP(i, m) cout << l[i] << " \n"[i + 1 == m];
  // REP(i, m) cout << r[i] << " \n"[i + 1 == m];
  int ans = 0;
  for (int i = m - 2; i >= 0; --i) {
    chmax(ans, l[i] + r[i + 1]);
    chmax(r[i], r[i + 1]);
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}