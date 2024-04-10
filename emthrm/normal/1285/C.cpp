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
// const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
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

template <typename T>
vector<pair<T, int> > prime_factorization(T val) {
  vector<pair<T, int> > res;
  for (T i = 2; i * i <= val; ++i) {
    if (val % i != 0) continue;
    int exponent = 0;
    while (val % i == 0) {
      ++exponent;
      val /= i;
    }
    res.emplace_back(i, exponent);
  }
  if (val != 1) res.emplace_back(val, 1);
  return res;
}

int main() {
  ll x; cin >> x;
  if (x == 1) {
    cout << "1 1\n";
    return 0;
  }
  auto p = prime_factorization(x);
  int n = p.size();
  ll ans_a = LINF, ans_b = LINF;
  REP(i, 1 << n) {
    ll a = 1, b = 1;
    REP(j, n) {
      if (i >> j & 1) {
        REP(k, p[j].second) a *= p[j].first;
      } else {
        REP(k, p[j].second) b *= p[j].first;
      }
    }
    if (max(ans_a, ans_b) > max(a, b)) {
      ans_a = a;
      ans_b = b;
    }
  }
  cout << ans_a << ' ' << ans_b << '\n';
  return 0;
}