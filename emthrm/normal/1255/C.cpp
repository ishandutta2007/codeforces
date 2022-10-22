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
  int n; cin >> n;
  vector<vector<int> > q(n - 2, vector<int>(3));
  map<pair<int, int>, vector<int> > mp;
  REP(i, n - 2) {
    REP(j, 3) {
      cin >> q[i][j]; --q[i][j];
    }
    sort(ALL(q[i]));
    REP(j, 3) FOR(k, j + 1, 3) mp[{q[i][j], q[i][k]}].emplace_back(i);
  }
  vector<vector<int> > graph(n);
  for (auto &pr : mp) {
    if (pr.second.size() == 2) {
      graph[pr.second[0]].emplace_back(pr.second[1]);
      graph[pr.second[1]].emplace_back(pr.second[0]);
    }
  }
  int src = 0;
  for (; src < n; ++src) {
    if (graph[src].size() == 1) break;
  }
  vector<int> p{src};
  vector<bool> visited(n, false);
  visited[src] = true;
  while (p.size() < n - 2) {
    for (int e : graph[src]) {
      if (!visited[e]) {
        src = e;
        visited[src] = true;
        p.emplace_back(src);
        break;
      }
    }
  }
  vector<int> ans(n, -1);
  REP(i, n - 3) {
    set<int> st1, st2;
    REP(j, 3) st1.emplace(q[p[i]][j]);
    REP(j, 3) {
      if (st1.count(q[p[i + 1]][j]) == 1) {
        st1.erase(q[p[i + 1]][j]);
        st2.emplace(q[p[i + 1]][j]);
      }
    }
    ans[i] = *st1.begin();
    REP(j, 3) {
      if (st2.count(q[p[i + 1]][j]) == 0) {
        ans[i + 3] = q[p[i + 1]][j];
        break;
      }
    }
  }
  if (n == 5) {
    REP(i, n) {
      if (count(ALL(ans), i) == 0) {
        REP(j, n) {
          if (ans[j] == -1) {
            ans[j] = i;
            break;
          }
        }
        break;
      }
    }
  }
  REP(i, n) cout << ans[i] + 1 << (i + 1 == n ? '\n' : ' ');
  return 0;
}