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

vector<pair<int, ll>> canonical(const vector<int>& a, const int m) {
  vector<pair<int, ll>> b;
  for (int a_i : a) {
    ll d = 1;
    while (a_i % (d * m) == 0) d *= m;
    const int x = a_i / d;
    if (b.empty() || b.back().first != x) b.emplace_back(x, 0);
    b.back().second += d;
  }
  return b;
}

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n); REP(i, n) cin >> a[i];
  int k; cin >> k;
  vector<int> b(k); REP(i, k) cin >> b[i];
  cout << (canonical(a, m) == canonical(b, m) ? "Yes\n" : "No\n");
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}