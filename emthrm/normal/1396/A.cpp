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
pair<T, T> ext_gcd(T a, T b) {
  if (b == 0) return {1, 0};
  T fst, snd; tie(fst, snd) = ext_gcd(b, a % b);
  return {snd, fst - a / b * snd};
}

int main() {
  int n; cin >> n;
  vector<ll> a(n); REP(i, n) cin >> a[i];
  if (n == 1) {
    cout << "1 1\n0\n";
  } else {
    cout << 1 << ' ' << n - 1 << '\n';
    ll tmp = -ext_gcd(1LL * n, n - 1LL).second * (n - 1);
    REP(i, n - 1) {
      ll add = tmp * a[i];
      a[i] += add;
      cout << add << " \n"[i == n - 2];
    }
  }
  cout << n << ' ' << n << '\n' << n - a[n - 1] << '\n';
  a[n - 1] = n;
  cout << 1 << ' ' << n << '\n';
  REP(i, n) cout << -a[i] << " \n"[i + 1 == n];
  return 0;
}