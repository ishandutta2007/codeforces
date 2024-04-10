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

vector<int> fib{1, 1};
vector<ll> sum{1, 2};

void solve() {
  int k; cin >> k;
  priority_queue<int> c;
  ll sum_c = 0;
  while (k--) {
    int c_i; cin >> c_i;
    c.emplace(c_i);
    sum_c += c_i;
  }
  const auto it = lower_bound(ALL(sum), sum_c);
  if (it == sum.end() || *it != sum_c) {
    cout << "NO\n";
    return;
  }
  int nxt = 0;
  for (int i = it - sum.begin(); i >= 0; --i) {
    if (c.empty()) {
      cout << "NO\n";
      return;
    }
    int x = c.top(); c.pop();
    if (x < fib[i]) {
      cout << "NO\n";
      return;
    }
    x -= fib[i];
    if (nxt > 0) c.emplace(nxt);
    nxt = x;
  }
  cout << "YES\n";
}

int main() {
  constexpr int C = 1000000000;
  for (int i = 2; ; ++i) {
    const int nxt = fib[i - 2] + fib[i - 1];
    if (nxt > C) break;
    fib.emplace_back(nxt);
    sum.emplace_back(sum[i - 1] + nxt);
  }

  int t; cin >> t;
  while (t--) solve();
  return 0;
}