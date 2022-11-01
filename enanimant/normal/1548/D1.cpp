/*
 * author:  ADMathNoob
 * created: 08/01/21 10:35:14
 * problem: https://codeforces.com/contest/1548/problem/D1
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

long long Choose(int n, int k) {
  long long res = 1;
  for (int i = 1; i <= k; i++) {
    res *= (n + 1 - i);
    res /= i;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> cnt(4, 0);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x /= 2;
    y /= 2;
    cnt[2 * (x % 2) + (y % 2)] += 1;
  }
  long long ans = 0;
  for (int i = 0; i < 4; i++) {
    ans += Choose(cnt[i], 3);
    ans += Choose(cnt[i], 2) * (n - cnt[i]);
  }
  cout << ans << '\n';
  return 0;
}