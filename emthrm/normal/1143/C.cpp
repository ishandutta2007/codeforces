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

  int n; cin >> n;
  vector<vector<int> > edge(n + 1);
  vector<int> c(n + 1);
  FOR(i, 1, n + 1) {
    int p; cin >> p >> c[i];
    if (p != -1) edge[p].emplace_back(i);
  }
  vector<int> ans;
  FOR(i, 1, n + 1) if (c[i] == 1) {
    bool del = true;
    for (int e : edge[i]) {
      if (c[e] == 0) del = false;
    }
    if (del) ans.emplace_back(i);
  }
  if (ans.empty()) {
    cout << -1 << '\n';
  } else {
    int sz = ans.size();
    REP(i, sz) cout << ans[i] << (i == sz - 1 ? '\n': ' ');
  }
  return 0;
}