#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int h, w; cin >> h >> w;
  // vector<int> per(h * w - 1);
  // iota(ALL(per), 1);
  // do {
  //   vector<vector<bool> > visited(h, vector<bool>(w));
  //   set<pair<int, int> > st;
  //   int y = 0, x = 0;
  //   REP(i, h * w - 1) {
  //     int ny = per[i] / w, nx = per[i] % w;
  //     st.emplace(ny - y, nx - x);
  //     y = ny; x = nx;
  //   }
  //   if (st.size() == h * w - 1) {
  //     REP(i, h * w - 1) cout << '(' << per[i] / w << ',' << per[i] % w << ") ";
  //     cout << '\n';
  //   }
  // } while (next_permutation(ALL(per)));
  vector<int> y{1}, x{1};
  int ue = 1, shita = h;
  while (ue < shita) {
    for (int ue_x = 1, shita_x = w; ue_x <= w && shita_x >= 0; --shita_x) {
      y.emplace_back(shita);
      x.emplace_back(shita_x);
      ++ue_x;
      if (ue_x <= w) {
        y.emplace_back(ue);
        x.emplace_back(ue_x);
      }
    }
    ++ue;
    --shita;
    if (ue <= shita) {
      y.emplace_back(ue);
      x.emplace_back(1);
    }
  }
  if (ue == shita) {
    int hidari = 1, migi = w;
    while (hidari < migi) {
      y.emplace_back(ue);
      x.emplace_back(migi);
      ++hidari;
      if (hidari < migi) {
        y.emplace_back(ue);
        x.emplace_back(hidari);
      }
      --migi;
    }
  }
  set<pair<int, int> > st;
  FOR(i, 1, y.size()) st.emplace(y[i] - y[i - 1], x[i] - x[i - 1]);
  if (st.size() < h * w - 1) assert(false);
  REP(i, y.size()) cout << y[i] << ' ' << x[i] << '\n';
  return 0;
}