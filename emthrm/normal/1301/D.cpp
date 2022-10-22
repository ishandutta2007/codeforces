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
  if (4 * n * m - 2 * n - 2 * m < k) {
    cout << "NO\n";
    return 0;
  }
  vector<int> f;
  vector<string> s;
  function<void()> ans = [&]() {
    cout << "YES\n";
    int a = f.size();
    cout << a << '\n';
    REP(i, a) cout << f[i] << ' ' << s[i] << '\n';
    exit(0);
  };
  for (int y = 1; y < n; ++y) {
    if (m > 1) {
      s.emplace_back("R");
      if (m - 1 >= k) {
        f.emplace_back(k);
        ans();
      }
      f.emplace_back(m - 1);
      k -= m - 1;
      s.emplace_back("L");
      if (m - 1 >= k) {
        f.emplace_back(k);
        ans();
      }
      f.emplace_back(m - 1);
      k -= m - 1;
    }
    s.emplace_back("D");
    f.emplace_back(1);
    --k;
    if (k == 0) ans();
  }
  if (m > 1) {
    s.emplace_back("R");
    if (m - 1 >= k) {
      f.emplace_back(k);
      ans();
    }
    f.emplace_back(m - 1);
    k -= m - 1;
  }
  for (int x = m; x > 1; --x) {
    if (n > 1) {
      s.emplace_back("U");
      if (n - 1 >= k) {
        f.emplace_back(k);
        ans();
      }
      f.emplace_back(n - 1);
      k -= n - 1;
      s.emplace_back("D");
      if (n - 1 >= k) {
        f.emplace_back(k);
        ans();
      }
      f.emplace_back(n - 1);
      k -= n - 1;
    }
    s.emplace_back("L");
    f.emplace_back(1);
    --k;
    if (k == 0) ans();
  }
  if (n > 1) {
    s.emplace_back("U");
    if (n - 1 >= k) {
      f.emplace_back(k);
      ans();
    }
    f.emplace_back(n - 1);
    k -= n - 1;
  }
  assert(false);
}