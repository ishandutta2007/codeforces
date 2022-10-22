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
  Manacher man(s);
  int a = 0, b = 0;
  FOR(i, 1, n + 1) {
    if (man.is_palindrome(0, i)) b = i;
  }
  for (int i = n - 1; i >= 0; --i) {
    if (man.is_palindrome(i, n) && n - i > b - a) {
      a = i;
      b = n;
    }
  }
  int a2 = -1, b2 = n;
  // vector<vector<int> > ins_odd(n), ins_even(n);
  // map<int, int> odd, even;
  // REP(i, (n + 1) / 2) ins_odd[max(i - man.odd(i), 0)].emplace_back(i);
  // REP(i, (n + 1) / 2) ins_even[max(i - man.even(i), 0)].emplace_back(i);
  for (int i = 0; i < n - 1 - i; ++i) {
    if (s[i] != s[n - 1 - i]) break;
    if (i + 1 + i + 1 > a2 + 1 + n - b2) a2 = i, b2 = n - 1 - i;
    FOR(j, i + 1, n - 1 - i) {
      if (man.is_palindrome(i + 1, j + 1)) {
        if (j + 1 + i + 1 > a2 + 1 + n - b2) a2 = j, b2 = n - 1 - i;
      }
    }
    for (int j = n - 1 - i - 1; j > i; --j) {
      if (man.is_palindrome(j, n - 1 - i)) {
        if (i + 1 + n - j > a2 + 1 + n - b2) a2 = i, b2 = j;
      }
    }
    // for (int e : ins_odd[i]) ++odd[e];
    // for (int e : ins_even[i]) ++even[e];
    // if (odd.count(i) == 1) odd.erase(i);
    // if (even.count(i) == 1) even.erase(i);
    // if (!odd.empty()) {
    //   int idx = odd.rbegin()->first;
    //   int a2a2 = min(i + (idx - i - 1) * 2 + 1, n - 1 - i - 1);
    //   if (a2a2 + 1 + i + 1 > a2 + 1 + n - b2) a2 = a2a2, b2 = n - 1 - i;
    // }
    // if (!even.empty()) {
    //   int idx = even.rbegin()->first;
    //   int a2a2 = min(i + (idx - i) * 2, n - 1 - i - 1);
    //   if (a2a2 + 1 + i + 1 > a2 + 1 + n - b2) a2 = a2a2, b2 = n - 1 - i;
    // }
  }
  // cout << s << ' ' << a2 << ' ' << b2 << endl;
  // reverse(ALL(s));
  // int a3 = -1, b3 = n;
  // {
  //   Manacher man_rev(s);
  //   vector<vector<int> > ins_odd(n), ins_even(n);
  //   map<int, int> odd, even;
  //   REP(i, (n + 1) / 2) ins_odd[max(i - man_rev.odd(i), 0)].emplace_back(i);
  //   REP(i, (n + 1) / 2) ins_even[max(i - man_rev.even(i), 0)].emplace_back(i);
  //   for (int i = 0; i < n - 1 - i; ++i) {
  //     if (s[i] != s[n - 1 - i]) break;
  //     if (i + 1 + i + 1 > a3 + 1 + n - b3) a3 = i, b3 = n - 1 - i;
  //     for (int e : ins_odd[i]) ++odd[e];
  //     for (int e : ins_even[i]) ++even[e];
  //     if (odd.count(i) == 1) odd.erase(i);
  //     if (even.count(i) == 1) even.erase(i);
  //     if (!odd.empty()) {
  //       int idx = odd.rbegin()->first;
  //       int a3a3 = min(i + (idx - i - 1) * 2 + 1, n - 1 - i - 1);
  //       if (a3a3 + 1 + i + 1 > a3 + 1 + n - b3) a3 = a3a3, b3 = n - 1 - i;
  //     }
  //     if (!even.empty()) {
  //       int idx = even.rbegin()->first;
  //       int a3a3 = min(i + (idx - i) * 2, n - 1 - i - 1);
  //       if (a3a3 + 1 + i + 1 > a3 + 1 + n - b3) a3 = a3a3, b3 = n - 1 - i;
  //     }
  //   }
  // }
  // reverse(ALL(s));
  // a3 = n - 1 - a3; b3 = n - 1 - b3;
  // swap(a3, b3);
  // // cout << s << ' ' << a3 << ' ' << b3 << endl;
  // if (a3 + 1 + n - b3 > a2 + 1 + n - b2) {
  //   a2 = a3;
  //   b2 = b3;
  // }
  // cout << a2 << ' ' << b2 << endl;
  if (b - a >= a2 + 1 + n - b2) {
    cout << s.substr(a, b - a) << '\n';
  } else {
    string ans = "";
    REP(i, a2 + 1) ans += s[i];
    FOR(i, b2, n) ans += s[i];
    cout << ans << '\n';
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}