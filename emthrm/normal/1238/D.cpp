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
/*-------------------------------------------------*/
int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  string s; cin >> s;
  long long ans = 0;
  int a = INF, b = INF;
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == 'A') {
      if (a != INF) {
        if (s[i + 1] == 'A') {
          ans += n - i - 1 - (b != INF);
        } else {
          ans += n - a;
        }
      }
      a = i;
    } else if (s[i] == 'B') {
      if (b != INF) {
        if (s[i + 1] == 'B') {
          ans += n - i - 1 - (a != INF);
        } else {
          ans += n - b;
        }
      }
      b = i;
    }
  }
  cout << ans << '\n';
  return 0;
}