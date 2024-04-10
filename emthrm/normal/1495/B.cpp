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

int main() {
  int n; cin >> n;
  vector<int> p(n); REP(i, n) cin >> p[i], --p[i];
  multiset<int> len;
  int i = 0;
  if (p[0] > p[1]) {
    int j = 2;
    while (j < n && p[j - 1] > p[j]) ++j;
    len.emplace(j);
    i = j - 1;
  }
  while (i < n) {
    int j = i + 1;
    while (j < n && p[j - 1] < p[j]) ++j;
    if (j - i == 1) break;
    len.emplace(j - i);
    if (j >= n) break;
    int k = j + 1;
    while (k < n && p[k - 1] > p[k]) ++k;
    len.emplace(k - j + 1);
    i = k - 1;
  }
  int ans = 0;
  i = 0;
  if (p[0] > p[1]) {
    int j = 2;
    while (j < n && p[j - 1] > p[j]) ++j;
    i = j - 1;
  }
  while (i < n) {
    int j = i + 1;
    while (j < n && p[j - 1] < p[j]) ++j;
    if (j >= n || j - i == 1) break;
    int k = j + 1;
    while (k < n && p[k - 1] > p[k]) ++k;
    int l = j - i, r = k - j + 1;
    if (l == r && l % 2 == 1) {
      len.erase(len.lower_bound(l));
      len.erase(len.lower_bound(r));
      ans += len.empty() || *len.rbegin() < l;
      len.emplace(l);
      len.emplace(r);
    }
    i = k - 1;
  }
  cout << ans << '\n';
  return 0;
}