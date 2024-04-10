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
  if (n & 1) {
    cout << ":(\n";
    return 0;
  }
  string s; cin >> s;
  if (s.front() == ')') {
    cout << ":(\n";
    return 0;
  }
  reverse(ALL(s));
  int cnt = 0;
  REP(i, n) {
    if (s[i] == '?' || s[i] == ')') ++cnt;
    else --cnt;
    if (i < n - 1 && cnt == 0) {
      cout << ":(\n";
      return 0;
    }
  }
  reverse(ALL(s));
  int left = 0, right = 0;
  REP(i, n) {
    if (s[i] == '(') ++left;
    else if (s[i] == ')') ++right;
  }
  if (left > n / 2 || right > n / 2) {
    cout << ":(\n";
    return 0;
  }
  REP(i, n) {
    if (s[i] == '?') {
      if (left < n / 2) {
        s[i] = '(';
        ++left;
      } else {
        s[i] = ')';
      }
    }
  }
  int tst = 0;
  REP(i, n) {
    if (s[i] == '(') ++tst;
    else --tst;
    if (i < n - 1 && tst == 0) {
      cout << ":(\n";
      return 0;
    }
  }
  cout << s << '\n';
  return 0;
}