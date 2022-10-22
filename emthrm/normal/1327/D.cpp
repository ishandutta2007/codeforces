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
  int n; cin >> n;
  vector<int> p(n), c(n);
  REP(i, n) cin >> p[i], --p[i];
  REP(i, n) {
    int ci; cin >> ci; --ci;
    c[p[i]] = ci;
  }
  vector<bool> visited(n, false);
  int ans = n;
  vector<int> ps(n), idx(n);
  REP(src, n) {
    if (visited[src]) continue;
    visited[src] = true;
    vector<int> pos{src};
    while (!visited[p[pos.back()]]) {
      pos.emplace_back(p[pos.back()]);
      visited[pos.back()] = true;
    }
    int m = pos.size();
    REP(i, m) idx[pos[i]] = i;
    for (int k : divisor(m)) {
      REP(i, m) ps[pos[i]] = pos[(i + k) % m];
      vector<bool> vis(m, false);
      bool ok = false;
      REP(i, m) {
        if (vis[i]) continue;
        vis[i] = true;
        int now = pos[i], color = c[ps[now]];
        ok = true;
        while (!vis[idx[ps[now]]]) {
          now = ps[now];
          vis[idx[now]] = true;
          ok &= color == c[ps[now]];
        }
        if (ok) break;
      }
      if (ok) {
        chmin(ans, k);
        break;
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}