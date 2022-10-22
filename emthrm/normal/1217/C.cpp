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
int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    if (count(ALL(s), '1') == 0) {
      cout << 0 << '\n';
      continue;
    }
    reverse(ALL(s));
    int n = s.length();
    vector<int> nx(n);
    int tmp = n;
    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == '1') tmp = i;
      nx[i] = tmp;
    }
    long long ans = 0;
    REP(i, n) {
      long long now = 0;
      int j = i - 1;
      while (j + 1 < n) {
        if (nx[j + 1] == n) break;
        if (nx[j + 1] - i > 20) break;
        now |= (1LL << (nx[j + 1] - i));
        if (now > n) break;
        int len = nx[j + 1] - i + 1;
        if (now >= len) {
          if (nx[j + 1] == n - 1) {
            if (now == len) ++ans;
          } else {
            int pos = nx[nx[j + 1] + 1], sonolen = pos - i + 1;
            if (now < sonolen) ++ans;
          }
        }
        j = nx[j + 1];
        // if (nx[j + 1] == n) {
        //   int len = n - i;
        //   if (j - i + 1 < now && now <= len) ++ans;
        //   break;
        // } else {
        //   if (nx[j + 1] - i > 20) break;
        //   int len = nx[j + 1] - i + 1;
        //   if (now == 0) {
        //     if ((now | (1LL << (nx[j + 1] - i))) == len) ++ans;
        //   } else if (j - i + 1 < now) {
        //     if ((now | (1LL << (nx[j + 1] - i))) >= len) ++ans;
        //   }
        //   now |= (1LL << (nx[j + 1] - i));
        //   if (now > n) break;
        //   j = nx[j + 1];
        // }
        // cout << i << ':' << j << ' ' << now << ' ' << ans << '\n';
      }
      // cout << i << ' ' << ans << '\n';
    }
    cout << ans << '\n';
  }
  return 0;
}