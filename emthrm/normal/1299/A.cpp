#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
template <typename T> using posteriority_queue = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
template <typename T> void unique(vector<T> &a) { a.erase(unique(ALL(a)), a.end()); }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<int> cnt(31, 0);
  REP(i, n) {
    REP(j, 31) cnt[j] += !(a[i] >> j & 1);
  }
  int idx = 0, mx = -INF;
  REP(i, n) {
    REP(j, 31) cnt[j] -= !(a[i] >> j & 1);
    int tmp = 0;
    REP(j, 31) {
      if ((a[i] >> j & 1) && cnt[j] == n - 1) tmp |= 1 << j;
    }
    if (tmp > mx) {
      mx = tmp;
      idx = i;
    }
    REP(j, 31) cnt[j] += !(a[i] >> j & 1);
  }
  vector<int> ans(n);
  iota(ALL(ans), 0);
  ans.erase(ans.begin() + idx);
  ans.emplace(ans.begin(), idx);
  REP(i, n) cout << a[ans[i]] << " \n"[i + 1 == n];
  return 0;
}