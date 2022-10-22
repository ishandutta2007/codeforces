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

constexpr int C = 26;

void solve() {
  string t; cin >> t;
  const int n = t.length();
  int cnt[C]{};
  string sec = "";
  for (int i = n - 1; i >= 0; --i) {
    if (cnt[t[i] - 'a']++ == 0) sec += t[i];
  }
  reverse(ALL(sec));
  int contain[C]{};
  REP(i, sec.length()) {
    const int idx = sec[i] - 'a';
    if (cnt[idx] % (i + 1) > 0) {
      cout << "-1\n";
      return;
    }
    contain[idx] = cnt[idx] / (i + 1);
  }
  int rem = 0;
  REP(c, C) {
    if (contain[c] > 0) ++rem;
  }
  string fir = "";
  int i = 0;
  for (; i < n && rem > 0; ++i) {
    const int idx = t[i] - 'a';
    if (contain[idx] == 0) {
      cout << "-1\n";
      return;
    }
    if (--contain[idx] == 0) --rem;
    fir += t[i];
  }
  string cur = fir;
  for (char c : sec) {
    string nx = "";
    for (char c2 : cur) {
      if (c2 != c) nx += c2;
    }
    cur = nx;
    if (i + cur.length() > n || t.substr(i, cur.length()) != cur) {
      cout << "-1\n";
      return;
    }
    i += cur.length();
  }
  if (i < n) {
    cout << "-1\n";
  } else {
    cout << fir << ' ' << sec << '\n';
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}