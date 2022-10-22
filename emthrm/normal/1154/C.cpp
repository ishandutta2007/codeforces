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

  // a b c a c b a | a b c a c b a
  vector<int> food(3); cin >> food[0] >> food[1] >> food[2];
  int a = food[0] / 3, b = food[1] / 2, c = food[2] / 2;
  long long ans = min({a, b, c});
  food[0] -= ans * 3;
  food[1] -= ans * 2;
  food[2] -= ans * 2;
  ans *= 7;
  vector<int> day{0, 1, 2, 0, 2, 1, 0, 0, 1, 2, 0, 2, 1, 0};
  int mx = 0;
  REP(i, 7) {
    vector<int> res(food);
    int cnt = 0;
    FOR(j, i, i + 7) {
      if (res[day[j]] == 0) {
        break;
      } else {
        --res[day[j]];
        ++cnt;
      }
    }
    mx = max(mx, cnt);
  }
  cout << ans + mx << '\n';
  return 0;
}