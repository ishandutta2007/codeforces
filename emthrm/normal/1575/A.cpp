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
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

template <typename T = std::string>
struct RollingHash {
  T str;

  RollingHash(const T &s, const int base = 10007, const int md = 1000000007) : str(s), base(base), md(md) {
    int n = str.size();
    hash_val.resize(n + 1);
    hash_val[0] = 0;
    power.resize(n + 1);
    power[0] = 1;
    for (int i = 0; i < n; ++i) {
      hash_val[i + 1] = (hash_val[i] * base % md + str[i]) % md;
      power[i + 1] = power[i] * base % md;
    }
  }

  long long get(int left, int right) const {
    long long res = hash_val[right] - hash_val[left] * power[right - left] % md;
    return res < 0 ? res + md : res;
  }

  void add(const T &t) {
    for (auto c : t) {
      hash_val.emplace_back((hash_val.back() * base % md + c) % md);
      power.emplace_back(power.back() * base % md);
    }
  }

  int lcp(int i, int j) const {
    int n = str.size(), lb = 0, ub = n + 1 - std::max(i, j);
    while (ub - lb > 1) {
      int mid = (lb + ub) >> 1;
      (get(i, i + mid) == get(j, j + mid) ? lb : ub) = mid;
    }
    return lb;
  }

  template <typename U>
  int lcp(const RollingHash<U> &t, int i, int j) const {
    int lb = 0, ub = std::min(static_cast<int>(str.size()) - i, static_cast<int>(t.str.size()) - j) + 1;
    while (ub - lb > 1) {
      int mid = (lb + ub) >> 1;
      (get(i, i + mid) == t.get(j, j + mid) ? lb : ub) = mid;
    }
    return lb;
  }

private:
  int base, md;
  std::vector<long long> hash_val, power;
};

int main() {
  int n, m; cin >> n >> m;
  vector<string> s(n); REP(i, n) cin >> s[i];
  vector<RollingHash<>> hash;
  REP(i, n) hash.emplace_back(s[i]);
  vector<int> ans(n);
  iota(ALL(ans), 0);
  sort(ALL(ans), [&](int i, int j) -> bool {
    int lb = 0, ub = m;
    while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      (hash[i].get(0, mid) == hash[j].get(0, mid) ? lb : ub) = mid;
    }
    if (lb % 2 == 0) {
      return s[i][lb] < s[j][lb];
    } else {
      return s[i][lb] > s[j][lb];
    }
  });
  REP(i, n) cout << ans[i] + 1 << " \n"[i + 1 == n];
  return 0;
}