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

void solve() {
  int l1[2], l2[2];
  REP(i, 2) cin >> l1[i];
  REP(i, 2) cin >> l2[i];
  string s; cin >> s;
  REP(i, 2) {
    if (count(ALL(s), 'A' + i) != l1[i] + l2[0] + l2[1]) {
      cout << "NO\n";
      return;
    }
  }
  const int n = s.length();
  vector<int> odd, even[2]{};
  for (int i = 0; i < n;) {
    int j = i + 1;
    while (j < n && s[j - 1] != s[j]) ++j;
    if ((j - i) % 2 == 0) {
      even[s[i] - 'A'].emplace_back((j - i) / 2);
    } else {
      --l1[s[i] - 'A'];
      if (j - i >= 2) odd.emplace_back((j - i) / 2);
    }
    i = j;
  }
  REP(i, 2) {
    sort(ALL(even[i]));
    for (int l : even[i]) {
      if (l2[i] >= l) {
        l2[i] -= l;
      } else {
        l -= l2[i];
        l2[i] = 0;
        REP(j, 2) --l1[j];
        const int u = min(l - 1, l2[i ^ 1]);
        l2[i ^ 1] -= u;
        REP(j, 2) l1[j] -= l - 1 - u;
      }
    }
  }
  for (int l : odd) {
    REP(i, 2) {
      const int u = min(l, l2[i]);
      l2[i] -= u;
      l -= u;
    }
    REP(i, 2) l1[i] -= l;
  }
  REP(i, 2) {
    if (l1[i] != 0 || l2[i] != 0) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}