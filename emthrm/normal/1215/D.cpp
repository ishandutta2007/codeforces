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
bool solveA(int sum_a, int un_a, int sum_b, int un_b, int teban) {
  if (teban > un_a) {
    sum_a += un_a * 9;
    teban -= un_a;
    un_a = 0;
    un_b -= teban;
  } else {
    sum_a += teban;
    un_a -= teban;
  }
  if (un_a == 0) {
    if (0 <= sum_a - sum_b && sum_a - sum_b <= un_b * 9) return false;
    return true;
  } else {
    sum_a -= sum_b;
    sum_b = 0;
    int mn_a = sum_a, mx_a = sum_a + un_a * 9, mn_b = 0, mx_b = un_b * 9;
    if (mn_a <= mx_b && mn_b <= mx_a) return false;
    return true;
  }
}

bool solveB(int sum_a, int un_a, int sum_b, int un_b, int teban) {
  if (teban > un_a) {
    teban -= un_a;
    un_a = 0;
    sum_b += teban * 9;
    un_b -= teban;
  } else {
    un_a -= teban;
  }
  if (un_a == 0) {
    if (0 <= sum_a - sum_b && sum_a - sum_b <= un_b * 9) return false;
    return true;
  } else {
    sum_a -= sum_b;
    sum_b = 0;
    int mn_a = sum_a, mx_a = sum_a + un_a * 9, mn_b = 0, mx_b = un_b * 9;
    if (mn_a <= mx_b && mn_b <= mx_a) return false;
    return true;
  }
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  string s; cin >> s;
  int sum_a = 0, un_a = 0, sum_b = 0, un_b = 0;
  REP(i, n / 2) {
    if (s[i] == '?') {
      ++un_a;
    } else {
      sum_a += s[i] - '0';
    }
  }
  FOR(i, n / 2, n) {
    if (s[i] == '?') {
      ++un_b;
    } else {
      sum_b += s[i] - '0';
    }
  }
  int teban = (un_a + un_b) / 2;
  cout << (solveA(sum_a, un_a, sum_b, un_b, teban) || solveA(sum_b, un_b, sum_a, un_a, teban) || solveB(sum_a, un_a, sum_b, un_b, teban) || solveB(sum_b, un_b, sum_a, un_a, teban) ? "Monocarp\n" : "Bicarp\n");
  return 0;
}