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
  int n, k; cin >> n >> k;
  int m = 1 << n;
  vector<int> a(m, 0);
  while (k--) {
    int ai; cin >> ai; --ai;
    a[ai] = 1;
  }
  function<vector<ll>(int, int)> rec = [&](int l, int r) {
    vector<ll> res(4, -LINF);
    if (l + 4 == r) {
      int left = a[l] + a[l + 1], right = a[l + 2] + a[l + 3];
      if (left > right) swap(left, right);
      if (left == 0 && right == 0) {
        res[0] = 0;
      } else if (left == 0 && right == 1) {
        res[0] = 3;
        res[1] = 3;
        res[2] = 2;
      } else if (left == 0 && right == 2) {
        res[0] = 4;
        res[1] = 4;
        res[2] = 4;
        res[3] = 4;
      } else if (left == 1 && right == 1) {
        res[0] = 5;
        res[1] = 5;
        res[2] = 5;
        res[3] = 5;
      } else if (left == 1 && right == 2) {
        res[1] = 5;
        res[2] = 5;
        res[3] = 5;
      } else if (left == 2 && right == 2) {
        res[3] = 5;
      }
    } else {
      int m = (l + r) >> 1;
      vector<ll> left = rec(l, m), right = rec(m, r);
      {
        chmax(res[0], left[0] + right[0]);
      }
      {
        chmax(res[0], left[0] + right[1] + 2);
        chmax(res[1], left[0] + right[1] + 2);
      }
      {
        chmax(res[0], left[0] + right[2] + 2);
        chmax(res[1], left[0] + right[2] + 2);
        chmax(res[2], left[0] + right[2] + 1);
      }
      {
        chmax(res[0], left[0] + right[3] + 3);
        chmax(res[1], left[0] + right[3] + 3);
        chmax(res[2], left[0] + right[3] + 3);
        chmax(res[3], left[0] + right[3] + 3);
      }
      {
        chmax(res[0], left[1] + right[1] + 2);
        chmax(res[1], left[1] + right[1] + 2);
      }
      {
        chmax(res[0], left[1] + right[2] + 3);
        chmax(res[1], left[1] + right[2] + 3);
        chmax(res[2], left[1] + right[2] + 3);
        chmax(res[3], left[1] + right[2] + 3);
      }
      {
        chmax(res[1], left[1] + right[3] + 3);
        chmax(res[2], left[1] + right[3] + 3);
        chmax(res[3], left[1] + right[3] + 3);
      }
      {
        chmax(res[2], left[2] + right[2] + 2);
        chmax(res[3], left[2] + right[2] + 2);
      }
      {
        chmax(res[2], left[2] + right[3] + 3);
        chmax(res[3], left[2] + right[3] + 3);
      }
      {
        chmax(res[3], left[3] + right[3] + 3);
      }
      swap(left, right);
      {
        chmax(res[0], left[0] + right[0]);
      }
      {
        chmax(res[0], left[0] + right[1] + 2);
        chmax(res[1], left[0] + right[1] + 2);
      }
      {
        chmax(res[0], left[0] + right[2] + 2);
        chmax(res[1], left[0] + right[2] + 2);
        chmax(res[2], left[0] + right[2] + 1);
      }
      {
        chmax(res[0], left[0] + right[3] + 3);
        chmax(res[1], left[0] + right[3] + 3);
        chmax(res[2], left[0] + right[3] + 3);
        chmax(res[3], left[0] + right[3] + 3);
      }
      {
        chmax(res[0], left[1] + right[1] + 2);
        chmax(res[1], left[1] + right[1] + 2);
      }
      {
        chmax(res[0], left[1] + right[2] + 3);
        chmax(res[1], left[1] + right[2] + 3);
        chmax(res[2], left[1] + right[2] + 3);
        chmax(res[3], left[1] + right[2] + 3);
      }
      {
        chmax(res[1], left[1] + right[3] + 3);
        chmax(res[2], left[1] + right[3] + 3);
        chmax(res[3], left[1] + right[3] + 3);
      }
      {
        chmax(res[2], left[2] + right[2] + 2);
        chmax(res[3], left[2] + right[2] + 2);
      }
      {
        chmax(res[2], left[2] + right[3] + 3);
        chmax(res[3], left[2] + right[3] + 3);
      }
      {
        chmax(res[3], left[3] + right[3] + 3);
      }
    }
    return res;
  };
  vector<ll> v = rec(0, m);
  ll ans = v[0];
  FOR(i, 1, 4) chmax(ans, v[i] + 1);
  cout << ans << '\n';
  return 0;
}