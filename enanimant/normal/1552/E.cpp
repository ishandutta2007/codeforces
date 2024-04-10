/*
 * author:  ADMathNoob
 * created: 07/25/21 10:34:24
 * problem: https://codeforces.com/contest/1552/problem/E
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n * k);
  for (int i = 0; i < n * k; i++) {
    cin >> a[i];
    --a[i];
  }
  int at = 0;
  vector<int> L(n, -1), R(n);
  const int M = (n + k - 2) / (k - 1);
  for (int i = 0; i < n; i += M) {
    vector<int> cnt(n, 0);
    vector<int> last(n, -1);
    int took = 0;
    for (int j = at; j < n * k; j++) {
      if (L[a[j]] != -1) {
        continue;
      }
      ++cnt[a[j]];
      if (cnt[a[j]] == 2) {
        L[a[j]] = last[a[j]];
        R[a[j]] = j;
        ++took;
        if (took == M) {
          at = j + 1;
          break;
        }
      }
      last[a[j]] = j;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << L[i] + 1 << ' ' << R[i] + 1 << '\n';
  }
  return 0;
}