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

struct Manacher {
  template <typename T>
  explicit Manacher(const T& s) {
    T str;
    int n = s.size();
    str.reserve(n * 2 + 1);
    for (int i = 0; i < n; ++i) {
      str.push_back(s[i]);
      str.push_back('$');
    }
    str.pop_back();
    n = str.size();
    radius.resize(n);
    for (int i = 0, j = 1; i < n;) {
      while (i - j >= 0 && i + j < n && str[i - j] == str[i + j]) ++j;
      radius[i] = j;
      int k = 1;
      for (; i - k >= 0 && i + k < n && k + radius[i - k] < j; ++k) {
        radius[i + k] = radius[i - k];
      }
      i += k;
      j -= k;
    }
  }

  int odd(const int idx) const { return (radius[idx * 2] + 1) / 2; }

  int even(const int idx) const { return radius[idx * 2 + 1] / 2; }

  bool is_palindrome(const int left, const int right) const {
    const int mid = (left + right - 1) / 2;
    return ((right - left) & 1 ? odd(mid) * 2 - 1 : even(mid) * 2)
           >= right - left;
  }

 private:
  std::vector<int> radius;
};

void solve() {
  int n; string s; cin >> n >> s;
  Manacher manacher(s);
  int c = 0, i = 0;
  while (i < n) {
    bool has_good_pre = false, is_reg = true;
    for (int j = i, dep = 0; j < n; ++j) {
      dep += (s[j] == '(' ? 1 : -1);
      is_reg &= dep >= 0;
      if ((is_reg && dep == 0) || (j > i && manacher.is_palindrome(i, j + 1))) {
        ++c;
        i = j + 1;
        has_good_pre = true;
        break;
      }
    }
    if (!has_good_pre) break;
  }
  cout << c << ' ' << n - i << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}