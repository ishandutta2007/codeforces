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

void solve() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  if (int num = accumulate(ALL(a), 0); num % 2 == 1 || num == n) {
    cout << "NO\n";
    return;
  }
  vector<int> b;
  auto op = [&](int bi) -> void {
    a[bi] = a[bi + 1] = a[bi + 2] = a[bi] ^ a[bi + 1] ^ a[bi + 2];
    b.emplace_back(bi);
  };
  auto solve = [&]() -> void {
    assert(a.front() == 0);
    for (int i = 1; i + 3 <= n;) {
      if (a[i] == 0) {
        ++i;
      } else if ((a[i] ^ a[i + 1] ^ a[i + 2]) == 0) {
        op(i);
        i += 3;
      } else {
        if (a[i + 1] == 0) op(i);
        op(i - 1);
      }
    }
    if (a[n - 2] == 1) {
      assert(a[n - 1] == 1);
      op(n - 3);
    }
  };
  if (a.front() == 1) {
    int j = 1;
    while (a[j] == 1) ++j;
    if (j % 2 == 0) {
      for (int i = j - 2; i >= 0; i -= 2) op(i);
      solve();
    } else if (a.back() == 0) {
      reverse(ALL(a));
      solve();
      for (int &bi : b) bi = n - 1 - bi - 2;
    } else {
      j = n - 2;
      while (a[j] == 1) --j;
      if ((n - (j + 1)) % 2 == 0) {
        reverse(ALL(a));
        j = 1;
        while (a[j] == 1) ++j;
        assert(j % 2 == 0);
        for (int i = j - 2; i >= 0; i -= 2) op(i);
        solve();
        for (int &bi : b) bi = n - 1 - bi - 2;
      } else {
        j = 0;
        while (true) {
          int k = j + 1;
          while (k < n && a[k] == 1) ++k;
          if (k == n) {
            assert(n % 2 == 0);
            cout << "NO\n";
            return;
          }
          if (k % 2 == 0) {
            for (int i = k - 2; i >= 0; i -= 2) op(i);
            break;
          }
          j = k;
          k = j + 1;
          while (a[k] == 0) ++k;
          if ((k - j) % 2 == 1) {
            for (; j + 1 < k; j += 2) op(j - 1);
            assert(a[j - 1] == 1 && a[j] == 0 && a[j + 1] == 1);
            op(j - 1);
            for (int i = j - 3; i >= 0; i -= 2) op(i);
            break;
          }
          for (; j < k; j += 2) op(j - 1);
          assert(j == k);
        }
        solve();
      }
    }
  } else {
    solve();
  }
  assert(count(ALL(a), 1) == 0);
  const int k = b.size();
  cout << "YES\n" << k << '\n';
  REP(i, k) cout << b[i] + 1 << " \n"[i + 1 == k];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}