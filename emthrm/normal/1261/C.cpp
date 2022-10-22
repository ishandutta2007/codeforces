#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
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
const int MOD = 1000000007;
// const int MOD = 998244353;
// const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1},
          dx[] = {0, -1, -1, -1, 0, 1, 1, 1};

struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(10);
  }
} iosetup;
/*-------------------------------------------------*/
int n, m;
vector<string> forest;
vector<vector<long long> > sum;

bool ok(int u, int l, int r, int d) {
  long long burned = sum[d + 1][r + 1] - sum[d + 1][l] - sum[u][r + 1] + sum[u][l];
  return burned == (long long)(r - l + 1) * (d - u + 1);
}

bool bs(int mid) {
  vector<vector<char> > ori(n, vector<char>(m, '.'));
  REP(i, n) REP(j, m) {
    int u = i - mid, l = j - mid, r = j + mid, d = i + mid;
    if (u < 0 || l < 0 || r >= m || d >= n) continue;
    ori[i][j] = (ok(u, l, r, d) ? 'X' : '.');
  }
  // REP(i, n) {
  //   REP(j, m) cout << ori[i][j];
  //   cout << '\n';
  // }
  queue<pair<int, int> > que;
  vector<vector<char> > sim(n, vector<char>(m, '.'));
  REP(i, n) REP(j, m) {
    if (ori[i][j] == 'X') {
      sim[i][j] = 'X';
      que.emplace(i, j);
    }
  }
  REP(_, mid) {
    vector<pair<int, int> > vec;
    while (!que.empty()) {
      vec.emplace_back(que.front());
      que.pop();
    }
    for (auto &pr : vec) {
      int i = pr.first, j = pr.second;
      REP(k, 8) {
        int y = i + dy[k], x = j + dx[k];
        if (y < 0 || n <= y || x < 0 || m <= x) return false;
        if (sim[y][x] == '.') {
          sim[y][x] = 'X';
          que.emplace(y, x);
        }
      }
    }
  }
  REP(i, n) REP(j, m) {
    if (sim[i][j] != forest[i][j]) return false;
  }
  return true;
}

void bs_ans(int mid, vector<vector<char> > &ans) {
  REP(i, n) REP(j, m) {
    int u = i - mid, l = j - mid, r = j + mid, d = i + mid;
    if (u < 0 || l < 0 || r >= m || d >= n) continue;
    ans[i][j] = (ok(u, l, r, d) ? 'X' : '.');
  }
}

int main() {
  cin >> n >> m;
  forest.resize(n);
  REP(i, n) cin >> forest[i];
  sum.assign(n + 1, vector<long long>(m + 1, 0));
  REP(i, n) REP(j, m) sum[i + 1][j + 1] = sum[i + 1][j] + (forest[i][j] == 'X');
  FOR(j, 1, m + 1) FOR(i, 1, n) sum[i + 1][j] += sum[i][j];
  // bs(1);
  int lb = 0, ub = 501;
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    (bs(mid) ? lb : ub) = mid;
  }
  vector<vector<char> > ans(n, vector<char>(m, '.'));
  bs_ans(lb, ans);
  cout << lb << '\n';
  REP(i, n) {
    REP(j, m) cout << ans[i][j];
    cout << '\n';
  }
  return 0;
}