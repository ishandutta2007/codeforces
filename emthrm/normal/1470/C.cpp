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
    unsigned t = x ^ (x << 11);
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
  unsigned x = 123456789, y = 362436069, z = 521288629, w = static_cast<unsigned>(std::time(nullptr));
} xor128;

int query(int q) {
  cout << "? " << q + 1 << endl;
  int k; cin >> k;
  return k;
}

int main() {
  int n, k; cin >> n >> k;
  int ub = -1;
  if (n <= 400) {
    REP(_, n) {
      int p = xor128.rand(0, n);
      if (query(p) > k) {
        ub = p;
        break;
      }
    }
    if (ub == -1) {
      REP(i, n) {
        if (query(i) > k) {
          ub = i;
          break;
        }
      }
    }
  } else {
    int x = static_cast<int>(floor(sqrt(n)));
    REP(_, x) {
      int p = xor128.rand(0, n);
      if (query(p) > k) {
        ub = p;
        break;
      }
    }
    for (int i = 0; ub == -1; i += x) {
      assert(i < n);
      if (query(i) > k) {
        ub = i;
        break;
      }
    }
  }
  int lb = ub - n / 2;
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    (query((mid + n) % n) > k ? ub : lb) = mid;
  }
  cout << "! " << (lb + n) % n + 1 << endl;
  return 0;

  // int p = 0, q = 10;
  // vector<int> a(n, k);
  // REP(_, q) {
  //   vector<int> b(n, 0);
  //   REP(i, n) {
  //     if (i == p) {
  //       b[(i + 1) % n] += a[i];
  //     } else {
  //       b[(i - 1 + n) % n] += a[i] / 2;
  //       b[(i + 1) % n] += (a[i] + 1) / 2;
  //     }
  //   }
  //   a.swap(b);
  //   REP(i, n) cout << a[i] << " \n"[i + 1 == n];
  // }
}