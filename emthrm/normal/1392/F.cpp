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

int main() {
  int n; cin >> n;
  vector<ll> h(n); REP(i, n) cin >> h[i];
  // while (true) {
  //   vector<int> landslide;
  //   FOR(i, 1, n) {
  //     if (h[i - 1] + 2 <= h[i]) landslide.emplace_back(i);
  //   }
  //   if (landslide.empty()) break;
  //   for (int idx : landslide) {
  //     ++h[idx - 1];
  //     --h[idx];
  //   }
  //   REP(i, n) cout << h[i] << " \n"[i + 1 == n];
  // }
  ll sum = accumulate(ALL(h), 0LL);
  ll lb = -1, ub = 1000000000000;
  while (ub - lb > 1) {
    ll mid = (lb + ub) >> 1;
    (sum <= (mid * 2 + n - 1) * n / 2 ? ub : lb) = mid;
  }
  ll diff = (ub * 2 + n - 1) * n / 2;
  int same = n - (diff - sum);
  REP(i, n) {
    cout << ub << " \n"[i + 1 == n];
    if (i + 1 != same) ++ub;
  }
  return 0;
}