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

void solve() {
  int n; cin >> n;
  vector<ll> a(n); REP(i, n) cin >> a[i];
  ll m = 0;
  REP(i, n - 1) {
    if (a[i] >= 0 && a[i + 1] >= 0) chmax(m, abs(a[i + 1] - a[i]));
  }
  vector<ll> val;
  REP(i, n) {
    if (a[i] == -1) {
      if (i - 1 >= 0 && a[i - 1] >= 0) val.emplace_back(a[i - 1]);
      if (i + 1 < n && a[i + 1] >= 0) val.emplace_back(a[i + 1]);
    }
  }
  sort(ALL(val));
  if (val.size() >= 2) {
    chmax(m, (val.back() - val.front() + 1) / 2);
    cout << m << ' ' << (val.front() + val.back() + 1) / 2 << '\n';
  } else {
    cout << m << ' ' << (val.empty() ? 0 : val[0]) << '\n';
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}