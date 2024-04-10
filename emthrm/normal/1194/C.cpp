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

  int q; cin >> q;
  while (q--) {
    string s, t, p; cin >> s >> t >> p;
    vector<int> cnt(26, 0);
    for (char c : p) ++cnt[c - 'a'];
    int x = 0, y = 0;
    bool ok = true;
    while (y < t.length()) {
      if (x == s.length()) {
        if (cnt[t[y] - 'a'] > 0) {
          --cnt[t[y] - 'a'];
        } else {
          ok = false;
          break;
        }
      } else if (s[x] == t[y]) {
        ++x;
      } else {
        if (cnt[t[y] - 'a'] > 0) {
          --cnt[t[y] - 'a'];
        } else {
          ok = false;
          break;
        }
      }
      ++y;
    }
    cout << (x == s.length() && ok ? "YES\n" : "NO\n");
  }
  return 0;
}