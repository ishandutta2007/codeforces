/*
 * author:  ADMathNoob
 * created: 11/28/21 09:35:13
 * problem: https://codeforces.com/contest/1609/problem/A
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    int e = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      while (a[i] % 2 == 0) {
        a[i] /= 2;
        e += 1;
      }
    }
    int i = max_element(a.begin(), a.end()) - a.begin();
    a[i] <<= e;
    cout << accumulate(a.begin(), a.end(), 0LL) << '\n';
  }
  return 0;
}