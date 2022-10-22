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
void solve(vector<int> &a, vector<int> &b) {
  vector<int> ans;
  while (!a.empty() || !b.empty()) {
    if (!a.empty()) {
      ans.emplace_back(a.back());
      a.pop_back();
    }
    if (!b.empty()) {
      ans.emplace_back(b.back());
      b.pop_back();
    }
  }
  FOR(i, 1, ans.size()) {
    if (abs(ans[i] - ans[i - 1]) != 1) return;
  }
  cout << "YES\n";
  REP(i, ans.size()) cout << ans[i] << " \n"[i + 1 == ans.size()];
  exit(0);
}

int main() {
  vector<int> num(4); REP(i, 4) cin >> num[i];
  vector<int> even, odd;
  for (; num[0]; --num[0]) even.emplace_back(0);
  for (; num[1]; --num[1]) odd.emplace_back(1);
  for (; num[2]; --num[2]) even.emplace_back(2);
  for (; num[3]; --num[3]) odd.emplace_back(3);
  reverse(ALL(even));
  reverse(ALL(odd));
  vector<int> x(even), y(odd);
  solve(even, odd);
  solve(y, x);
  cout << "NO\n";
  return 0;
}