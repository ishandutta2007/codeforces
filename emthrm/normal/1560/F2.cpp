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

constexpr int D = 10;

void solve() {
  string n; int k; cin >> n >> k;
  ll N = stoll(n);
  const int l = n.length();
  vector<ll> w(l, 1);
  for (int i = l - 2; i >= 0; --i) w[i] = w[i + 1] * 10;
  vector<ll> sum = w;
  for (int i = l - 2; i >= 0; --i) sum[i] += sum[i + 1];
  int lb = 0, ub = l + 1;
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    set<int> digit;
    ll num = 0;
    REP(i, mid) {
      num += w[i] * (n[i] - '0');
      digit.emplace(n[i] - '0');
    }
    if (digit.size() > k) {
      ub = mid;
      continue;
    } else if (digit.size() == k) {
      if (mid < l) num += sum[mid] * *digit.rbegin();
    } else {
      if (mid < l) num += sum[mid] * 9;
    }
    (num >= N ? lb : ub) = mid;
  }
  if (lb == l) {
    cout << N << '\n';
    return;
  }
  ll ans = 0;
  set<int> digit;
  REP(i, lb) {
    ans += w[i] * (n[i] - '0');
    digit.emplace(n[i] - '0');
  }
  FOR(lb_d, n[lb] - '0' + 1, D) {
    set<int> tmp_digit = digit;
    tmp_digit.emplace(lb_d);
    if (tmp_digit.size() > k) continue;
    ll tmp_ans = ans + w[lb] * lb_d;
    if (lb + 1 < l) tmp_ans += sum[lb + 1] * (tmp_digit.size() == k ? *tmp_digit.rbegin() : 9);
    if (tmp_ans >= N) {
      ans += w[lb] * lb_d;
      digit.emplace(lb_d);
      break;
    }
  }
  if (lb + 1 < l && digit.size() == k) ans += sum[lb + 1] * *digit.begin();
  cout << ans << '\n';
  // while (true) {
  //   int popcnt = 0;
  //   for (char c : to_string(N)) popcnt |= 1 << (c - '0');
  //   if (__builtin_popcount(popcnt) <= k) {
  //     // assert(N == ans);
  //     break;
  //   }
  //   ++N;
  // }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}