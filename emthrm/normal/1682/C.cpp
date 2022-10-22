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

template <typename T>
std::vector<T> longest_increasing_subsequence(
    const std::vector<T>& a, const bool is_strict = true) {
  const T inf = std::numeric_limits<T>::max();
  const int n = a.size();
  std::vector<int> idx(n);
  std::vector<T> tmp(n, inf);
  for (int i = 0; i < n; ++i) {
    if (is_strict) {
      idx[i] = std::distance(tmp.begin(),
                             std::lower_bound(tmp.begin(), tmp.end(), a[i]));
    } else {
      idx[i] = std::distance(tmp.begin(),
                             std::upper_bound(tmp.begin(), tmp.end(), a[i]));
    }
    tmp[idx[i]] = a[i];
  }
  int res_size =
      std::distance(tmp.begin(), std::lower_bound(tmp.begin(), tmp.end(), inf));
  std::vector<T> res(res_size--);
  for (int i = n - 1; res_size >= 0 && i >= 0; --i) {
    if (idx[i] == res_size) res[res_size--] = a[i];
  }
  return res;
}

void solve() {
  int n; cin >> n;
  map<int, int> a;
  while (n--) {
    int a_i; cin >> a_i;
    ++a[a_i];
  }
  n = 0;
  for (const auto [_, num] : a) n += min(num, 2);
  cout << (n + 1) / 2 << '\n';
  // {
  //   vector<int> b;
  //   for (const auto [a_i, num] : a) {
  //     REP(_, num) b.emplace_back(a_i);
  //   }
  //   int ans = 0;
  //   do {
  //     vector<int> c = b;
  //     reverse(ALL(c));
  //     chmax(ans, min(longest_increasing_subsequence(b).size(), longest_increasing_subsequence(c).size()));
  //   } while (next_permutation(ALL(b)));
  //   assert(ans == (n + 1) / 2);
  // }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}