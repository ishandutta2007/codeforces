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

template <typename Abelian>
struct FenwickTree {
  FenwickTree(int n, const Abelian ID = 0) : n(n), ID(ID), dat(n, ID) {}

  void add(int idx, Abelian val) {
    while (idx < n) {
      dat[idx] += val;
      idx |= idx + 1;
    }
  }

  Abelian sum(int idx) const {
    Abelian res = ID;
    --idx;
    while (idx >= 0) {
      res += dat[idx];
      idx = (idx & (idx + 1)) - 1;
    }
    return res;
  }

  Abelian sum(int left, int right) const {
    return left < right ? sum(right) - sum(left) : ID;
  }

  Abelian operator[](const int idx) const { return sum(idx, idx + 1); }

  int lower_bound(Abelian val) const {
    if (val <= ID) return 0;
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
  const Abelian ID;
  std::vector<Abelian> dat;
};

int query(int l, int r) {
  cout << "? " << l + 1 << ' ' << r + 1 << endl;
  int sum; cin >> sum;
  assert(sum != -1);
  return sum;
}

int main() {
  constexpr int L = 10;
  int n, t, k; cin >> n >> t >> k;
  vector<int> l, r;
  for (int i = 0; i < n; i += L) {
    l.emplace_back(i);
    r.emplace_back(min(i + L, n) - 1);
  }
  int m = l.size();
  FenwickTree<int> bit(m);
  REP(i, m) bit.add(i, r[i] - l[i] + 1 - query(l[i], r[i]));
  while (t--) {
    int s = bit.lower_bound(k);
    k -= bit.sum(s);
    int lb = l[s] - 1, ub = r[s];
    while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      (mid - l[s] + 1 - query(l[s], mid) < k ? lb : ub) = mid;
    }
    cout << "! " << ub + 1 << endl;
    bit.add(s, -1);
    if (t > 0) cin >> k;
  }
  return 0;
}