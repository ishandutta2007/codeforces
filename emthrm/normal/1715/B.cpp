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
  int n, k, b; ll s; cin >> n >> k >> b >> s;
  if (s / k < b) {
    cout << "-1\n";
    return;
  }
  if (k == 1) {
    if (s == b) {
      cout << s;
      FOR(i, 1, n) cout << ' ' << 0;
      cout << '\n';
    } else {
      cout << "-1\n";
    }
    return;
  }
  vector<ll> a(n, 0);
  REP(i, n) {
    a[i] = min(k - 1LL, s);
    s -= a[i];
  }
  while (!a.empty() && a.back() == 0) a.pop_back();
  a.back() += s;
  ll cur_b = 0;
  for (const ll a_i : a) cur_b += a_i / k;
  if (cur_b > b) {
    cout << "-1\n";
    return;
  }
  cur_b -= a.back() / k;
  for (int i = static_cast<int>(a.size()) - 2; i >= 0 && cur_b + a.back() / k < b; --i) {
    a.back() += a[i];
    a[i] = 0;
  }
  a.resize(n, 0);
  REP(i, n) cout << a[i] << " \n"[i + 1 == n];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}