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

struct Xor128 {
  int rand() {
    unsigned int t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
  }
  int rand(const int ub) {
    const int res = rand() % ub;
    return res < 0 ? res + ub : res;
  }
  int rand(const int lb, const int ub) { return lb + rand(ub - lb); }
  long long randll() {
    return (static_cast<unsigned long long>(rand()) << 32) | rand();
  }
  long long randll(const long long ub) {
    const long long res = randll() % ub;
    return res < 0 ? res + ub : res;
  }
  long long randll(const long long lb, const long long ub) {
    return lb + randll(ub - lb);
  }
 private:
  unsigned int x = 123456789, y = 362436069, z = 521288629;
  unsigned int w = std::time(nullptr);
} xor128;

int main() {
  int n, m; cin >> n >> m;
  vector a(n, vector(m, 0));
  vector<int> w(n);
  REP(i, n) {
    REP(j, m) cin >> a[i][j];
    cin >> w[i];
  }
  vector<int> b(n * m);
  REP(i, n) copy(ALL(a[i]), next(b.begin(), m * i));
  sort(ALL(b));
  b.erase(unique(ALL(b)), b.end());
  REP(i, n) REP(j, m) a[i][j] = lower_bound(ALL(b), a[i][j]) - b.begin();
  {
    vector<int> ord(n);
    iota(ALL(ord), 0);
    sort(ALL(ord), [&](int x, int y) -> bool { return w[x] < w[y]; });
    vector<int> nxt_w(n);
    REP(i, n) nxt_w[i] = w[ord[i]];
    w.swap(nxt_w);
    vector<vector<int>> nxt_a(n);
    REP(i, n) nxt_a[i] = a[ord[i]];
    a.swap(nxt_a);
  }
  const int x = b.size();
  vector<ll> hash(x);
  REP(i, x) hash[i] = xor128.randll();
  vector c(n, vector(1 << m, 0LL));
  REP(i, n) FOR(j, 1, 1 << m) {
    REP(k, m) {
      if (j >> k & 1) c[i][j] ^= hash[a[i][k]];
    }
  }
  vector<ll> subsets(n * (1 << m));
  REP(i, n) copy(ALL(c[i]), subsets.begin() + (i * (1 << m)));
  sort(ALL(subsets));
  subsets.erase(unique(ALL(subsets)), subsets.end());
  const int y = subsets.size();
  REP(i, n) REP(j, 1 << m) c[i][j] = lower_bound(ALL(subsets), c[i][j]) - subsets.begin();
  vector<int> lb(n, -1), ub(n, n);
  while (true) {
    bool is_finished = true;
    vector<vector<int>> mids(n);
    REP(i, n) {
      if (ub[i] - lb[i] > 1) {
        mids[(lb[i] + ub[i]) / 2].emplace_back(i);
        is_finished = false;
      }
    }
    if (is_finished) break;
    vector<int> nums(y, 0);
    REP(i, n) {
      for (int j : c[i]) ++nums[j];
      for (int id : mids[i]) {
        int ways = 0;
        REP(j, 1 << m) {
          if (__builtin_popcount(j) & 1) {
            ways -= nums[c[id][j]];
          } else {
            ways += nums[c[id][j]];
          }
        }
        (ways > 0 ? ub : lb)[id] = i;
      }
    }
  }
  int ans = numeric_limits<int>::max();
  REP(i, n) {
    if (ub[i] != n) chmin(ans, w[i] + w[ub[i]]);
  }
  cout << (ans == numeric_limits<int>::max() ? -1 : ans) << '\n';
  return 0;
}