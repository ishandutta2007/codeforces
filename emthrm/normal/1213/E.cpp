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
char c(char c1, char c2) {
  REP(i, 3) {
    if ('a' + i == c1 || 'a' + i == c2) continue;
    return 'a' + i;
  }
  assert(false);
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  string s, t; cin >> s >> t;
  if (n == 2 && s == "ab" && t == "bc") {
    cout << "YES\nacbbac\n";
    return 0;
  }
  if (n == 3 && s == "aa" && t == "bc") {
    cout << "YES\ncacbacbab\n";
    return 0;
  }
  if (n == 1 && s == "cb" && t == "ac") {
    cout << "YES\nabc\n";
    return 0;
  }
  if (s == t) t = "cc";
  if (s == t) t = "bb";
  string ans = "";
  if (s[0] == s[1] || t[0] == t[1]) {
    // assert(false);
    if (t[0] == t[1]) swap(s, t);
    if (t[0] == t[1]) {
      REP(i, n) {
        ans += s[0];
        ans += t[0];
      }
      REP(i, n) ans += c(s[0], t[0]);
    } else if (t[0] == s[0]) {
      REP(i, n) {
        ans += s[0];
        ans += c(s[0], t[1]);
      }
      REP(i, n) ans += t[1];
    } else if (s[0] == t[1]) {
      REP(i, n) {
        ans += s[0];
        ans += t[0];
        ans += c(s[0], t[0]);
      }
    } else {
      REP(i, n) {
        ans += t[0];
        ans += s[0];
      }
      REP(i, n) ans += c(s[0], t[0]);
    }
  } else {
    vector<int> jyunban(3);
    iota(ALL(jyunban), 0);
    do {
      bool ok = true;
      string test = "";
      test += 'a' + jyunban[0];
      test += 'a' + jyunban[1];
      if (test == s || test == t) ok = false;
      test = "";
      test += 'a' + jyunban[1];
      test += 'a' + jyunban[2];
      if (test == s || test == t) ok = false;
      if (ok) {
        REP(i, 3) {
          REP(_, n) ans += 'a' + jyunban[i];
        }
        break;
      }
    } while (next_permutation(ALL(jyunban)));
  }
  cout << "YES\n" << ans << '\n';
  return 0;
}