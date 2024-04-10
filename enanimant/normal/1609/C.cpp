/*
 * author:  ADMathNoob
 * created: 11/28/21 09:35:17
 * problem: https://codeforces.com/contest/1609/problem/C
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  const int A = 1000005;
  vector<bool> p(A, true);
  p[1] = false;
  for (int i = 2; i * i < A; i++) {
    if (p[i]) {
      for (int j = i * i; j < A; j += i) {
        p[j] = false;
      }
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> groups(e);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      groups[i % e].push_back(x);
    }
    long long ans = 0;
    for (const auto& a : groups) {
      int m = (int) a.size();
      int beg = 0;
      while (beg < m) {
        int end = beg;
        while (end < m && a[end] == 1) {
          end += 1;
        }
        if (end == m || !p[a[end]]) {
          beg = end + 1;
          continue;
        }
        int pos = end - beg;
        end += 1;
        while (end < m && a[end] == 1) {
          end += 1;
        }
        int length = end - beg;
        ans += (long long) (pos + 1) * (length - pos) - 1;
        beg += pos + 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}