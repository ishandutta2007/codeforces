/*
 * author:  ADMathNoob
 * created: 10/17/21 07:05:22
 * problem: https://codeforces.com/contest/1586/problem/D
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  auto Ask = [&](const vector<int>& a) {
    cout << '?';
    for (int i = 0; i < n; i++) {
      cout << ' ' << a[i];
    }
    cout << endl;
    int k;
    cin >> k;
    --k;
    return k;
  };
  vector<int> p(n);
  p[n - 1] = 1;
  for (int i = n; i >= 2; i--) {
    vector<int> a(n, i);
    a[n - 1] = 1;
    int r = Ask(a);
    if (r != -1) {
      p[n - 1] = i;
      break;
    }
  }
  for (int x = 1; x <= n; x++) {
    if (x == p[n - 1]) {
      continue;
    }
    vector<int> a(n, p[n - 1]);
    a[n - 1] = x;
    int r = Ask(a);
    assert(r != -1);
    p[r] = x;
  }
  cout << '!';
  for (int i = 0; i < n; i++) {
    cout << ' ' << p[i];
  }
  cout << endl;
  return 0;
}