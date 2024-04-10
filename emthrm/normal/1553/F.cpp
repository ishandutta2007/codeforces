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

int main() {
  constexpr int M = 300000, S = 548;
  int n; cin >> n;
  int x[S]{}, exist[M + 1]{};
  FenwickTree<int> cnt(M + 1);
  FenwickTree<ll> pos(M + 1);
  ll p = 0, sum_a = 0;
  REP(index, n) {
    int a; cin >> a;
    if (a < S) {
      p += x[a];
    } else {
      p += sum_a;
      for (int i = a; i <= M; i += a) {
        p -= 1LL * i * cnt.sum(i, min(i + a, M + 1));
      }
    }
    p += 1LL * a * cnt.sum(a + 1, M + 1);
    int l = a;
    for (int i = 1; i * i <= a; ++i) {
      const int r = l;
      l = a / (i + 1);
      const int c = cnt.sum(l + 1, r + 1);
      p += 1LL * (a % r) * c;
      p += (pos.sum(l + 1, r + 1) - 1LL * c * (M - r)) * i;
    }
    for (; l >= 1; --l) {
      if (exist[l]) p += a % l;
    }
    cout << p << " \n"[index + 1 == n];
    FOR(i, 1, S) x[i] += a % i;
    exist[a] = true;
    cnt.add(a, 1);
    pos.add(a, M - a);
    sum_a += a;
  }
  return 0;
}