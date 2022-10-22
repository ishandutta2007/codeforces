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
template <typename T, typename U> inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n; cin >> n;
  vector<string> s(n); REP(i, n) cin >> s[i];
  REP(i, n) {
    if (equal(ALL(s[i]), s[i].rbegin())) {
      cout << "YES\n";
      return;
    }
  }
  set<string> st;
  REP(i, n) {
    if (s[i].length() == 2) {
      string rev = "";
      rev += s[i][1];
      rev += s[i][0];
      if (st.count(rev)) {
        cout << "YES\n";
        return;
      }
      st.emplace(s[i]);
    }
  }
  st.clear();
  REP(i, n) {
    if (s[i].length() == 3) {
      string rev = "";
      rev += s[i][2];
      rev += s[i][1];
      rev += s[i][0];
      if (st.count(rev)) {
        cout << "YES\n";
        return;
      }
      st.emplace(s[i]);
    }
  }
  st.clear();
  for (int i = n - 1; i >= 0; --i) {
    if (s[i].length() == 2) {
      if (st.count(s[i])) {
        cout << "YES\n";
        return;
      }
    } else {
      string rev = "";
      rev += s[i][2];
      rev += s[i][1];
      st.emplace(rev);
    }
  }
  st.clear();
  REP(i, n) {
    if (s[i].length() == 2) {
      if (st.count(s[i])) {
        cout << "YES\n";
        return;
      }
    } else {
      string rev = "";
      rev += s[i][1];
      rev += s[i][0];
      st.emplace(rev);
    }
  }
  cout << "NO\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}