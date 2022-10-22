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
  ll n; int m; cin >> n >> m;
  vector<ll> cnt(61, 0);
  while (m--) {
    int a; cin >> a;
    REP(j, 31) if (a >> j & 1) ++cnt[j];
  }
  int ans = 0;
  REP(i, 61) {
    if (i > 0) cnt[i] += cnt[i - 1] / 2;
    if (!(n >> i & 1)) continue;
    if (cnt[i] > 0) {
      --cnt[i];
      continue;
    }
    FOR(j, i + 1, 62) {
      if (j == 61) {
        cout << "-1\n";
        return;
      }
      if (cnt[j] > 0) {
        for (int k = j; k > i; --k) {
          --cnt[k];
          ++ans;
          cnt[k - 1] += 2;
        }
        --cnt[i];
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