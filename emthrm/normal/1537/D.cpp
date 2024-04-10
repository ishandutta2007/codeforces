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

bool is_prime(long long n) {
  if (n <= 1) return false;
  for (long long i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

template <typename T>
std::vector<T> divisor(T n) {
  std::vector<T> res;
  for (T i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      res.emplace_back(i);
      if (i * i != n) res.emplace_back(n / i);
    }
  }
  std::sort(res.begin(), res.end());
  return res;
}

void solve() {
}

int main() {
  // constexpr int N = 1000;
  // vector<int> win(N, 0);
  // FOR(i, 2, N) {
  //   for (int d : divisor(i)) {
  //     if (d != 1 && d != i && win[i - d] == 0) {
  //       win[i] = 1;
  //       break;
  //     }
  //   }
  // }
  // FOR(i, 1, N) {
  //   if (i % 2 == 0) {
  //     if (win[i] == 0) cout << i << '\n';
  //   } else {
  //     assert(win[i] == 0);
  //   }
  // }

  constexpr int M = 1000000000;
  unordered_set<ll> bob;
  for (ll n = 2; n <= M; n *= 4) bob.emplace(n);

  int t; cin >> t;
  while (t--) {
    int n ; cin >> n;
    cout << (n % 2 == 1 || bob.count(n) == 1 ? "Bob\n" : "Alice\n");
  }
  return 0;
}