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
constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};
constexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

struct Mo {
  explicit Mo(const std::vector<int>& ls, const std::vector<int>& rs)
      : ls(ls), rs(rs), n(ls.size()), ptr(0), nl(0), nr(0) {
    const int width = std::round(std::sqrt(n));
    order.resize(n);
    std::iota(order.begin(), order.end(), 0);
    std::sort(order.begin(), order.end(),
              [&ls, &rs, width](const int a, const int b) -> bool {
                  if (ls[a] / width != ls[b] / width) return ls[a] < ls[b];
                  return (ls[a] / width) & 1 ? rs[a] < rs[b] : rs[a] > rs[b];
              });
  }

  int process() {
    if (ptr == n) return -1;
    const int id = order[ptr++];
    while (ls[id] < nl) add(--nl);
    while (nr < rs[id]) add(nr++);
    while (nl < ls[id]) del(nl++);
    while (rs[id] < nr) del(--nr);
    return id;
  }

  void add(const int idx) const;

  void del(const int idx) const;

 private:
  const int n;
  int ptr, nl, nr;
  std::vector<int> ls, rs, order;
};

constexpr int N = 200000, A = 1000000;
int a[N], k[A + 1]{};
ll ans = 0;

void Mo::add(const int idx) const {
  ans -= 1LL * k[a[idx]] * k[a[idx]] * a[idx];
  ++k[a[idx]];
  ans += 1LL * k[a[idx]] * k[a[idx]] * a[idx];
}

void Mo::del(const int idx) const {
  ans -= 1LL * k[a[idx]] * k[a[idx]] * a[idx];
  --k[a[idx]];
  ans += 1LL * k[a[idx]] * k[a[idx]] * a[idx];
}

int main() {
  int n, t; cin >> n >> t;
  REP(i, n) cin >> a[i];
  vector<int> l(t), r(t); REP(i, t) cin >> l[i] >> r[i], --l[i];
  Mo mo(l, r);
  vector<ll> b(t);
  REP(_, t) {
    const int id = mo.process();
    b[id] = ans;
  }
  REP(i, t) cout << b[i] << '\n';
  return 0;
}