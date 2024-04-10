#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
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
std::vector<T> divisor(T val) {
  std::vector<T> res;
  for (T i = 1; i * i <= val; ++i) {
    if (val % i == 0) {
      res.emplace_back(i);
      if (i * i != val) res.emplace_back(val / i);
    }
  }
  std::sort(res.begin(), res.end());
  return res;
}

template <typename T>
std::vector<std::pair<T, int>> prime_factorization(T val) {
  std::vector<std::pair<T, int>> res;
  for (T i = 2; i * i <= val; ++i) {
    if (val % i != 0) continue;
    int exponent = 0;
    while (val % i == 0) {
      ++exponent;
      val /= i;
    }
    res.emplace_back(i, exponent);
  }
  if (val != 1) res.emplace_back(val, 1);
  return res;
}

void solve() {
  int n; cin >> n;
  vector<int> d = divisor(n);
  d.erase(d.begin());
  vector<int> p;
  for (auto pr : prime_factorization(n)) p.emplace_back(pr.first);
  if (p.size() == 1) {
    REP(i, d.size()) cout << d[i] << " \n"[i + 1 == d.size()];
    cout << 0 << '\n';
    return;
  } else if (p.size() == 2) {
    if (p[0] * p[1] == n) {
      cout << p[0] << ' ' << n << ' ' << p[1] << '\n' << 1 << '\n';
    } else {
      vector<int> circle{p[0]};
      vector<int> p1;
      for (int e : d) {
        if (e % p[0] == 0) {
          if (e != p[0] && e != p[0] * p[1] && e != n) circle.emplace_back(e);
        } else if (e != p[1]) {
          p1.emplace_back(e);
        }
      }
      circle.emplace_back(p[0] * p[1]);
      copy(ALL(p1), back_inserter(circle));
      circle.emplace_back(p[1]);
      circle.emplace_back(n);
      int ans = 0;
      REP(i, circle.size()) ans += gcd(circle[i], circle[(i + 1) % circle.size()]) == 1;
      assert(ans == 0);
      REP(i, circle.size()) cout << circle[i] << " \n"[i + 1 == circle.size()];
      cout << ans << '\n';
    }
    return;
  }
  {
    set<int> spe(p.begin(), p.end());
    REP(i, p.size()) spe.emplace(p[i] * p[(i + 1) % p.size()]);
    vector<int> nx;
    for (int e : d) {
      if (spe.count(e) == 0) nx.emplace_back(e);
    }
    d.swap(nx);
  }
  vector<int> circle{p[0]};
  FOR(i, 1, p.size()) {
    vector<int> nx;
    for (int e : d) {
      if (e % p[i - 1] == 0) {
        circle.emplace_back(e);
      } else {
        nx.emplace_back(e);
      }
    }
    d.swap(nx);
    circle.emplace_back(p[i - 1] * p[i]);
    circle.emplace_back(p[i]);
  }
  circle.emplace_back(p.front() * p.back());
  int ans = 0;
  REP(i, circle.size()) ans += gcd(circle[i], circle[(i + 1) % circle.size()]) == 1;
  assert(ans == 0);
  REP(i, circle.size()) cout << circle[i] << " \n"[i + 1 == circle.size()];
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}