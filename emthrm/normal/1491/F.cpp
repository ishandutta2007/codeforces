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

int query(const vector<int> &a, const vector<int> &b) {
  int l = a.size(), r = b.size();
  cout << "? " << l << ' ' << r << endl;
  REP(i, l) cout << a[i] + 1 << " \n"[i + 1 == l];
  REP(i, r) {
    cout << b[i] + 1;
    if (i + 1 == r) {
      cout << endl;
    } else {
      cout << ' ';
    }
  }
  int force; cin >> force;
  return force;
}

void solve() {
  int n; cin >> n;
  vector<int> l{0};
  int magnet = -1;
  FOR(i, 1, n) {
    if (query(l, {i}) != 0) {
      magnet = i;
      break;
    }
    l.emplace_back(i);
  }
  vector<bool> is_mag(n, false);
  is_mag[magnet] = true;
  int lb = -1, ub = magnet - 1;
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    while (l.size() < mid + 1) l.emplace_back(l.size());
    while (l.size() > mid + 1) l.pop_back();
    (query(l, {magnet}) != 0 ? ub : lb) = mid;
  }
  is_mag[ub] = true;
  FOR(i, magnet + 1, n) {
    is_mag[i] = query({i}, {magnet}) != 0;
  }
  vector<int> a;
  REP(i, n) {
    if (!is_mag[i]) a.emplace_back(i);
  }
  int k = a.size();
  cout << "! " << k << ' ';
  REP(i, k) {
    cout << a[i] + 1;
    if (i + 1 == k) {
      cout << endl;
    } else {
      cout << ' ';
    }
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}