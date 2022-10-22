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
int subcheck(char c, char target) {
  if (c == target) return 0;
  int cnt1, cnt2;
  char tmp = c;
  for (cnt1 = 1; cnt1 < 26; ++cnt1) {
    if (c == 'Z') c = 'A';
    else ++c;
    if (c == target) break;
  }
  c = tmp;
  for (cnt2 = 1; cnt2 < 26; ++cnt2) {
    if (c == 'A') c = 'Z';
    else --c;
    if (c == target) break;
  }
  return min(cnt1, cnt2);
}

int check(string s) {
  return subcheck(s[0], 'A') + subcheck(s[1], 'C') + subcheck(s[2], 'T') + subcheck(s[3], 'G');
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  string s; cin >> s;
  int ans = INF;
  REP(i, n - 3) {
    ans = min(ans, check(s.substr(i, 4)));
  }
  cout << ans << '\n';
  return 0;
}