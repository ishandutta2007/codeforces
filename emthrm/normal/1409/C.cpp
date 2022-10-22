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
  int n, x, y; cin >> n >> x >> y;
  int ans = INF;
  vector<int> a;
  for (int diff : divisor(y - x)) {
    vector<int> elem;
    for (int i = y; i >= x; i -= diff) elem.emplace_back(i);
    if (elem.size() > n) continue;
    for (int i = x - diff; i > 0 && elem.size() < n; i -= diff) elem.emplace_back(i);
    for (int i = y + diff; elem.size() < n; i += diff) elem.emplace_back(i);
    int sum = *max_element(ALL(elem));
    if (sum < ans) {
      ans = sum;
      a = elem;
    }
  }
  REP(i, n) cout << a[i] << " \n"[i + 1 == n];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}