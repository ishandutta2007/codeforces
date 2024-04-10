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

bool is_prime(ll val) {
  if (val <= 1) return false;
  for (ll i = 2; i * i <= val; ++i) {
    if (val % i == 0) return false;
  }
  return true;
}

template <typename T>
vector<pair<T, int>> prime_factorization(T val) {
  vector<pair<T, int>> res;
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

int query(ll q) {
  cout << "? " << q << endl;
  int g; cin >> g;
  return g;
}

vector<ll> qs;

void solve() {
  int x = 1;
  for (ll q : qs) x *= query(q);
  REP(_, 4) x = query(1LL * x * x);
  int ans = 1;
  for (auto [ignore, num] : prime_factorization(x)) ans *= num + 1;
  cout << "! " << max(ans << 1, 8) << endl;
}

int main() {
  int p = 2;
  while (qs.size() < 18) {
    ll now = 1;
    while (true) {
      while (!is_prime(p)) ++p;
      if (log10(now) + log10(p) > 18 - EPS) break;
      now *= p++;
    }
    qs.emplace_back(now);
  }
  int t; cin >> t;
  while (t--) solve();
  return 0;
}