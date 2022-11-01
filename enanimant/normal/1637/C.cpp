/*
 * author:  ADMathNoob
 * created: 02/12/22 09:35:06
 * problem: https://codeforces.com/contest/1637/problem/C
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

void TestCase() {
  int n;
  cin >> n;
  vector<int> a(n);
  bool has2 = false;
  bool has3 = false;
  long long ans = 0;
  vector<int> ones;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i == 0 || i == n - 1) {
      continue;
    }
    if (a[i] == 1) {
      ones.push_back(i);
      continue;
    }
    int rem = (a[i] % 2) + 2;
    assert(a[i] >= rem);
    ans += (a[i] - rem) / 2;
    a[i] = rem;
    if (a[i] == 2) {
      has2 = true;
    }
    if (a[i] == 3) {
      has3 = true;
    }
  }
  if (has2) {
    for (int i = 1; i < n - 1; i++) {
      int rem = (a[i] % 2 == 0 ? 2 : 1);
      ans += (a[i] - rem) / 2;
      a[i] = rem;
    }
    ans += n - 2;
  } else {
    if (has3 && n >= 4) {
      for (int i = 1; i < n - 1; i++) {
        if (a[i] == 3) {
          a[i] = 1;
          ans += 1;
          for (int j = 1; j < n - 1; j++) {
            if (j == i) continue;
            a[j] += 1;
            break;
          }
          break;
        }
      }
      for (int i = 1; i < n - 1; i++) {
        int rem = (a[i] % 2 == 0 ? 2 : 1);
        ans += (a[i] - rem) / 2;
        a[i] = rem;
      }
      ans += n - 2;
    } else {
      // single odd or all 1s
      ans = -1;
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