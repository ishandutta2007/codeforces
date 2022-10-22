#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
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
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
// const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1},
//           dx[] = {0, -1, -1, -1, 0, 1, 1, 1};

struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(10);
  }
} iosetup;
/*-------------------------------------------------*/
int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    map<string, vector<int> > mp;
    set<string> used;
    vector<string> ans(n);
    REP(i, n) {
      cin >> ans[i];
      mp[ans[i]].emplace_back(i);
      used.emplace(ans[i]);
    }
    int digits = 0;
    for (auto &pr : mp) {
      string s = pr.first;
      if (pr.second.size() >= 2) {
        FOR(i, 1, pr.second.size()) {
          bool changed = false;
          REP(j, 4) {
            REP(k, 10) {
              string tmp = ans[pr.second[i]];
              tmp[j] = '0' + (s[j] - '0' + k) % 10;
              if (used.count(tmp) == 0) {
                ans[pr.second[i]] = tmp;
                used.emplace(tmp);
                ++digits;
                changed = true;
                break;
              }
            }
            if (changed) break;
          }
        }
      }
    }
    cout << digits << '\n';
    REP(i, n) cout << ans[i] << '\n';
  }
  return 0;
}