/*
 * author:  ADMathNoob
 * created: 07/16/22 07:35:12
 * problem: https://codeforces.com/contest/1707/problem/B
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

const int A = 500000;

int TestCase() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  reverse(a.begin(), a.end());
  int k0 = 0;
  while (!a.empty() && a.back() == 0) {
    a.pop_back();
    k0 += 1;
  }
  
  // maintain a, k0
  auto Do = [&] {
    assert(a.size() + k0 > 1);
    if (k0 > 0) {
      k0 -= 1;
      a.push_back(0);
    }
    int m = a.size();
    for (int i = 0; i < m - 1; i++) {
      a[i] -= a[i + 1];
    }
    a.resize(m - 1);
    sort(a.rbegin(), a.rend());
    while (!a.empty() && a.back() == 0) {
      a.pop_back();
      k0 += 1;
    }
  };
  
  while (true) {
    int m = a.size();
    if (m == 0) {
      return 0;
    }
    if (m == 1) {
      return a[0];
    }
    Do();
  }
  assert(0);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cout << TestCase() << '\n';
  }
  return 0;
}