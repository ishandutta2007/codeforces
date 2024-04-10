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

  int n, m; cin >> n >> m;
  vector<int> fri(512, 0);
  REP(i, n) {
    int f; cin >> f;
    int bit = 0;
    REP(j, f) {
      int b; cin >> b; --b;
      bit |= (1 << b);
    }
    REP(j, 512) {
      if (__builtin_popcount(j & bit) == f) ++fri[j];
    }
  }
  vector<vector<pair<long long, int> > > pizza(512);
  REP(i, m) {
    long long c; int r; cin >> c >> r;
    vector<int> a(r);
    REP(j, r) {
      cin >> a[j]; --a[j];
    }
    REP(j, 1 << r) {
      int bubun = 0;
      REP(k, r) if (j >> k & 1) {
        bubun |= (1 << a[k]);
      }
      pizza[bubun].emplace_back(c, i + 1);
    }
  }
  REP(i, 512) sort(ALL(pizza[i]));
  int ans1, ans2, person = 0;
  long long price = LINF;
  REP(i, 512) {
    if (fri[i] < person) continue;
    int sub = i;
    do {
      int ni = 0;
      REP(j, 9) {
        if ((!(sub >> j & 1)) && (i >> j & 1)) ni |= (1 << j);
      }
      if (pizza[sub].empty() || pizza[ni].empty()) {
        sub = (sub - 1) & i;
        continue;
      }
      if (pizza[sub].front().second == pizza[ni].front().second) {
        if (sub == ni) {
          long long p = pizza[0][0].first + pizza[0][1].first;
          if (person < fri[i]) {
            ans1 = pizza[0][0].second;
            ans2 = pizza[0][1].second;
            person = fri[i];
            price = p;
          } else if (p < price) {
            ans1 = pizza[0][0].second;
            ans2 = pizza[0][1].second;
            price = p;
          }
        } else {
          long long p = pizza[sub].front().first;
          if (pizza[0][0].second == pizza[sub].front().second) {
            p += pizza[0][1].first;
            if (person < fri[i]) {
              ans1 = pizza[sub].front().second;
              ans2 = pizza[0][1].second;
              person = fri[i];
              price = p;
            } else if (p < price) {
              ans1 = pizza[sub].front().second;
              ans2 = pizza[ni].front().second;
              price = p;
            }
          } else {
            p += pizza[0].front().first;
            if (person < fri[i]) {
              ans1 = pizza[sub].front().second;
              ans2 = pizza[0].front().second;
              person = fri[i];
              price = p;
            } else if (p < price) {
              ans1 = pizza[sub].front().second;
              ans2 = pizza[0].front().second;
              price = p;
            }
          }
        }
      } else {
        long long p = pizza[sub].front().first + pizza[ni].front().first;
        if (person < fri[i]) {
          ans1 = pizza[sub].front().second;
          ans2 = pizza[ni].front().second;
          person = fri[i];
          price = p;
        } else if (p < price) {
          ans1 = pizza[sub].front().second;
          ans2 = pizza[ni].front().second;
          price = p;
        }
      }
      sub = (sub - 1) & i;
    } while (sub != i);
  }
  cout << min(ans1, ans2) << ' ' << max(ans1, ans2) << '\n';
  return 0;
}