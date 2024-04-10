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
  constexpr int B = 316;
  int n, q; cin >> n >> q;
  vector<int> p(n); REP(i, n) cin >> p[i], --p[i];
  vector<int> type(q), xi(q), yk(q);
  REP(i, q) {
    cin >> type[i] >> xi[i] >> yk[i]; --xi[i];
    if (type[i] == 1) --yk[i];
  }
  for (int l = 0; l < q;) {
    const int r = min(l + B, q);
    vector<int> mv(n, -2);
    FOR(i, l, r) {
      mv[xi[i]] = -1;
      if (type[i] == 1) mv[yk[i]] = -1;
    }
    vector<vector<int>> block;
    REP(i, n) {
      if (mv[i] != -1 || mv[p[i]] != -2) continue;
      const int id = block.size();
      block.emplace_back();
      for (int j = p[i]; mv[j] == -2; j = p[j]) {
        block.back().emplace_back(j);
        mv[j] = id;
      }
    }
    FOR(i, l, r) {
      if (type[i] == 1) {
        swap(p[xi[i]], p[yk[i]]);
      } else if (type[i] == 2) {
        int len = 1;
        for (int j = p[xi[i]]; j != xi[i];) {
          if (mv[j] == -1) {
            ++len;
            j = p[j];
          } else {
            len += block[mv[j]].size();
            j = p[block[mv[j]].back()];
          }
        }
        yk[i] %= len;
        while (yk[i] > 0) {
          if (mv[xi[i]] == -1) {
            --yk[i];
            xi[i] = p[xi[i]];
          } else if (block[mv[xi[i]]].size() > yk[i]) {
            xi[i] = block[mv[xi[i]]][yk[i]];
            yk[i] = 0;
            break;
          } else {
            yk[i] -= block[mv[xi[i]]].size();
            xi[i] = p[block[mv[xi[i]]].back()];
          }
        }
        cout << xi[i] + 1 << '\n';
      }
    }
    l = r;
  }
  return 0;
}