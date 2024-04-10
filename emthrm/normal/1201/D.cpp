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

#define int long long
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
signed main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, m, k, q; cin >> n >> m >> k >> q;
  vector<vector<int> > tre(n);
  while (k--) {
    int r, c; cin >> r >> c; --r; --c;
    tre[r].emplace_back(c);
  }
  REP(i, n) sort(ALL(tre[i]));
  vector<int> b(q);
  REP(i, q) {
    cin >> b[i]; --b[i];
  }
  sort(ALL(b));
  for (int i = n - 1; i >= 0; --i) {
    if (tre[i].empty()) {
      tre.pop_back();
    } else {
      break;
    }
  }
  n = tre.size();
  if (n == 1) {
    cout << tre[0].back() << '\n';
    return 0;
  }
  vector<vector<long long> > memo(n - 1, vector<long long>(4, LINF)), idx(n - 1, vector<long long>(4, -1));
  if (!tre[0].empty()) {
    int Mae = tre[0].front(), Ush = tre[0].back();
    int Midx0 = -1, Midx1 = lower_bound(ALL(b), Mae) - b.begin(), Uidx0 = -1, Uidx1 = lower_bound(ALL(b), Ush) - b.begin();
    if (Midx1 == q) {
      Midx1 = -1;
    } else if (b[Midx1] != Mae) {
      if (Midx1 > 0) Midx0 = Midx1 - 1;
    }
    if (Uidx1 == q) {
      Uidx1 = -1;
      Uidx0 = q - 1;
    } else if (b[Uidx1] != Ush) {
      if (Uidx1 > 0) Uidx0 = Uidx1 - 1;
    }
    idx[0][0] = Midx0;
    idx[0][1] = Midx1;
    idx[0][2] = Uidx0;
    idx[0][3] = Uidx1;
    REP(k, 4) if (idx[0][k] != -1) {
      int y = idx[0][k];
      long long dist = b[y];
      dist += max(Ush - b[y], 0LL) * 2;
      memo[0][k] = dist;
    }
  } else {
    memo[0][0] = b[0];
    idx[0][0] = 0;
  }
  REP(i, n - 2) {
    if (tre[i + 1].empty()) {
      memo[i + 1] = memo[i];
      idx[i + 1] = idx[i];
      continue;
    }
    int mae = tre[i + 1].front(), ush = tre[i + 1].back();
    int midx0 = -1, midx1 = lower_bound(ALL(b), mae) - b.begin(), uidx0 = -1, uidx1 = lower_bound(ALL(b), ush) - b.begin();
    if (midx1 == q) {
      midx1 = -1;
    } else if (b[midx1] != mae) {
      if (midx1 > 0) midx0 = midx1 - 1;
    }
    if (uidx1 == q) {
      uidx1 = -1;
      uidx0 = q - 1;
    } else if (b[uidx1] != ush) {
      if (uidx1 > 0) uidx0 = uidx1 - 1;
    }
    idx[i + 1][0] = midx0;
    idx[i + 1][1] = midx1;
    idx[i + 1][2] = uidx0;
    idx[i + 1][3] = uidx1;
    REP(j, 4) REP(k, 4) if (idx[i][j] != -1 && idx[i + 1][k] != -1) {
      int x = idx[i][j], y = idx[i + 1][k];
      long long dist = memo[i][j];
      dist += abs(b[x] - b[y]);
      dist += max(min(b[x], b[y]) - mae, 0LL) * 2;
      dist += max(ush - max(b[x], b[y]), 0LL) * 2;
      memo[i + 1][k] = min(memo[i + 1][k], dist);
      // cout << memo[i][j] << ' ' << b[x] << '|' << memo[i + 1][k] << ' ' << b[y] << '\n';
    }
  }
  long long ans = LINF;
  int left = tre[n - 1].front(), right = tre[n - 1].back();
  REP(j, 4) if (idx[n - 2][j] != -1) {
    int x = idx[n - 2][j];
    memo[n - 2][j] += n - 1;
    // cout << memo[n - 2][j] << '\n';
    int l = max(b[x] - left, 0LL), r = max(right - b[x], 0LL);
    // cout << l << ' ' << r << '\n';
    ans = min(ans, memo[n - 2][j] + min(l, r) * 2 + max(l, r));
  }
  cout << ans << '\n';
  return 0;
}