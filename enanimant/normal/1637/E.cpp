/*
 * author:  ADMathNoob
 * created: 02/12/22 09:35:11
 * problem: https://codeforces.com/contest/1637/problem/E
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

#ifdef _DEBUG
#include "../algorithms/debug/debug.h"
#else
#define debug(...) 42
#endif

const long long INF = 9e18;

// void TestCase() {
//   int n, m;
//   cin >> n >> m;
//   vector<int> a(n);
//   map<int, int> cnt;
//   for (int i = 0; i < n; i++) {
//     cin >> a[i];
//     cnt[a[i]] += 1;
//   }
//   set<pair<int, int>> bad;
//   for (int j = 0; j < m; j++) {
//     int x, y;
//     cin >> x >> y;
//     bad.insert(minmax(x, y));
//   }
//   auto Bad = [&](int x, int y, int z) -> bool {
//     return (long long) (cnt[x] - cnt[y]) * (z - y) >= (long long) (cnt[y] - cnt[z]) * (y - x);
//   };
//   vector<int> hull;
//   int sz = 0;
//   for (const auto& [x, _] : cnt) {
//     while (sz >= 2 && Bad(hull[sz - 2], hull.back(), x)) {
//       hull.pop_back();
//       sz -= 1;
//     }
//     hull.push_back(x);
//     sz += 1;
//   }
//   auto Plug = [&](int x, int qx) -> long long {
//     return (long long) x * 
//   };
//   for (const auto& [x, _] : cnt) {
//     int low = 0, high = sz - 1;
//     while (low < high) {
//       int mid = (low + high) / 2;
//       if ()
//     }
//   }
// }

void TestCase() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]] += 1;
  }
  set<pair<int, int>> bad;
  for (int j = 0; j < m; j++) {
    int x, y;
    cin >> x >> y;
    bad.insert(minmax(x, y));
  }
  map<int, vector<int>> by_cnt;
  for (const auto& [x, cx] : cnt) {
    by_cnt[cx].push_back(x);
  }
  for (auto& p : by_cnt) {
    reverse(p.second.begin(), p.second.end());
  }
  long long ans = 0;
  for (const auto& [c, nums] : by_cnt) {
    for (const auto& [d, other] : by_cnt) {
      for (int x : nums) {
        long long res = 0;
        for (int y : other) {
          if (y == x || bad.count(minmax(x, y))) {
            continue;
          }
          res = (long long) (c + d) * (x + y);
          break;
        }
        ans = max(ans, res);
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    TestCase();
  }
  return 0;
}