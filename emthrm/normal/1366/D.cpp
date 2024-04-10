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

struct osa_k {
  osa_k(int val = 10000000) : least_prime_factor(val + 1, -1) {
    least_prime_factor[0] = 0;
    if (val >= 1) least_prime_factor[1] = 1;
    FOR(i, 2, val + 1) if (least_prime_factor[i] == -1) {
      least_prime_factor[i] = i;
      for (ll j = 1LL * i * i; j <= val; j += i) {
        if (least_prime_factor[j] == -1) least_prime_factor[j] = i;
      }
    }
  }

  vector<pair<int, int>> query(int val) {
    vector<pair<int, int>> res;
    while (val > 1) {
      int prime = least_prime_factor[val], exponent = 0;
      while (least_prime_factor[val] == prime) {
        ++exponent;
        val /= prime;
      }
      res.emplace_back(prime, exponent);
    }
    return res;
  }

private:
  vector<int> least_prime_factor;
};

int main() {
  osa_k osa(10000000);
  int n; cin >> n;
  vector<int> d1(n, -1), d2(n, -1);
  REP(i, n) {
    int a; cin >> a;
    vector<pair<int, int>> d = osa.query(a);
    d1[i] = a;
    d2[i] = 1;
    while (d1[i] % d[0].first == 0) {
      d1[i] /= d[0].first;
      d2[i] *= d[0].first;
    }
    if (d1[i] == 1 || d2[i] == 1 || __gcd(a, d1[i] + d2[i]) > 1) d1[i] = d2[i] = -1;
  }
  REP(i, n) cout << d1[i] << " \n"[i + 1 == n];
  REP(i, n) cout << d2[i] << " \n"[i + 1 == n];
  return 0;
}