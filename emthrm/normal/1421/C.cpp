#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

struct Manacher {
  template <typename T>
  Manacher(const T &s) {
    T str;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      str.push_back(s[i]);
      if (i + 1 < n) str.push_back('$');
    }
    n = str.size();
    radius.resize(n);
    int j = 1;
    for (int i = 0; i < n;) {
      while (i - j >= 0 && i + j < n && str[i - j] == str[i + j]) ++j;
      radius[i] = j;
      int k = 1;
      while (i - k >= 0 && i + k < n && k + radius[i - k] < j) {
        radius[i + k] = radius[i - k];
        ++k;
      }
      i += k;
      j -= k;
    }
  }

  int odd(int idx) const { return (radius[idx * 2] + 1) / 2; }

  int even(int idx) const { return radius[idx * 2 + 1] / 2; }

  bool is_palindrome(int left, int right) const {
    int mid = (left + right - 1) / 2;
    return (((right - left) & 1) ? odd(mid) * 2 - 1 : even(mid) * 2) >= right - left;
  }

private:
  std::vector<int> radius;
};

int main() {
  string s; cin >> s;
  int n = s.length();
  cout << 3 << '\n';
  cout << "L " << n - 1 << '\n';
  {
    string t = s.substr(1);
    t.pop_back();
    reverse(ALL(t));
    s = t + s;
  }
  cout << "R " << n - 1 << '\n';
  {
    string t = s.substr(n - 2);
    t.pop_back();
    reverse(ALL(t));
    s += t;
  }
  cout << "R " << 2 * n - 1 << '\n';
  {
    string t = s.substr(2 * n - 2);
    t.pop_back();
    reverse(ALL(t));
    s += t;
  }
  assert(Manacher(s).is_palindrome(0, s.length()) && s.length() <= 1000000);
  return 0;
}