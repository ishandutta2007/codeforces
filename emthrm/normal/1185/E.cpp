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

  int t; cin >> t;
  while (t--) {
    int h, w; cin >> h >> w;
    int mx = -1;
    vector<int> cnt(26, 0);
    vector<pair<int, int> > atama(26, make_pair(-1, -1)), shippo(26, make_pair(-1, -1));
    vector<vector<char> > snake(h, vector<char>(w));
    REP(i, h) REP(j, w) {
      cin >> snake[i][j];
      if ('a' <= snake[i][j] && snake[i][j] <= 'z') {
        mx = max(mx, snake[i][j] - 'a');
        if (cnt[snake[i][j] - 'a'] == 0) atama[snake[i][j] - 'a'] = {i, j};
        shippo[snake[i][j] - 'a'] = {i, j};
        ++cnt[snake[i][j] - 'a'];
      }
    }
    if (mx == -1) {
      cout << "YES\n" << 0 << '\n';
      continue;
    }
    bool ok = true;
    for (int k = mx; k >= 0; --k) {
      if (atama[k] == make_pair(-1, -1)) {
        atama[k] = atama[k + 1];
        shippo[k] = atama[k + 1];
      } else if (atama[k].first == shippo[k].first) {
        int tmp = 0, i = atama[k].first;
        FOR(j, atama[k].second, shippo[k].second + 1) {
          if (snake[i][j] == '.' || snake[i][j] - 'a' < k) {
            ok = false;
            break;
          }
          if (snake[i][j] - 'a' == k) ++tmp;
        }
        if (tmp != cnt[k]) ok = false;
        if (!ok) break;
      } else if (atama[k].second == shippo[k].second) {
        int tmp = 0, j = atama[k].second;
        FOR(i, atama[k].first, shippo[k].first + 1) {
          if (snake[i][j] == '.' || snake[i][j] - 'a' < k) {
            ok = false;
            break;
          }
          if (snake[i][j] - 'a' == k) ++tmp;
        }
        if (tmp != cnt[k]) ok = false;
        if (!ok) break;
      } else {
        ok = false;
        break;
      }
    }
    if (!ok) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n" << mx + 1 << '\n';
    REP(i, mx + 1) cout << atama[i].first + 1 << ' ' << atama[i].second + 1 << ' ' << shippo[i].first + 1 << ' ' << shippo[i].second + 1 << '\n';
  }
  return 0;
}