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

int query(int x, int y) {
  cout << "? " << x + 1 << ' ' << y + 1 << endl;
  int k; cin >> k;
  return k;
}

int main() {
  int n; cin >> n;
  vector p(n, -1);
  int cur = 0;
  FOR(i, 1, n) {
    int a = query(i, cur), b = query(cur, i);
    if (a > b) {
      p[i] = a;
    } else {
      p[cur] = b;
      cur = i;
    }
  }
  p[cur] = n;
  cout << "! ";
  REP(i, n) {
    cout << p[i];
    if (i + 1 == n) {
      cout << endl;
    } else {
      cout << ' ';
    }
  }
  return 0;
}