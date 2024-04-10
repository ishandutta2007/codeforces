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

constexpr int B = 18;

valarray<int> to_k(int a, int k) {
  valarray<int> b(B);
  REP(i, B) {
    b[i] = a % k;
    a /= k;
  }
  return b;
}

int to10(const valarray<int> &a, int k) {
  int b = 0;
  for (int i = B - 1; i >= 0; --i) b = b * k + a[i];
  return b;
}

void normalize(valarray<int> &a, int k) {
  a %= k;
  REP(i, B) {
    if (a[i] < 0) a[i] += k;
  }
}

bool query(int y) {
  cout << y << endl;
  int r; cin >> r;
  assert(r != -1);
  return r == 1;
}

void solve() {
  int n, k; cin >> n >> k;
  valarray<int> x(B);
  REP(p, n) {
    valarray<int> q = x + to_k(p, k) * (p & 1 ? -1 : 1);
    normalize(q, k);
    if (query(to10(q, k))) return;
    x = q - x;
    normalize(x, k);
  }
  assert(false);
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}