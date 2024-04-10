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

// https://xuzijian629.hatenablog.com/entry/2018/12/01/000010
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

int main() {
  int n; cin >> n;
  tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> s;
  const auto temp = [&](int day, int p) -> int {
    return p + day - s.order_of_key(p);
  };
  int lastans = 0;
  REP(day, n) {
    int t, k; cin >> t >> k;
    const auto f = [&](int t) -> int {
      int lb = t - day * 2 - 1, ub = t + day * 2 + 1;
      while (ub - lb > 1) {
        const int mid = (lb + ub) / 2;
        (temp(day, mid) <= t ? lb : ub) = mid;
      }
      return lb;
    };
    for (int e : vector<int>{f(t - 1), f(t)}) s.insert(e);
    while (k--) {
      int x; cin >> x;
      x = (x + lastans) % 1000000001;
      lastans = temp(day + 1, x);
      cout << lastans << '\n';
    }
  }
  return 0;
}