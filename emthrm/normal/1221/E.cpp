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
bool win(int a, int b, string s, bool turn) {
  int n = s.length();
  if (turn) {
    REP(i, n) {
      if (i + a - 1 >= n) break;
      bool ok = true;
      FOR(j, i, i + a) {
        if (s[j] == 'X') {
          ok = false;
          break;
        }
      }
      if (ok) {
        FOR(j, i, i + a) s[j] = 'X';
        if (!win(a, b, s, !turn)) return true;
        FOR(j, i, i + a) s[j] = '.';
      }
    }
    return false;
  } else {
    REP(i, n) {
      if (i + b - 1 >= n) break;
      bool ok = true;
      FOR(j, i, i + b) {
        if (s[j] == 'X') {
          ok = false;
          break;
        }
      }
      if (ok) {
        FOR(j, i, i + b) s[j] = 'X';
        if (!win(a, b, s, !turn)) return true;
        FOR(j, i, i + b) s[j] = '.';
      }
    }
    return false;
  }
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  // int n = 9;
  // string s = "";
  // REP(_, n) s += '.';
  // FOR(i, 2, n + 1) FOR(j, 1, i) {
  //   cout << i << ' ' << j << ':' << (win(i, j, s, true) ? "OK\n" : "NG\n");
  // }

  int q; cin >> q;
  while (q--) {
    int a, b; cin >> a >> b;
    string s; cin >> s;
    bool b_win = false;
    int pos = 0, mx = -1, cnt = 0;
    while (pos < s.length()) {
      int idx1 = s.find('.', pos);
      if (idx1 == s.npos) break;
      int idx2 = s.find('X', idx1);
      if (idx2 == s.npos) idx2 = s.length();
      if (idx2 - idx1 >= b * 2) {
        if (mx != -1) {
          b_win = true;
          break;
        }
        mx = idx2 - idx1;
      } else if (idx2 - idx1 >= a) {
        ++cnt;
      } else if (idx2 - idx1 >= b) {
        b_win = true;
      }
      pos = idx2;
    }
    if (b_win) {
      cout << "NO\n";
      continue;
    }
    if (mx == -1) {
      cout << (cnt % 2 == 0 ? "NO\n" : "YES\n");
      continue;
    }
    b_win = true;
    REP(i, mx) {
      if (i + a > mx) break;
      int right = mx - (i + a);
      if (b <= i && i < a) continue;
      if (i >= b * 2) continue;
      if (b <= right && right < a) continue;
      if (right >= b * 2) continue;
      int now_cnt = cnt + (i >= a) + (right >= a);
      if (now_cnt % 2 == 0) {
        b_win = false;
        break;
      }
    }
    cout << (b_win ? "NO\n" : "YES\n");
  }
  return 0;
}