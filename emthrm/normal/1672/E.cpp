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

#ifndef ONLINE_JUDGE
vector<int> l;
#endif

int q = 0, limit = 0;

int query(int w) {
  static map<int, int> hs;
  if (hs.count(w)) return hs[w];
  if (++q > limit) {
    while (true) cout << "0\n";
  }
#ifdef ONLINE_JUDGE
  cout << "? " << w << endl;
  int h; cin >> h;
#else
  int h = 0;
  if (*max_element(ALL(l)) <= w) {
    int width = 0;
    for (int l_i : l) {
      if (width < l_i) {
        ++h;
        width = w;
      }
      width -= l_i + 1;
    }
  }
#endif
  return hs[w] = h;
}

int main() {
  constexpr int L = 2000;
  int n; cin >> n;
  limit = n + 30;
#ifndef ONLINE_JUDGE
  l.resize(n);
  REP(i, n) cin >> l[i];
#endif

  // int ans = INF;
  // int max_l = L;
  // {
  //   int lb = 0;
  //   while (max_l - lb > 1) {
  //     const int mid = (lb + max_l) / 2;
  //     (query(mid) == 0 ? lb : max_l) = mid;
  //   }
  // }
  // chmin(ans, max_l * query(max_l));
  // for (int w = max_l, h = query(max_l); h > 1;) {
  //   int lb = w, ub = w * 2 + 1;
  //   while (ub - lb > 1) {
  //     const int mid = (lb + ub) / 2;
  //     (query(mid) == h ? lb : ub) = mid;
  //   }
  //   w = ub;
  //   h = query(w);
  //   chmin(ans, h * w);
  // }

  int max_l = L;
  {
    int lb = 0;
    while (max_l - lb > 1) {
      const int mid = (lb + max_l) / 2;
      (query(mid) == 0 ? lb : max_l) = mid;
    }
  }
  int one_line = max_l * n + n - 1;
  {
    int lb = max_l - 1;
    while (one_line - lb > 1) {
      const int mid = (lb + one_line) / 2;
      (query(mid) == 1 ? one_line : lb) = mid;
    }
  }
  int ans = min(max_l * query(max_l), one_line);
  for (int h = 2; h < query(max_l);) {
    const int w = ans / h;
    if (w < max_l) break;
    if (query(w) > h) {
      h = query(w);
    } else {
      int lb = max_l, ub = w;
      while (ub - lb > 1) {
        const int mid = (lb + ub) / 2;
        (query(mid) == h ? ub : lb) = mid;
      }
      chmin(ans, h * ub);
      ++h;
    }
  }

  cout << "! " << ans << endl;
  return 0;
}