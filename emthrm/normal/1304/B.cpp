#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
template <typename T> using posteriority_queue = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
template <typename T> void unique(vector<T> &a) { a.erase(unique(ALL(a)), a.end()); }
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

int main() {
  int n, m; cin >> n >> m;
  vector<string> s(n); REP(i, n) cin >> s[i];
  int ans = 0;
  string t = "", u = "";
  vector<bool> used(n, false), cen(n, false);
  REP(i, n) {
    cen[i] = Manacher(s[i]).is_palindrome(0, m);
    if (used[i]) continue;
    FOR(j, i + 1, n) {
      if (used[j]) continue;
      bool same = true;
      REP(k, m) same &= s[i][k] == s[j][m - 1 - k];
      if (same) {
        used[i] = used[j] = true;
        t += s[i];
        reverse(ALL(s[j]));
        u += s[j];
        ans += m * 2;
        break;
      }
    }
  }
  REP(i, n) {
    if (!used[i] && cen[i]) {
      ans += m;
      t += s[i];
      break;
    }
  }
  reverse(ALL(u));
  cout << ans << '\n' << t + u << '\n';;
  return 0;
}