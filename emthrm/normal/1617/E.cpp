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
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  constexpr int B = 30;
  int n; cin >> n;
  int zero = -1;
  vector<pair<vector<int>, int>> a[B]{};
  int bother[B]{}, argmax[B]{};
  fill(bother, bother + B, -1);
  fill(argmax, argmax + B, -1);
  REP(i, n) {
    int ai; cin >> ai;
    if (ai == 0) {
      zero = i;
    } else {
      const int ctz = __builtin_ctz(ai);
      ai >>= ctz + 1;
      vector<int> blocks;
      while (ai > 0) {
        int b = 1;
        while ((ai >> b & 1) == (ai & 1)) ++b;
        blocks.emplace_back(b);
        ai >>= b;
      }
      reverse(ALL(blocks));
      a[ctz].emplace_back(blocks, i);
      if (chmax(bother[ctz], int(blocks.size()) + 1)) argmax[ctz] = i;
    }
  }
  // REP(i, B) cerr << bother[i] << " \n"[i + 1 == B];
  // REP(i, B) cerr << argmax[i] << " \n"[i + 1 == B];
  int x = -1, y = -1, ans = 0;
  if (zero != -1) {
    const int arg = max_element(bother, bother + B) - bother;
    ans = bother[arg];
    x = zero;
    y = argmax[arg];
  }
  REP(i, B) FOR(j, i + 1, B) {
    if (bother[i] != -1 && bother[j] != -1 && chmax(ans, bother[i] + bother[j])) {
      x = argmax[i];
      y = argmax[j];
    }
  }
  auto f = [&](auto&& f, const vector<pair<vector<int>, int>>& blocks) -> void {
    map<int, pair<vector<pair<vector<int>, int>>, pair<int, int>>> m;
    for (pair<vector<int>, int> block : blocks) {
      if (block.first.empty()) {
        m[0].second = {0, block.second};
      } else {
        const int key = block.first.back();
        block.first.pop_back();
        m[key].first.emplace_back(block);
        if (chmax(m[key].second.first, int(block.first.size()) + 1)) m[key].second.second = block.second;
      }
    }
    vector<pair<int, int>> mx;
    for (const auto [_, subblock] : m) {
      mx.emplace_back(subblock.second);
      if (subblock.first.size() > 1) f(f, subblock.first);
    }
    if (mx.size() >= 2) {
      sort(ALL(mx), greater<pair<int, int>>());
      if (chmax(ans, mx[0].first + mx[1].first)) {
        x = mx[0].second;
        y = mx[1].second;
      }
    }
  };
  REP(b, B) {
    if (a[b].size() >= 2) f(f, a[b]);
  }
  cout << x + 1 << ' ' << y + 1 << ' ' << ans << '\n';
  return 0;
}