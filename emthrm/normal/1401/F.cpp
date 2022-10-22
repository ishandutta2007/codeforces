#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

template <typename Abelian>
struct BIT {
  BIT(int n, const Abelian UNITY = 0) : n(n), UNITY(UNITY), dat(n, UNITY) {}

  void add(int idx, Abelian val) {
    while (idx < n) {
      dat[idx] += val;
      idx |= idx + 1;
    }
  }

  Abelian sum(int idx) const {
    Abelian res = UNITY;
    --idx;
    while (idx >= 0) {
      res += dat[idx];
      idx = (idx & (idx + 1)) - 1;
    }
    return res;
  }

  Abelian sum(int left, int right) const {
    return left < right ? sum(right) - sum(left) : UNITY;
  }

  Abelian operator[](const int idx) const { return sum(idx, idx + 1); }

  int lower_bound(Abelian val) const {
    if (val <= UNITY) return 0;
    int res = 0, exponent = 1;
    while (exponent <= n) exponent <<= 1;
    for (int mask = exponent >> 1; mask > 0; mask >>= 1) {
      if (res + mask - 1 < n && dat[res + mask - 1] < val) {
        val -= dat[res + mask - 1];
        res += mask;
      }
    }
    return res;
  }

private:
  int n;
  const Abelian UNITY;
  std::vector<Abelian> dat;
};

int main() {
  int n, q; cin >> n >> q;
  BIT<ll> a(1 << n);
  REP(i, 1 << n) {
    int ai; cin >> ai;
    a.add(i, ai);
  }
  int x = 0;
  while (q--) {
    int query; cin >> query;
    if (query == 1) {
      int i, k; cin >> i >> k; --i;
      a.add(i ^ x, -a[i ^ x]);
      a.add(i ^ x, k);
    } else if (query == 2) {
      int k; cin >> k;
      x ^= (1 << k) - 1;
    } else if (query == 3) {
      int k; cin >> k;
      x ^= 1 << k;
    } else if (query == 4) {
      int l, r; cin >> l >> r; --l;
      ll ans = 0;
      while (l < r) {
        int k = 0;
        while (l + (1 << (k + 1)) <= r && !(l >> k & 1)) ++k;
        ans += a.sum(l ^ (x & ~((1 << k) - 1)), (l ^ (x & ~((1 << k) - 1))) + (1 << k));
        l += 1 << k;
      }
      cout << ans << '\n';
    }
  }
  return 0;
}