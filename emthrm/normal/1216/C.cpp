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
#include <numeric>
#include <queue>
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
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  vector<int> x(6), y(6), X, Y;
  REP(i, 6) {
    cin >> x[i] >> y[i];
    X.emplace_back(x[i - 1]);
    X.emplace_back(x[i]);
    X.emplace_back(x[i + 1]);
    Y.emplace_back(y[i - 1]);
    Y.emplace_back(y[i]);
    Y.emplace_back(y[i + 1]);
  }
  sort(ALL(X));
  X.erase(unique(ALL(X)), X.end());
  sort(ALL(Y));
  Y.erase(unique(ALL(Y)), Y.end());
  vector<vector<int> > table(Y.size(), vector<int>(X.size(), 0));
  for (int i = 2; i < 6; i += 2) {
    x[i] = lower_bound(ALL(X), x[i]) - X.begin();
    x[i + 1] = lower_bound(ALL(X), x[i + 1]) - X.begin();
    y[i] = lower_bound(ALL(Y), y[i]) - Y.begin();
    y[i + 1] = lower_bound(ALL(Y), y[i + 1]) - Y.begin();
    FOR(r, y[i], y[i + 1]) FOR(c, x[i], x[i + 1]) ++table[r][c];
  }
  x[0] = lower_bound(ALL(X), x[0]) - X.begin();
  x[1] = lower_bound(ALL(X), x[1]) - X.begin();
  y[0] = lower_bound(ALL(Y), y[0]) - Y.begin();
  y[1] = lower_bound(ALL(Y), y[1]) - Y.begin();
  FOR(r, y[0], y[1]) FOR(c, x[0], x[1]) {
    if (table[r][c] == 0) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}