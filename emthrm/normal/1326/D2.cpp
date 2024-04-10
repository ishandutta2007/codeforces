#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
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
    REP(i, n) {
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

  int odd(int idx) { return (radius[idx * 2] + 1) / 2; }

  int even(int idx) { return radius[idx * 2 + 1] / 2; }

  bool is_palindrome(int left, int right) {
    int mid = (left + right - 1) / 2;
    return (((right - left) & 1) ? odd(mid) * 2 - 1 : even(mid) * 2) >= right - left;
  }

private:
  vector<int> radius;
};

void solve() {
  string s; cin >> s;
  int n = s.length();
  function<int(int, int)> len = [&](int a, int b) { return a + 1 + n - b; };
  int idx = 0;
  for (; idx < n - 1 - idx; ++idx) {
    if (s[idx] != s[n - 1 - idx]) break;
  }
  if (n - 1 - idx < idx) {
    cout << s << '\n';
    return;
  }
  int a = -1, b = n;
  Manacher man(s);
  REP(i, n) {
    if (i <= n - 1 - i) {
      if (i - man.odd(i) < idx) {
        int p = i + man.odd(i) - 1, q = n - 1 - (i - man.odd(i));
        if (len(p, q) > len(a, b)) a = p, b = q;
      }
    } else {
      if (i + man.odd(i) > n - idx - 1) {
        int p = n - 1 - (i + man.odd(i)), q = i - man.odd(i) + 1;
        if (len(p, q) > len(a, b)) a = p, b = q;
      }
    }
  }
  REP(i, n - 1) {
    if (i < n - 1 - i) {
      if (i - man.even(i) < idx) {
        int p = i + man.even(i), q = n - 1 - (i - man.even(i));
        if (len(p, q) > len(a, b)) a = p, b = q;
      }
    } else {
      if (i + man.even(i) >= n - idx - 1) {
        int p = n - 1 - (i + man.even(i) + 1), q = i - man.even(i) + 1;
        if (len(p, q) > len(a, b)) a = p, b = q;
      }
    }
  }
  string ans = "";
  REP(i, a + 1) ans += s[i];
  FOR(i, b, n) ans += s[i];
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}