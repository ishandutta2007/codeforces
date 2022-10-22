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

  string s; cin >> s;
  int n = s.length();
  string ans1 = "", ans2 = "";
  int l = 0, r = n - 1;
  while (l <= r) {
    if (l == r) {
      ans1 += s[l];
      break;
    }
    if (s[l] == s[r]) {
      ans1 += s[l];
      ans2 += s[r];
      ++l;
      --r;
      continue;
    }
    if (l + 1 < r && s[l + 1] == s[r]) {
      ans1 += s[l + 1];
      ans2 += s[r];
      l += 2;
      --r;
      continue;
    }
    if (l < r - 1 && s[l] == s[r - 1]) {
      ans1 += s[l];
      ans2 += s[r - 1];
      ++l;
      r -= 2;
      continue;
    }
    if (l + 1 < r - 1 && s[l + 1] && s[r - 1]) {
      ans1 += s[l + 1];
      ans2 += s[r - 1];
      l += 2;
      r -= 2;
      continue;
    }
    ans1 += s[l];
    break;
  }
  reverse(ALL(ans2));
  cout << ans1 + ans2 << '\n';
  return 0;
}