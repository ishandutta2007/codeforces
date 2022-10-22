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
#include <iomanip>
#include <iostream>
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
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
// const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1},
//           dx[] = {0, -1, -1, -1, 0, 1, 1, 1};

struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(10);
  }
} iosetup;
/*-------------------------------------------------*/
int main() {
  string s, t; cin >> s >> t;
  int n = s.length(), m = t.length();
  auto idx = [&](int i, int j, int k) { return i * (m + 1) * (n + m + 1) + j * (n + m + 1) + k; };
  int z = idx(n, m, n + m) + 1;
  vector<tuple<int, int, int> > rev(z);
  REP(i, n + 1) REP(j, m + 1) REP(k, n + m + 1) rev[idx(i, j, k)] = {i, j, k};
  vector<int> dist(z, INF), prev(z, -1);
  dist[idx(0, 0, 0)] = 0;
  queue<int> que;
  que.emplace(idx(0, 0, 0));
  while (!que.empty()) {
    int now = que.front(); que.pop();
    int i, j, k; tie(i, j, k) = rev[now];
    // (
    int nx_i = (i < n && s[i] == '(' ? i + 1 : i);
    int nx_j = (j < m && t[j] == '(' ? j + 1 : j);
    int nx_k = k + 1;
    if (nx_k <= n + m) {
      int nx = idx(nx_i, nx_j, nx_k);
      if (dist[nx] > dist[now] + 1) {
        dist[nx] = dist[now] + 1;
        prev[nx] = now;
        que.emplace(nx);
      }
    }
    // )
    nx_i = (i < n && s[i] == ')' ? i + 1 : i);
    nx_j = (j < m && t[j] == ')' ? j + 1 : j);
    nx_k = k - 1;
    if (nx_k >= 0) {
      int nx = idx(nx_i, nx_j, nx_k);
      if (dist[nx] > dist[now] + 1) {
        dist[nx] = dist[now] + 1;
        prev[nx] = now;
        que.emplace(nx);
      }
    }
  }
  string ans = "";
  int pos = idx(n, m, 0);
  while (true) {
    int nx = prev[pos];
    if (nx == -1) break;
    int i, j, k; tie(i, j, k) = rev[nx];
    if (k + 1 == get<2>(rev[pos])) {
      ans += '(';
    } else {
      ans += ')';
    }
    pos = nx;
  }
  reverse(ALL(ans));
  cout << ans << '\n';
  return 0;
}