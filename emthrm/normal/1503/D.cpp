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

int main() {
  int n; cin >> n;
  vector<int> a(n), b(n), card(n * 2);
  REP(i, n) {
    cin >> a[i] >> b[i]; --a[i]; --b[i];
    card[a[i]] = card[b[i]] = i;
  }
  int ans = 0, l = 0, r = n * 2 - 1;
  vector<bool> used(n, false);
  while (l < r) {
    int cur = 0, flip = 0;
    vector<pair<int, int>> v{{l, card[l]}};
    assert(!used[card[l]]);
    used[card[l]] = true;
    bool put_l = true;
    ++l;
    while (!v.empty()) {
      // cout << l << ' ' << r << ": ";
      // for (auto [vf, vs] : v) cout << '{' << vf << ',' << vs << "} ";
      // cout << '\n';
      cur += v.size();
      vector<pair<int, int>> nx;
      vector<int> rb;
      for (auto [li, c] : v) {
        flip += li == b[c];
        rb.emplace_back(li == a[c] ? b[c] : a[c]);
      }
      if (put_l) {
        if (!is_sorted(rb.rbegin(), rb.rend())) {
          cout << "-1\n";
          return 0;
        }
        assert(r >= rb.front());
        for (int rb_i : rb) {
          while (r > rb_i) {
            if (used[card[r]]) {
              cout << "-1\n";
              return 0;
            }
            nx.emplace_back(r, card[r]);
            used[card[r]] = true;
            --r;
          }
          --r;
        }
      } else {
        if (!is_sorted(ALL(rb))) {
          cout << "-1\n";
          return 0;
        }
        assert(l <= rb.front());
        for (int rb_i : rb) {
          while (l < rb_i) {
            if (used[card[l]]) {
              cout << "-1\n";
              return 0;
            }
            nx.emplace_back(l, card[l]);
            used[card[l]] = true;
            ++l;
          }
          ++l;
        }
      }
      v.swap(nx);
      put_l = !put_l;
    }
    ans += min(flip, cur - flip);
  }
  assert(l > r);
  cout << ans << '\n';
  return 0;
}