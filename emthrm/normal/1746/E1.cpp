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
constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
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

bool query(const vector<int>& s) {
  const int n = s.size();
  cout << "? " << n;
  for (const int s_i : s) cout << ' ' << s_i;
  cout << endl;
#ifndef ONLINE_JUDGE
  return count(ALL(s), 1) > 0;
#else
  string yes_or_no; cin >> yes_or_no;
  return yes_or_no == "YES";
#endif
}

// [E1]
// https://twitter.com/maspy_stars/status/1581332067379343360
// [E2]
// https://twitter.com/heno_code/status/1581327942272983042
// https://twitter.com/maspy_stars/status/1581329022268583936
// https://twitter.com/yosupot/status/1581331729616633857
int main() {
  int n; cin >> n;
  vector<int> s(n);
  iota(ALL(s), 1);
  while (s.size() >= 3) {
    vector<int> a[3]{};
    REP(i, s.size()) a[i % 3].emplace_back(s[i]);
    if (query(a[0]) || query(a[0])) {
      a[query(a[1]) ? 2 : 1].clear();
    } else {
      a[0].clear();
    }
    s.clear();
    REP(i, 3) copy(ALL(a[i]), back_inserter(s));
  }
  for (const int x : s) {
    cout << "! " << x << endl;
    string answer; cin >> answer;
    if (answer == ":)") break;
  }
  return 0;
}