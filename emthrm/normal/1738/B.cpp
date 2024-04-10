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
constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};
constexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n, k; cin >> n >> k;
  vector<ll> s(k); REP(i, k) cin >> s[i];
  if (k == 1) {
    // if (s.back() < 0) {
    //   cout << s.back();
    //   FOR(i, 1, n) cout << ' ' << 0;
    //   cout << '\n';
    // } else {
    //   REP(i, n - 1) cout << 0 << ' ';
    //   cout << s.back() << '\n';
    // }
    cout << "Yes\n";
    return;
  }
  vector<ll> a(n, 0);
  for (int i = n - 1; i > n - k; --i) {
    a[i] = s[i - (n - k)] - s[i - 1 - (n - k)];
  }
  if (s.front() >= 0) {
    if (a[n - k + 1] < 0) {
      cout << "No\n";
      return;
    }
    for (int i = n - k; i >= 0; --i) {
      a[i] = min(a[i + 1], s.front());
      s.front() -= a[i];
    }
    if (s.front() > 0) {
      cout << "No\n";
      return;
    }
  } else {
    for (int i = n - k; i > 0; --i) {
      a[i] = a[n - k + 1];
      s.front() -= a[i];
    }
    a.front() = s.front();
  }
  // REP(i, n) cout << a[i] << " \n"[i + 1 == n];
  cout << (is_sorted(ALL(a)) ? "Yes\n" : "No\n");
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}