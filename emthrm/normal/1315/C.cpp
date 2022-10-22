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

template <typename T = char, typename U = string>
vector<pair<T, int> > rle(const U &s) {
  int n = s.size();
  vector<pair<T, int> > res;
  T now = s[0];
  int cnt = 1;
  FOR(i, 1, n) {
    if (s[i] != now) {
      res.emplace_back(now, cnt);
      cnt = 0;
    }
    now = s[i];
    ++cnt;
  }
  res.emplace_back(now, cnt);
  return res;
}

void solve() {
  int n; cin >> n;
  set<int> rem;
  REP(i, n << 1) rem.emplace(i);
  vector<int> b(n);
  REP(i, n) {
    cin >> b[i]; --b[i];
    rem.erase(b[i]);
  }
  vector<int> a(n << 1);
  REP(i, n) {
    auto it = rem.upper_bound(b[i]);
    if (it == rem.end()) {
      cout << "-1\n";
      return;
    }
    a[i << 1] = b[i];
    a[(i << 1) + 1] = *it;
    rem.erase(it);
  }
  REP(i, n << 1) cout << a[i] + 1 << " \n"[i + 1 == (n << 1)];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}