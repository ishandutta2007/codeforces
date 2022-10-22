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
  int n, k; string s; cin >> n >> k >> s;
  if (n % k > 0) {
    cout << "-1\n";
    return;
  }
  int lb = 0, ub = n + 1;
  while (ub - lb > 1) {
    int mid = (lb + ub) >> 1;
    int occ[C] = {};
    REP(i, mid) ++occ[s[i] - 'a'];
    int lack[C] = {};
    REP(i, C) lack[i] += (occ[i] + k - 1) / k * k - occ[i];
    int need = accumulate(lack, lack + C, 0);
    if (mid + need > n) {
      ub = mid;
      continue;
    }
    lack[C - 1] += n - (mid + need);
    string t = "";
    for (int i = C - 1; i >= 0; --i) t += string(lack[i], 'a' + i);
    bool ok = true;
    FOR(j, mid, n) {
      if (t[j - mid] > s[j]) break;
      if (t[j - mid] < s[j]) {
        ok = false;
        break;
      }
    }
    (ok ? lb : ub) = mid;
  }
  string ans = s.substr(0, lb);
  if (lb == n) {
    cout << ans << '\n';
    return;
  }
  int occ[C] = {};
  REP(i, lb) ++occ[s[i] - 'a'];
  int lack[C] = {};
  REP(i, C) lack[i] = (occ[i] + k - 1) / k * k - occ[i];
  int rem = n - (lb + accumulate(lack, lack + C, 0));
  assert(s[lb] < 'z' && rem % k == 0);
  if (rem > 0) {
    if (lack[s[lb] - 'a' + 1] == 0) {
      lack[s[lb] - 'a' + 1] = k;
      rem -= k;
    }
    lack[0] += rem;
  }
  FOR(i, s[lb] - 'a' + 1, C) {
    if (lack[i] > 0) {
      ans += 'a' + i;
      --lack[i];
      break;
    }
  }
  REP(i, C) ans += string(lack[i], 'a' + i);
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}