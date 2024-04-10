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

vector<ll> solve(ll n) {
  if (n == 1) return {1, 2, 3};
  --n;
  ll now = 1;
  for (int digit = 0; ; ++digit) {
    if (n < now) {
      ll res = 0, weight = 1;
      {
        ll tmp = 1;
        REP(_, digit) tmp *= 4;
        res += tmp;
      }
      while (n > 0) {
        res += (n % 4) * weight;
        n /= 4;
        weight *= 4;
      }
      int ub = 0;
      REP(i, 64) {
        if (res >> i & 1) ub = i;
      }
      assert(ub % 2 == 0);
      ll b = 0, c = 0;
      for (int i = 0; i <= ub; i += 2) {
        ll tmp = (res >> i) & 3;
        if (tmp == 1) {
          b |= 2LL << i;
          c |= 3LL << i;
        } else if (tmp == 2) {
          b |= 3LL << i;
          c |= 1LL << i;
        } else if (tmp == 3) {
          b |= 1LL << i;
          c |= 2LL << i;
        }
      }
      return {res, b, c};
    }
    n -= now;
    now *= 4;
  }
}

int main() {
  int t; cin >> t;
  while (t--) {
    ll n; cin >> n;
    vector<ll> ans = solve((n + 2) / 3);
    cout << ans[(n - 1) % 3] << '\n';
  }
  return 0;

  // set<int> st{1, 2, 3, 4, 8, 12, 5, 10, 15};
  // while (st.size() < 100) {
  //   int i = 5;
  //   for (;; ++i) {
  //     if (st.count(i) == 0) break;
  //   }
  //   st.emplace(i);
  //   for (int j = i + 1; ; ++j) {
  //     if (st.count(j) == 0 && st.count(i ^ j) == 0) {
  //       cout << bitset<10>(i) << ' ' << bitset<10>(j) << ' ' << bitset<10>(i ^ j) << '\n';
  //       st.emplace(j);
  //       st.emplace(i ^ j);
  //       break;
  //     }
  //   }
  // }
}