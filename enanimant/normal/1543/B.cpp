/*
 * author:  ADMathNoob
 * created: 07/07/21 10:37:03
 * problem: https://codeforces.com/contest/1543/problem/B
 */

/*
g++ 1543B.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1543B.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



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
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    long long x = sum / n;
    int more = sum - x * n;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      long long b = (i < n - more ? x : x + 1);
      ans += (2 * i - n + 1) * b;
    }
    cout << ans << '\n';
  }
  return 0;
}