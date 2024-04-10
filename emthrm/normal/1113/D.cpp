#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*----------------------------------------*/
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  string s; cin >> s;
  int ans = 2, sz = s.length();
  if (sz & 1) {
    if (sz == 1) {
      cout << "Impossible\n";
      return 0;
    }
    char c = s.front();
    bool ng = true;
    FOR(i, 1, sz) if (i != sz / 2) {
      if (s[i] != c) ng = false;
    }
    if (ng) {
      cout << "Impossible\n";
      return 0;
    }
  } else {
    char c = s.front();
    bool ng = true;
    FOR(i, 1, sz) {
      if (s[i] != c) ng = false;
    }
    if (ng) {
      cout << "Impossible\n";
      return 0;
    }
  }
  FOR(i, 1, sz) {
    string s1 = s.substr(0, i), s2 = s.substr(i);
    string candidate = s2 + s1, rev = candidate;
    reverse(ALL(rev));
    if (candidate == rev && candidate != s) ans = 1;
  }
  cout << ans << '\n';
  return 0;
}