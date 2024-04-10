#include <algorithm>
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
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f, MOD = 1000000007;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*-----------------------------------------*/
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, m; cin >> n >> m;
  vector<vector<pair<int, int> > > candy(n);
  REP(i, m) {
    int a, b; cin >> a >> b; --a; --b;
    if (a < b) candy[a].emplace_back(b - a, b);
    else candy[a].emplace_back(n - a + b, b);
  }
  vector<int> idx(n);
  REP(i, n) {
    idx[i] = candy[i].size();
    sort(ALL(candy[i]));
  }
  REP(s, n) {
    vector<int> rem = idx;
    int cnt = 0, t = 0, now = s, mx = -1;
    while (true) {
      if (mx == now) mx = -1;
      if (rem[now] > 0) {
        int tmp = candy[now][rem[now]-1].second;
        if (mx == -1) mx = tmp;
        else if (tmp > now) {
          if (mx > now && tmp > mx) mx = tmp;
        } else {
          if (mx > now) mx = tmp;
          else if (tmp > mx) mx = tmp;
        }
        --rem[now];
        ++cnt;
      }
      // cout << now << ' ' << t << ' ' << mx << '\n';
      if (cnt == m) {
        if (mx > now) t += mx - now;
        else t += n - now + mx;
        break;
      }
      if (now == n - 1) now = 0;
      else ++now;
      ++t;
    }
    cout << t << (s == n - 1 ? '\n' : ' ');
  }
  return 0;
}