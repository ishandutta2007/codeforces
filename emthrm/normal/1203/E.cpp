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

  int n; cin >> n;
  vector<int> a(n), comp;
  REP(i, n) {
    cin >> a[i];
    if (a[i] - 1 > 0) comp.emplace_back(a[i] - 1);
    comp.emplace_back(a[i]);
    comp.emplace_back(a[i] + 1);
  }
  sort(ALL(comp));
  comp.erase(unique(ALL(comp)), comp.end());
  vector<int> boxer(comp.size(), 0);
  REP(i, n) {
    a[i] = lower_bound(ALL(comp), a[i]) - comp.begin();
    ++boxer[a[i]];
  }
  vector<int> answer(comp.size(), 0);
  if (boxer[0] >= 1) {
    ++answer[0];
    if (boxer[0] >= 2) ++answer[1];
  }
  FOR(i, 1, comp.size()) if (boxer[i] >= 1) {
    if (answer[i - 1] == 0) {
      ++answer[i - 1];
      --boxer[i];
    }
    if (boxer[i] >= 1) {
      if (answer[i] == 0) {
        ++answer[i];
        --boxer[i];
      }
    }
    if (boxer[i] >= 1) {
      ++answer[i + 1];
    }
  }
  int ans = 0;
  REP(i, comp.size()) {
    if (answer[i]) ++ans;
  }
  cout << ans << '\n';
  return 0;
}