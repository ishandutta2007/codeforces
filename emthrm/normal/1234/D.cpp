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

  string s; cin >> s;
  vector<set<int> > idx(26);
  REP(i, s.length()) idx[s[i] - 'a'].emplace(i);
  int q; cin >> q;
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int pos; char c; cin >> pos >> c; --pos;
      idx[s[pos] - 'a'].erase(pos);
      s[pos] = c;
      idx[s[pos] - 'a'].emplace(pos);
    } else {
      int l, r; cin >> l >> r; --l; --r;
      int ans = 0;
      REP(i, 26) {
        auto it = idx[i].lower_bound(l);
        if (it != idx[i].end() && *it <= r) ++ans;
      }
      cout << ans << '\n';
    }
  }
  return 0;
}