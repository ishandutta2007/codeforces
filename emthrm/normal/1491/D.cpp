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

struct Xor128 {
  int rand() {
    unsigned int t = x ^ (x << 11);
    x = y; y = z; z = w; w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    return static_cast<int>(w);
  }
  int rand(int ub) {
    int res = rand() % ub;
    return res < 0 ? res + ub : res;
  }
  int rand(int lb, int ub) { return lb + rand(ub - lb); }
  long long randll() {
    unsigned long long res = static_cast<unsigned long long>(rand()) << 32;
    return static_cast<long long>(res | rand());
  }
  long long randll(long long ub) {
    long long res = randll() % ub;
    return res < 0 ? res + ub : res;
  }
  long long randll(long long lb, long long ub) { return lb + randll(ub - lb); }
private:
  unsigned int x = 123456789, y = 362436069, z = 521288629, w = static_cast<unsigned int>(std::time(nullptr));
} xor128;

void solve() {
  int u, v; cin >> u >> v;
  if (u > v) {
    cout << "NO\n";
    return;
  }
  // int u = xor128.rand(1, 100), v = xor128.rand(u + 1, 200);
  // cout << u << ' ' << v << " : ";
  // vector<bool> reach(v + 1, false);
  // reach[u] = true;
  // queue<int> que({u});
  // while (!que.empty()) {
  //   int cur = que.front(); que.pop();
  //   FOR(i, 1, cur + 1) {
  //     if ((cur & i) == i && cur + i <= v && !reach[cur + i]) {
  //       reach[cur + i] = true;
  //       que.emplace(cur + i);
  //     }
  //   }
  // }
  // cout << (reach[v] ? "YES " : "NO ");
  for (int b = 29; b >= 0; --b) {
    if (v >> b & 1) {
      bool ok = false;
      for (int i = b; i >= 0; --i) {
        if (u >> i & 1) {
          ok = true;
          u ^= 1 << i;
          break;
        }
      }
      if (!ok) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
}

int main() {
  int q; cin >> q;
  while (q--) solve();
  return 0;
}