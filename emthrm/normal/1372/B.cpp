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

template <typename T>
vector<T> divisor(T val) {
  vector<T> res;
  for (T i = 1; i * i <= val; ++i) {
    if (val % i == 0) {
      res.emplace_back(i);
      if (i * i != val) res.emplace_back(val / i);
    }
  }
  sort(ALL(res));
  return res;
}

void solve() {
  int n; cin >> n;
  int a = 1, b = n - 1, l = b;
  for (int ai : divisor(n)) {
    if (n - ai >= ai && n - ai < l) {
      a = ai;
      b = n - ai;
    }
  }
  cout << a << ' ' << b << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}