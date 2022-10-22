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

void solve() {
  string s; cin >> s;
  vector<char> cs;
  for (char c : s) cs.emplace_back(c);
  sort(ALL(cs));
  cs.erase(unique(ALL(cs)), cs.end());
  int m = cs.size();
  vector<int> a(s.length());
  for (int i = s.length() - 1; i >= 0; --i) a[s.length() - 1 - i] = lower_bound(ALL(cs), s[i]) - cs.begin();
  vector<int> ans;
  while (ans.size() < m) {
    int i = 0, cnt = 0;
    vector<bool> exist(m, false);
    while (true) {
      if (!exist[a[i]]) ++cnt;
      if (cnt == m - ans.size()) break;
      exist[a[i++]] = true;
    }
    int ch = *max_element(a.begin() + i, a.end());
    ans.emplace_back(ch);
    while (a.back() != ch) a.pop_back();
    vector<int> nx;
    for (int e : a) {
      if (e != ch) nx.emplace_back(e);
    }
    a.swap(nx);
  }
  REP(i, m) cout << cs[ans[i]];
  cout << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}