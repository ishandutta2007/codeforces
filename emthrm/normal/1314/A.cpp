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
  int n; cin >> n;
  map<int, vector<int> > mp;
  vector<int> a(n), t(n);
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> t[i];
  REP(i, n) mp[a[i]].emplace_back(t[i]);
  int prev = 0;
  ll ans = 0, sum = 0;
  priority_queue<int> que;
  for (auto &pr : mp) {
    vector<int> &ts = pr.second;
    if (!que.empty()) {
      int diff = pr.first - prev;
      // cout << sum << ' ' << diff << '\n';
      ans += sum * diff;
      while (!que.empty() && --diff > 0) {
        ans -= 1LL * que.top() * diff;
        sum -= que.top();
        que.pop();
      }
    }
    if (que.size() + ts.size() >= 2) {
      for (ll e : ts) {
        que.emplace(e);
        sum += e;
      }
      sum -= que.top();
      que.pop();
    }
    prev = pr.first;
  }
  while (!que.empty()) {
    ans += sum;
    sum -= que.top();
    que.pop();
  }
  cout << ans << '\n';
  return 0;
}