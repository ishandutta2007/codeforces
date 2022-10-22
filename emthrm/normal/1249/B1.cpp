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
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};

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
  int q; cin >> q;
  while (q--) {
    int n; cin >> n;
    vector<int> p(n);
    REP(i, n) {
      cin >> p[i]; --p[i];
    }
    vector<int> ans(n, -1);
    vector<bool> visited(n, false);
    REP(i, n) if (!visited[i]) {
      int cnt = 1;
      vector<int> group{i};
      visited[i] = true;
      queue<int> que;
      que.emplace(i);
      while (!que.empty()) {
        int ver = que.front(); que.pop();
        if (visited[p[ver]]) break;
        visited[p[ver]] = true;
        ++cnt;
        que.emplace(p[ver]);
        group.emplace_back(p[ver]);
      }
      for (int e : group) ans[e] = cnt;
    }
    REP(i, n) cout << ans[i] << (i + 1 == n ? '\n' : ' ');
  }
  return 0;
}