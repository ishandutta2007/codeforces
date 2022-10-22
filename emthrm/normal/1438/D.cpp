#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int n; cin >> n;
  vector<ll> a(n); REP(i, n) cin >> a[i];
  if (n % 2 == 0) {
    REP(b, 29) {
      int cnt = 0;
      REP(i, n) cnt += a[i] >> b & 1;
      if (cnt & 1) {
        cout << "NO\n";
        return 0;
      }
    }
  }
  vector<int> ans_i, ans_j, ans_k;
  auto f = [&](int i, int j, int k) {
    ll x = a[i] ^ a[j] ^ a[k];
    a[i] = a[j] = a[k] = x;
    ans_i.emplace_back(i);
    ans_j.emplace_back(j);
    ans_k.emplace_back(k);
  };
  if (n & 1) {
    for (int i = 1; i < n; i += 2) f(0, i, i + 1);
    for (int i = 1; i < n; i += 2) f(0, i, i + 1);
  } else {
    for (int i = 1; i + 1 < n; i += 2) f(0, i, i + 1);
    assert(a[0] == a[n - 1]);
    for (int i = 1; i + 1 < n; i += 2) f(0, i, i + 1);
  }
  sort(ALL(a));
  assert(a.front() == a.back());
  int m = ans_i.size();
  assert(m <= n);
  cout << "YES\n" << m << '\n';
  REP(i, m) cout << ans_i[i] + 1 << ' ' << ans_j[i] + 1 << ' ' << ans_k[i] + 1 << '\n';
  return 0;
}