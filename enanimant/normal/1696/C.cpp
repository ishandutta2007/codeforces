/*
 * author:  ADMathNoob
 * created: 06/25/22 07:35:34
 * problem: https://codeforces.com/contest/1696/problem/C
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

bool TestCase() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, long long>> segs;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int cnt = 1;
    while (x % m == 0) {
      x /= m;
      cnt *= m;
    }
    if (!segs.empty() && segs.back().first == x) {
      segs.back().second += cnt;
    } else {
      segs.emplace_back(x, cnt);
    }
    // debug(i, segs);
  }
  // debug(segs);
  reverse(segs.begin(), segs.end());
  int k;
  cin >> k;
  vector<int> b(k);
  for (int i = 0; i < k; i++) {
    cin >> b[i];
  }
  for (int y : b) {
    if (segs.empty()) {
      return false;
    }
    auto& [x, cnt] = segs.back();
    int need = 1;
    while (y % m == 0) {
      need *= m;
      y /= m;
    }
    if (y != x) {
      return false;
    }
    if (need > cnt) {
      return false;
    }
    cnt -= need;
    if (cnt == 0) {
      segs.pop_back();
    }
  }
  return segs.empty();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    bool ok = TestCase();
    cout << (ok ? "Yes" : "No") << '\n';
  }
  return 0;
}